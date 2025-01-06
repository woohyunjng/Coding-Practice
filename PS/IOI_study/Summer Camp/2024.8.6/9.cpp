#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MAX_VAL 4100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int A[MAX], B[MAX], arr[MAX_VAL][MAX_VAL], fac[MAX], inv_fac[MAX];

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

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, res = 0;
    cin >> N;

    init(6000);

    for (int i = 1; i <= N; i++) {
        cin >> A[i] >> B[i];
        arr[-A[i] + 2000][-B[i] + 2000]++;
    }

    for (int i = 1; i <= 4000; i++) {
        arr[0][i] += arr[0][i - 1];
        arr[i][0] += arr[i - 1][0];
    }

    for (int i = 1; i <= 4000; i++) {
        for (int j = 1; j <= 4000; j++)
            arr[i][j] = (arr[i][j] + arr[i - 1][j] + arr[i][j - 1]) % MOD;
    }

    for (int i = 1; i <= N; i++)
        res = (res + arr[A[i] + 2000][B[i] + 2000]) % MOD;

    for (int i = 1; i <= N; i++)
        res = (res - comb((A[i] + B[i]) * 2, 2 * A[i]) % MOD + MOD) % MOD;

    res = (res * prime_inverse(2, MOD) % MOD + MOD) % MOD;

    cout << (res + MOD) % MOD;

    return 0;
}