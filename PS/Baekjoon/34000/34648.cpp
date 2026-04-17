#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MOD = 1'000'000'007;

int inv(int N) {
    int res = 1, K = MOD - 2;
    while (K) {
        if (K & 1)
            res = res * N % MOD;
        N = N * N % MOD, K >>= 1;
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int P, Q, N, A, B, resA = 1, resB = 1;

    cin >> P >> Q >> N;
    if (N == 1)
        cout << 0 << '\n';
    else if (N == 2)
        cout << 0 << ' ' << 1 << '\n';
    else {
        A = B = 1;
        cout << 0 << ' ' << 1 << ' ';
        for (int i = 3; i <= N; i++) {
            if (A > B)
                swap(A, B);
            if ((A + 2) * Q >= A * P)
                resA = resA * (A + 2) % MOD, resB = resB * A % MOD, A++;
            else
                resA = resA * P % MOD, resB = resB * Q % MOD;

            cout << (resA * inv(resB) % MOD) << ' ';
        }
        cout << '\n';
    }
}