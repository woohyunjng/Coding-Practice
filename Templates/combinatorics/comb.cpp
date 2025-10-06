int fpow(int N, int K) {
    int res = 1;
    while (K) {
        if (K & 1)
            res = res * N % MOD;
        K >>= 1, N = N * N % MOD;
    }
    return res;
}

int fac[MAX], inv_fac[MAX];

void init(int L) {
    fac[0] = 1;
    for (int i = 1; i <= L; i++)
        fac[i] = fac[i - 1] * i % MOD;
    inv_fac[L] = fpow(fac[L], MOD - 2);
    for (int i = L - 1; i >= 0; i--)
        inv_fac[i] = inv_fac[i + 1] * (i + 1) % MOD;
}

int comb(int A, int B) {
    if (A < B || A < 0 || B < 0)
        return 0;
    int X = fac[A], Y = inv_fac[B], Z = inv_fac[A - B];
    return X * Y % MOD * Z % MOD;
}
