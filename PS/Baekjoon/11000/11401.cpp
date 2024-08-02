#include <bits/stdc++.h>
#define int long long
#define MAX 4001000
#define MOD 1000000007

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int fac[MAX], fac_cur;

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

int factorial(int N) {
    if (fac[N])
        return fac[N];
    if (!fac_cur)
        fac[0] = 1, fac_cur = 1;

    for (int i = fac_cur; i <= N; i++)
        fac[i] = fac[i - 1] * i % MOD;
    fac_cur = N;
    return fac[N];
}

int comb(int A, int B) {
    int X = factorial(A), Y, Z;
    Y = factorial(B), Z = factorial(A - B);
    return X * prime_inverse(Y, MOD) % MOD * prime_inverse(Z, MOD) % MOD;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K;
    cin >> N >> K;
    cout << comb(N, K);

    return 0;
}