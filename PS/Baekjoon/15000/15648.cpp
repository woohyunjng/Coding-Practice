#include <bits/stdc++.h>
using namespace std;

const int MAX = 500001;

int tree[MAX * 4], A[MAX], V[MAX];

void update(int n, int s, int e, int x, int v) {
    if (x < s || e < x)
        return;
    else if (s == e)
        tree[n] = max(tree[n], v);
    else {
        int m = s + e >> 1;
        update(n << 1, s, m, x, v), update(n << 1 | 1, m + 1, e, x, v);
        tree[n] = max(tree[n << 1], tree[n << 1 | 1]);
    }
}

int query(int n, int s, int e, int l, int r) {
    if (r < s || e < l)
        return 0;
    else if (l <= s && e <= r)
        return tree[n];
    else {
        int m = s + e >> 1;
        return max(query(n << 1, s, m, l, r), query(n << 1 | 1, m + 1, e, l, r));
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, D, S = 0, ans = 0, L;

    cin >> N >> K >> D;
    for (int i = 1; i <= N; i++)
        cin >> A[i], S = max(S, A[i]);

    for (int i = 1; i <= N; i++) {
        L = max(V[A[i] % K], query(1, 1, S, max(1, A[i] - D), min(S, A[i] + D))) + 1;
        V[A[i] % K] = max(V[A[i] % K], L), update(1, 1, S, A[i], L), ans = max(ans, L);
    }

    cout << ans << '\n';

    return 0;
}