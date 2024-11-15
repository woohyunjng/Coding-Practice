#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int A[MAX], B[MAX];

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

int fac[MAX], inv_fac[MAX];

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

    int N, M, X = INF, res = 1, K = 0;
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        cin >> A[i];

    for (int i = 1; i <= M; i++)
        cin >> B[i];

    sort(A + 1, A + N + 1), sort(B + 1, B + M + 1, greater<int>());

    for (int i = 1; i <= N; i++)
        X = min(X, A[i] + B[i]);
    sort(B + 1, B + M + 1);

    for (int i = 1; i <= N; i++) {
        if (A[i] < X)
            res = res * (M - (lower_bound(B + 1, B + M + 1, X - A[i]) - B) + 1) % MOD, M--;
        else {
            K = N - i + 1;
            break;
        }
    }

    init(max(N, M)), X = 0;

    for (int i = 0; i <= min(K, M); i++)
        X = (X + comb(K, i) * comb(M, i) % MOD * fac[i] % MOD) % MOD;
    res = res * X % MOD;

    cout << res << '\n';

    return 0;
}