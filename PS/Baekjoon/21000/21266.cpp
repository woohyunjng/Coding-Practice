#include <bits/stdc++.h>
#define int long long

#define MAX 2001000
#define MOD 998244353
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int A[MAX];

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

int fac[MAX], inv_fac[MAX], fact[MAX];

void init(int L) {
    fac[0] = 1;
    for (int i = 1; i <= L; i++)
        fac[i] = fac[i - 1] * i % MOD;
    inv_fac[L] = fpow(fac[L], MOD - 2);
    for (int i = L - 1; i >= 0; i--)
        inv_fac[i] = inv_fac[i + 1] * (i + 1) % MOD;

    fact[0] = 1;
    for (int i = 1; i <= L; i++)
        fact[i] = fact[i - 1] * (2 * i - 1) % MOD;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, res = 0;
    cin >> N;

    init(N);
    N--;

    for (int i = 0; i <= N; i++) {
        cin >> A[i];
        if (A[i])
            res = (res + (((fact[i] * fact[N - i] % MOD) * inv_fac[i] % MOD) * inv_fac[N - i] % MOD) * fac[N]) % MOD;
    }

    cout << res;

    return 0;
}