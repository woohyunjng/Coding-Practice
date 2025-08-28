#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MOD = 998244353;

int fpow(int N, int K) {
    int res = 1;
    while (K) {
        if (K & 1)
            res = res * N % MOD;
        N = N * N % MOD, K >>= 1;
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, P, N, M, X, ans;

    cin >> T;
    while (T--) {
        cin >> P >> N >> M;
        if (N > M)
            swap(N, M);
        X = fpow(P, N), ans = fpow(P, M), M = (M - 1) / N;
        if (X == 1)
            ans += M;
        else
            ans += (fpow(X, M) - 1 + MOD) % MOD * fpow((X - 1 + MOD) % MOD, MOD - 2) % MOD * X % MOD;
        ans %= MOD;
        cout << ans << '\n';
    }

    return 0;
}