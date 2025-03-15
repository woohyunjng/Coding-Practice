#include <bits/stdc++.h>
using namespace std;

const int MAX = 20;

int dp[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;

    dp[0][0] = 1, dp[1][1] = 1, dp[2][1] = dp[1][2] = 1;

    cin >> N;
    for (int i = 2; i <= N; i++)
        for (int j = 2; j <= N; j++)
            dp[i][j] = dp[i - 1][j - 2] + dp[i - 2][j - 1] + dp[i - 1][j - 1] + dp[i - 2][j - 2];
    cout << dp[N][N] << '\n';

    return 0;
}