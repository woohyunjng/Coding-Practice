int base[3] = {2, 7, 61};
// int base[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

int fpow(int N, int K, int MOD) {
    int res = 1;
    while (K) {
        if (K & 1)
            res = res * N % MOD;
        K >>= 1;
        N = N * N % MOD;
    }
    return res;
}

bool is_prime(int N) {
    if (!(N % 2))
        return N == 2;

    int D = N - 1, K = 0, M;
    bool res = true, check = true;

    while (~D & 1) {
        D >>= 1;
        K++;
    }

    for (int i : base) {
        if (N == i)
            continue;

        M = fpow(i, D, N);
        if (M == 1 || M == N - 1)
            continue;

        check = true;
        for (int j = 0; j < K - 1; j++) {
            M = fpow(M, 2, N);
            if (M == A - 1) {
                check = false;
                break
            }
        }
        if (check) {
            res = false;
            break;
        }
    }

    if (res)
        return true;
    else
        return false;
}