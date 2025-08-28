#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 10001;
const int MOD = 998244353;

int fac[MAX], inv_fac[MAX], A[MAX], V[MAX], K[MAX];
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

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, S, X, ans = 0;
    vector<int> arr;

    cin >> N, init(N << 1);
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    for (int i = 1; i <= N; i++) {
        if (chk[i])
            continue;
        S = 0, X = i;
        while (!chk[X])
            S++, chk[X] = true, X = A[X];
        arr.push_back(S);
    }

    S = 0, V[0] = 1;
    for (int i : arr) {
        for (int j = 0; j <= i; j++)
            K[j] = (2 * comb(2 * i - j, 2 * (i - j)) - comb(2 * i - j - 1, 2 * (i - j) - 1) + MOD) % MOD;
        if (i == 1)
            K[1] = 1;
        for (int j = S; j >= 0; j--)
            for (int k = 1; k <= i; k++)
                V[j + k] += V[j] * K[k], V[j + k] %= MOD;
        S += i;
    }

    for (int i = 0; i <= N; i++)
        ans += (i % 2 == 0 ? 1 : -1) * V[i] * fac[N - i] % MOD, ans = (ans + MOD) % MOD;
    cout << ans << '\n';

    return 0;
}