#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 1000001;
const int MOD = 1000000007;

int fac[MAX], inv_fac[MAX];

int fpow(int N, int K) {
    int res = 1;
    while (K) {
        if (K & 1)
            res = res * N % MOD;
        K >>= 1, N = N * N % MOD;
    }
    return res;
}

int comb(int A, int B) {
    if (A < B || A < 0 || B < 0)
        return 0;
    int X = fac[A], Y = inv_fac[B], Z = inv_fac[A - B];
    return X * Y % MOD * Z % MOD;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, V, ans = 0;

    cin >> N;

    fac[0] = 1;
    for (int i = 1; i <= N; i++)
        fac[i] = fac[i - 1] * i % MOD;

    inv_fac[N] = fpow(fac[N], MOD - 2);
    for (int i = N - 1; i >= 0; i--)
        inv_fac[i] = inv_fac[i + 1] * (i + 1) % MOD;

    for (int i = 1; i <= N; i++) {
        V = fac[N - 1] * inv_fac[i - 1] % MOD * inv_fac[N - i] % MOD;
        V *= fac[N] * inv_fac[i] % MOD * inv_fac[N - i] % MOD, V %= MOD;
        V *= fac[N] * inv_fac[N - i + 1] % MOD, V %= MOD;
        ans += V, ans %= MOD;
    }

    cout << ans << '\n';

    return 0;
}
