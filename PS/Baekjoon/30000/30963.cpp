#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 1000001;
const int MOD = 1000000007;

int dp[MAX], V[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, P, C, N, S;

    cin >> T;
    while (T--) {
        cin >> P >> C >> N;

        V[0] = 1, S = 0;
        for (int i = 1; i <= N; i++)
            V[i] = V[i - 1] * (1 - P + MOD) % MOD;

        S = P;
        for (int i = 1; i <= N; i++) {
            dp[i] = S;
            if (i >= C)
                dp[i] = (dp[i] + (dp[i - C] + 1) * V[C] % MOD) % MOD;
            S = S * V[1] % MOD, S = (S + (dp[i] + 1) * P % MOD) % MOD;
            if (i >= C)
                S = (S - (dp[i - C] + 1) * P % MOD * V[C] % MOD + MOD) % MOD;
            cout << dp[i] << '\n';
        }
    }

    return 0;
}