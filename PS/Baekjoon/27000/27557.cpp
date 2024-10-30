#include <bits/stdc++.h>
#define int long long

#define MAX 1001000
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int A[MAX], fac[MAX], inv_fac[MAX];

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

    int N, res = 1, X = 0, cnt = 0, sm = 0;
    cin >> N;

    init(MAX - 1);

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        A[i] >>= 1;
    }

    vector<int> arr;
    for (int i = 1; i <= N; i++) {
        if (A[i] >= A[i + 1])
            res = res * comb(A[i], A[i + 1]) % MOD;
        else
            res = res * comb(A[i + 1] - 1, A[i] - 1) % MOD;
    }

    cout << res;

    return 0;
}