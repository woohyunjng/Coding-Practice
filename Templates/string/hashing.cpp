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

class Hash {
  public:
    int base, mod1, mod2, N;
    string S;

    vector<int> H[2], P[2];

    Hash(string S, int base = 31, int mod1 = 1234567891, int mod2 = 1000000007) : S(S), base(base), mod1(mod1), mod2(mod2) {
        N = S.size();

        for (int i = 0; i < 2; i++) {
            H[i].resize(N + 1), P[i].resize(N + 1);
            P[i][0] = 1;
        }

        for (int i = 1; i <= N; i++) {
            P[0][i] = P[0][i - 1] * base % mod1;
            P[1][i] = P[1][i - 1] * base % mod2;
        }

        for (int i = 1; i <= N; i++) {
            H[0][i] = (H[0][i - 1] * base + S[i - 1] - 'a' + 1) % mod1;
            H[1][i] = (H[1][i - 1] * base + S[i - 1] - 'a' + 1) % mod2;
        }
    }

    int get(int l, int r) {
        int val_1, val_2;
        val_1 = (H[0][r] - H[0][l - 1] * P[0][r - l + 1] % mod1 + mod1) % mod1;
        val_2 = (H[1][r] - H[1][l - 1] * P[1][r - l + 1] % mod2 + mod2) % mod2;

        return val_1 * mod2 + val_2;
    }
};