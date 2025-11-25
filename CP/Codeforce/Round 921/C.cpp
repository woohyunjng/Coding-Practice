#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 300000;
const int MOD = 999'999'893;

int fpow(int N, int K) {
    int res = 1;
    while (K) {
        if (K & 1)
            res = res * N % MOD;
        N = N * N % MOD, K >>= 1;
    }
    return res;
}

int inv(int N) { return fpow(N, MOD - 2); }

void solve() {
    int N, A, B, C, D, P, Q;

    cin >> N;
    A = (fpow(2, N - 1) - fpow(2, N / 2) + MOD) % MOD;
    B = (fpow(2, N - 1) - fpow(2, (N - 1) / 2) + MOD) % MOD;

    C = A, D = B;
    if (N & 1)
        D = (D + fpow(2, N / 2)) % MOD;
    else
        C = (C + fpow(2, N / 2)) % MOD;

    P = (A * D % MOD - B * C % MOD + MOD) % MOD, Q = (2 * D * D % MOD - C * C % MOD + MOD) % MOD;
    cout << P * inv(Q) % MOD << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;

    while (T--)
        solve();

    return 0;
}