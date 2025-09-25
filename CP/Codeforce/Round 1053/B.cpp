#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 200001;
const int MOD = 998244353;

int A[MAX], fac[MAX], inv_fac[MAX];

int comb(int A, int B) {
    if (A < B || A < 0 || B < 0)
        return 0;
    int X = fac[A], Y = inv_fac[B], Z = inv_fac[A - B];
    return X * Y % MOD * Z % MOD;
}

void solve() {
    int N, ans = 1, S = 0, X;
    bool ans_chk = true;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i], S += A[i];
        if (i > (N + 1) / 2)
            ans_chk &= A[i] == 0;
    }
    ans_chk &= S == N && A[1] >= 2;

    X = N % 2 == 1 ? -1 : 0;
    for (int i = (N + 1) / 2; i >= 1; i--) {
        X += 2, ans_chk &= A[i] <= X;
        if (ans_chk)
            ans *= comb(X, A[i]), X -= A[i], ans %= MOD;
    }

    ans = ans_chk ? ans : 0;
    cout << ans << '\n';
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

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;

    fac[0] = 1;
    for (int i = 1; i < MAX; i++)
        fac[i] = fac[i - 1] * i % MOD;
    inv_fac[MAX - 1] = fpow(fac[MAX - 1], MOD - 2);
    for (int i = MAX - 2; i >= 0; i--)
        inv_fac[i] = inv_fac[i + 1] * (i + 1) % MOD;

    while (T--)
        solve();

    return 0;
}