#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 300000;

int P[MAX], tree[MAX * 4], A[MAX];

void init(int n, int s, int e) {
    if (s == e)
        tree[n] = P[s];
    else {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
        tree[n] = max(tree[n << 1], tree[n << 1 | 1]);
    }
}

void update(int n, int s, int e, int x) {
    if (x < s || e < x)
        return;
    else if (s == e)
        tree[n] = 0;
    else {
        int m = s + e >> 1;
        update(n << 1, s, m, x), update(n << 1 | 1, m + 1, e, x);
        tree[n] = max(tree[n << 1], tree[n << 1 | 1]);
    }
}

int query(int n, int s, int e, int x) {
    if (tree[n] < x)
        return -1;
    else if (s == e)
        return s;
    else {
        int m = s + e >> 1;
        if (tree[n << 1] >= x)
            return query(n << 1, s, m, x);
        else
            return query(n << 1 | 1, m + 1, e, x);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, M, X, K, ans;
    cin >> T;

    while (T--) {
        cin >> N >> M, ans = 0;
        for (int i = 1; i <= N; i++)
            cin >> P[i], A[i] = 0;
        init(1, 1, N);
        for (int i = 1; i <= M; i++) {
            cin >> X;
            K = query(1, 1, N, X);
            if (K == -1)
                continue;
            A[K] = i, update(1, 1, N, K);
        }

        for (int i = 1; i <= N; i++)
            ans += A[i] * i;
        cout << ans << '\n';
    }

    return 0;
}