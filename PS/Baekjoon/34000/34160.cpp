#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define int long long

using namespace std;

const int MAX = 400001;
const int MOD = 998244353;
const int W = 3;

int fac[MAX], inv_fac[MAX], A[MAX], R[MAX], IR[MAX];
bool chk[MAX];

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

int comb(int A, int B) {
    if (A < B || A < 0 || B < 0)
        return 0;
    int X = fac[A], Y = inv_fac[B], Z = inv_fac[A - B];
    return X * Y % MOD * Z % MOD;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, ans = 0, S;
    vector<vector<int>> arr;
    vector<int> VR;

    fac[0] = 1;
    for (int i = 1; i < MAX; i++)
        fac[i] = fac[i - 1] * i % MOD;
    inv_fac[MAX - 1] = fpow(fac[MAX - 1], MOD - 2);
    for (int i = MAX - 2; i >= 0; i--)
        inv_fac[i] = inv_fac[i + 1] * (i + 1) % MOD;

    for (int i = 2; i < MAX; i <<= 1)
        R[i] = fpow(W, (MOD - 1) / i), IR[i] = fpow(R[i], MOD - 2);

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    for (int i = 1; i <= N; i++) {
        if (chk[i])
            continue;
        S = 0, X = i;
        while (!chk[X])
            S++, chk[X] = true, X = A[X];

        for (int j = 0; j <= S; j++)
            VR.push_back((2 * comb(2 * S - j, 2 * (S - j)) - comb(2 * S - j - 1, 2 * (S - j) - 1) + MOD) % MOD);
        if (S == 1)
            VR[1] = 1;
        arr.push_back(VR), VR.clear();
    }

    for (int i = 0; i + 1 < arr.size(); i += 2)
        arr.push_back(mul(arr[i], arr[i + 1]));

    for (int i = 0; i <= N; i++)
        ans += (i % 2 == 0 ? 1 : -1) * arr.back()[i] * fac[N - i] % MOD, ans = (ans + MOD) % MOD;
    cout << ans << '\n';

    return 0;
}