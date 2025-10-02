#include <bits/stdc++.h>
#define int long long

using namespace std;

int fpow(int N, int K, int MOD) {
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

    int M, S, X[2], A, C;

    cin >> M >> S >> X[0] >> X[1];

    A = fpow((X[0] - S + M) % M, M - 2, M) * (X[1] - X[0] + M) % M;
    C = (X[0] - A * S % M + M) % M;

    cout << A << ' ' << C << '\n';

    return 0;
}