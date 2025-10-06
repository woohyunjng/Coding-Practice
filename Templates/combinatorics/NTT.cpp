const int W = 3;
const int MOD = 998244353;

void init() {
    for (int i = 2; i < MAX; i <<= 1)
        R[i] = fpow(W, (MOD - 1) / i), IR[i] = fpow(R[i], MOD - 2);
}

int fpow(int N, int K) {
    int res = 1;
    while (K) {
        if (K & 1)
            res = res * N % MOD;
        K >>= 1, N = N * N % MOD;
    }
    return res;
}

void NTT(vector<int> &v, bool inv) {
    int S = v.size(), K, ang, A, B, root;

    for (int i = 1, j = 0; i < S; i++) {
        K = S >> 1;
        for (; j & K; K >>= 1)
            j ^= K;
        j ^= K;
        if (i < j)
            swap(v[i], v[j]);
    }

    for (int i = 2; i <= S; i <<= 1)
        for (int j = 0; j < S; j += i) {
            root = 1;
            for (int k = 0; k < (i >> 1); k++) {
                A = v[j | k], B = v[j | k | i >> 1] * root % MOD;
                v[j | k] = (A + B) % MOD, v[j | k | i >> 1] = (A - B + MOD) % MOD;
                root = root * (inv ? IR[i] : R[i]) % MOD;
            }
        }

    A = fpow(S, MOD - 2);
    if (inv)
        for (int i = 0; i < S; i++)
            v[i] = v[i] * A % MOD;
}

vector<int> mul(vector<int> A, vector<int> B) {
    int S = 1, SZ = (int)A.size() + B.size() - 1;

    while (S < A.size() + B.size())
        S <<= 1;
    A.resize(S), B.resize(S);

    NTT(A, false), NTT(B, false);
    for (int i = 0; i < S; i++)
        A[i] = A[i] * B[i] % MOD;
    NTT(A, true), A.resize(SZ);
    return A;
}