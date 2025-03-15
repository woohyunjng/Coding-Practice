#include <bits/stdc++.h>
using namespace std;

const int MAX = 20;

int dp[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M;
    dp[0][0] = dp[1][0] = 1, dp[2][0] = 2;

    cin >> N;
    for (int i = 3; i <= N; i++) {
        if (i == M)
            continue;
        for (int j = 0; j <= i / 3; j++)
            if (i % 3 == 0)
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 2][j - 1] + dp[i - 3][j - 1];
            else
                dp[i][j] = dp[i - 1][j] + dp[i - 2][j] + dp[i - 3][j];
    }
    cout << dp[N][1] << '\n';

    return 0;
}