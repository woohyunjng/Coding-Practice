#include <bits/stdc++.h>
using namespace std;

const int MAX = 20;

int dp[MAX][MAX][MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, ans = 0;
    dp[0][0][0][0] = dp[1][1][0][0] = dp[2][2][0][0] = dp[2][0][1][0] = 1;

    cin >> N >> K;
    for (int i = 3; i <= N; i++)
        for (int j = 0; j <= i; j++)
            for (int k = 0; k <= i; k++)
                for (int l = 0; l <= i; l++) {
                    dp[i][j + 1][k][l] += dp[i - 1][j][k][l];
                    dp[i][j][k + 1][l] += dp[i - 2][j][k][l];
                    dp[i][j][k][l + 1] += dp[i - 3][j][k][l];
                }

    for (int i = 0; i < K; i++)
        for (int j = 0; j < K; j++)
            for (int k = 0; k < K; k++)
                ans += dp[N][i][j][k];

    cout << ans << '\n';

    return 0;
}