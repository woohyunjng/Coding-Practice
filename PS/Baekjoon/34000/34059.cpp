#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 1000001;
const int MOD = 1'000'000'007;

int fac[MAX], inv_fac[MAX], two[MAX];

int fpow(int N, int K) {
    int res = 1;
    while (K) {
        if (K & 1)
            res = res * N % MOD;
        N = N * N % MOD, K >>= 1;
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

    int N, A, B, X = 0, Y = 0, V, ans;
    cin >> N >> A >> B;

    if (A > B)
        swap(A, B);

    fac[0] = 1;
    for (int i = 1; i <= N; i++)
        fac[i] = fac[i - 1] * i % MOD;
    inv_fac[N] = fpow(fac[N], MOD - 2);
    for (int i = N - 1; i >= 0; i--)
        inv_fac[i] = inv_fac[i + 1] * (i + 1) % MOD;
    two[0] = 1;
    for (int i = 1; i <= N; i++)
        two[i] = two[i - 1] * 2 % MOD;

    if (A + 1 == B) {
        V = comb(A - 2 + N - B, A - 2) * 2 % MOD;
        for (int i = A; i <= N - 2; i++)
            X = (X + comb(N - 3, i - 1)) % MOD;
        for (int i = N + 2 - B; i <= N - 2; i++)
            Y = (Y + comb(N - 3, i - 1)) % MOD;
        ans = (X + Y + V) % MOD;
    } else {
        X = N - B, Y = A - 2;
        ans = comb(X + Y, Y) * 2 % MOD;
        ans = ans * two[B - A - 2] % MOD;
    }
    cout << ans << '\n';

    return 0;
}