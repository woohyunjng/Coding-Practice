#include <bits/stdc++.h>
#define int long long
#define MAX 100100
#define MOD 1000000007

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int fac[MAX], inv_fac[MAX];

int fpow(int N, int K) {
    int res = 1;
    while (K) {
        if (K & 1)
            res = res * N % MOD;
        K >>= 1;
        N = N * N % MOD;
    }
    return res;
}

int prime_inverse(int K, int X) { return fpow(K, X - 2); }

tp extended_gcd(int A, int B) {
    if (B == 0)
        return {A, 1, 0};
    tp res = extended_gcd(B, A % B);
    return {res[0], res[2], res[1] - A / B * res[2]};
}

int modular_inverse(int K, int X) {
    tp res = extended_gcd(K, X);
    if (res[0] != 1)
        return -1;
    return (res[1] % X + X) % X;
}

void init(int L) {
    fac[0] = 1;
    for (int i = 1; i <= L; i++)
        fac[i] = fac[i - 1] * i % MOD;
    inv_fac[L] = fpow(fac[L], MOD - 2);
    for (int i = L - 1; i >= 0; i--)
        inv_fac[i] = inv_fac[i + 1] * (i + 1) % MOD;
}

int comb(int A, int B) {
    int X = fac[A], Y, Z;
    Y = fac[B], Z = fac[A - B];
    return X * prime_inverse(Y, MOD) % MOD * prime_inverse(Z, MOD) % MOD;
}