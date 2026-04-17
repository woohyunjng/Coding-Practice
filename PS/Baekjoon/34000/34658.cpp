#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 500001;
const int MOD = 998244353;

int N, A[MAX], tree[MAX * 4];

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

int comb(int X) { return X * (X - 1) / 2 % MOD; }

int calc(int X) {
    int V = query(1, 0, N, X, X), B = query(1, 0, N, X + 1, N), res;
    res = comb(X) * (V * (B * 2 + V - 1) / 2 % MOD) % MOD % MOD;
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int Q, X, Y, ans = 0;
    vector<int> arr;

    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        cin >> A[i], arr.push_back(i);
        update(1, 0, N, A[i], 1);
    }

    for (int i = 0; i <= N; i++)
        ans += calc(i), ans %= MOD;

    while (Q--) {
        cin >> X >> Y;

        ans = (ans - calc(A[X] + Y) - calc(A[X]) + MOD * 2) % MOD;
        update(1, 0, N, A[X], -1), update(1, 0, N, A[X] + Y, 1);
        ans = (ans + calc(A[X] + Y) + calc(A[X])) % MOD;

        cout << ans << '\n', A[X] += Y;
    }
}