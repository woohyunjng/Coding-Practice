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
