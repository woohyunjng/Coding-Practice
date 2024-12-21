#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

vector<vector<vector<int>>> dp;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M;
    cin >> N >> M;
    if (N < M)
        swap(N, M);

    dp.resize(N, vector<vector<int>>(M, vector<int>(1 << (M + 1), 0)));

    for (int i = N - 1; i >= 0; i--)
        for (int j = M - 1; j >= 0; j--)
            for (int k = 0; k < (1 << (M + 1)); k++) {
                if (j >= 1 && (k & (1 << M)) && (k & (1 << 0)) && (k & (1 << 1))) {
                    if (i == N - 1 && j == M - 1)
                        dp[i][j][k] = 1;
                    else if (j == M - 1)
                        dp[i][j][k] = dp[i + 1][0][k >> 1];
                    else
                        dp[i][j][k] = dp[i][j + 1][k >> 1];
                } else {
                    if (i == N - 1 && j == M - 1)
                        dp[i][j][k] = 2;
                    else if (j == M - 1)
                        dp[i][j][k] = (dp[i + 1][0][k >> 1] + dp[i + 1][0][(k >> 1) | (1 << M)]) % MOD;
                    else
                        dp[i][j][k] = (dp[i][j + 1][k >> 1] + dp[i][j + 1][(k >> 1) | (1 << M)]) % MOD;
                }
            }

    cout << dp[0][0][0] << '\n';

    return 0;
}