#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 100002;
const int MOD = 1000000007;

int fac[MAX], inv[MAX];

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

    int N, K, V, ans = 0;

    cin >> N >> K;

    fac[0] = 1;
    for (int i = 1; i <= N + 1; i++)
        fac[i] = fac[i - 1] * i % MOD;
    inv[N + 1] = fpow(fac[N + 1], MOD - 2) % MOD;
    for (int i = N; i >= 0; i--)
        inv[i] = inv[i + 1] * (i + 1) % MOD;

    for (int i = 0; i <= K; i++) {
        V = fac[N + 1] * inv[i] % MOD * inv[N + 1 - i] % MOD * fpow(K - i, N) % MOD;
        if (i & 1)
            ans = (ans - V + MOD) % MOD;
        else
            ans = (ans + V) % MOD;
    }

    cout << ans << '\n';

    return 0;
}