#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 500001;

int A[MAX], B[MAX], V[MAX], cnt[MAX], D[MAX], tree[MAX * 4];

void update(int n, int s, int e, int x, int v) {
    if (x < s || e < x)
        return;
    else if (s == e)
        tree[n] += v;
    else {
        int m = s + e >> 1;
        update(n << 1, s, m, x, v), update(n << 1 | 1, m + 1, e, x, v);
        tree[n] = tree[n << 1] + tree[n << 1 | 1];
    }
}

int query(int n, int s, int e, int l, int r) {
    if (r < s || e < l)
        return 0;
    else if (l <= s && e <= r)
        return tree[n];
    else {
        int m = s + e >> 1;
        return query(n << 1, s, m, l, r) + query(n << 1 | 1, m + 1, e, l, r);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, ans = 0, X = 0, Y, M, K = 0;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    for (int i = 1; i <= N; i++) {
        cin >> B[i], D[B[i]] = i;
        V[i] = max(V[i - 1], B[i]), update(1, 0, N, V[i] - i + 1, 1);
    }
    update(1, 0, N, 0, 1), V[0] = -1;

    K = 0, Y = N, M = N + 1;

    ans = query(1, 0, N, 0, 0);
    for (int i = 1; i <= N; i++) {
        X = max(A[i], X), M = min(M, D[A[i]] - 1);
        while (X - i + 1 > K)
            update(1, 0, N, V[K] - K + 1, -1), K++;
        while (K > X - i + 1)
            K--, update(1, 0, N, V[K] - K + 1, 1);

        while (Y > M)
            update(1, 0, N, V[Y] - Y + 1, -1), Y--;
        if (K <= Y)
            ans += query(1, 0, N, 0, i);
    }

    cout << ans << '\n';

    return 0;
}