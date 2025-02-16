#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 1000000;
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

int comb(int N, int K) {
    int X = fac[N], Y = inv[K], Z = inv[N - K];
    return X * Y % MOD * Z % MOD;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, ans = 1, X, Y;

    fac[0] = 1;
    for (int i = 1; i < MAX; i++)
        fac[i] = fac[i - 1] * i % MOD;
    inv[MAX - 1] = fpow(fac[MAX - 1], MOD - 2);
    for (int i = MAX - 2; i >= 0; i--)
        inv[i] = inv[i + 1] * (i + 1) % MOD;

    cin >> N;
    while (N--) {
        cin >> X >> Y;
        ans = ans * (comb(X + Y, min(X, Y)) - 1) % MOD;
    }

    cout << ans << '\n';

    return 0;
}