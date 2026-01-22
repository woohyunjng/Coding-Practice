#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAX = 2000002;
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

int fac[MAX], inv[MAX], dp[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, X;

    fac[0] = 1;
    for (int i = 1; i < MAX; i++)
        fac[i] = fac[i - 1] * i % MOD;
    inv[MAX - 1] = fpow(fac[MAX - 1], MOD - 2);
    for (int i = MAX - 2; i >= 0; i--)
        inv[i] = inv[i + 1] * (i + 1) % MOD;

    dp[0] = dp[1] = 0;
    dp[2] = dp[3] = 1;

    for (int i = 4; i + 2 < MAX; i += 3) {
        X = (i - 1) / 3, X = fac[X * 2] * inv[X] % MOD * inv[X + 1] % MOD;
        dp[i] = ((dp[i - 1] + dp[i - 2]) % MOD - X + MOD) % MOD;
        dp[i + 1] = (dp[i] + dp[i - 1]) % MOD;
        dp[i + 2] = (dp[i + 1] + dp[i]) % MOD;
    }
    dp[0] = dp[1] = -1;

    cin >> T;
    while (T--)
        cin >> N, cout << dp[N] << '\n';

    return 0;
}