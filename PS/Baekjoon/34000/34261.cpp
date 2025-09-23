#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 100001;
const int MOD = 1'000'000'007;

int T[MAX], F[MAX], M[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int S, K, V = 0, ans = 0, X;
    string N;

    cin >> K >> N, T[0] = 1, S = N.size();
    for (int i = 1; i <= S; i++)
        T[i] = (T[i - 1] * 10) % MOD;

    M[0] = 1;
    for (int i = 1; i <= S; i++) {
        F[i] = F[i - 1] * 10 % MOD;
        for (int j = 0; j < 10; j++) {
            if (j == K)
                continue;
            F[i] += j * M[i - 1] % MOD, F[i] %= MOD;
            M[i] += M[i - 1] * 10, M[i] %= MOD;
        }
        M[i] += M[i - 1], M[i] %= MOD;
    }

    for (int i = 0; i < S; i++) {
        X = N[i] - '0';
        ans += F[S - i - 1] * X % MOD, ans %= MOD;

        for (int j = 0; j < X; j++) {
            if (j == K)
                ans += V * M[S - i - 1], ans %= MOD;
            else
                ans += (V * 10 + j) % MOD * M[S - i - 1], ans %= MOD;
        }

        if (X != K)
            V = V * 10 + X, V %= MOD;
    }
    ans += V, ans %= MOD;

    cout << ans << '\n';

    return 0;
}