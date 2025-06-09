#include <bits/stdc++.h>
using namespace std;

const int MAX = 201;
const int MOD = 9901;

int dp[MAX][MAX], S[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K;

    cin >> N >> K;

    if (N % 2 == 0) {
        cout << 0 << '\n';
        return 0;
    }

    N = (N - 1) / 2, K--;

    dp[1][1] = dp[0][0] = 1, S[1][1] = 1, S[0][0] = S[0][1] = 1;

    for (int i = 1; i <= K; i++) {
        S[0][i] = (S[0][i - 1] + dp[0][i]) % MOD;
        S[1][i] = (S[1][i - 1] + dp[1][i]) % MOD;
    }

    for (int i = 2; i <= N; i++) {
        for (int j = 2; j <= K; j++) {
            for (int k = 0; k <= i - 1; k++)
                dp[i][j] = (dp[i][j] + dp[k][j - 1] * S[i - 1 - k][j - 2] * 2) % MOD;
            for (int k = 0; k <= i - 1; k++)
                dp[i][j] = (dp[i][j] + dp[k][j - 1] * dp[i - 1 - k][j - 1]) % MOD;
            if (i < j)
                dp[i][j] = 0;
            S[i][j] = (S[i][j - 1] + dp[i][j]) % MOD;
        }
    }

    cout << dp[N][K] << '\n';

    return 0;
}