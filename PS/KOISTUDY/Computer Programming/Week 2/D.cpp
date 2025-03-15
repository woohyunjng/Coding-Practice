#include <bits/stdc++.h>
using namespace std;

const int MAX = 20;

int dp[MAX][4];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;

    dp[1][1] = dp[2][2] = 1;
    dp[3][1] = dp[3][2] = dp[3][3] = 1;

    cin >> N;
    for (int i = 4; i <= N; i++) {
        for (int j = 1; j <= 3; j++)
            for (int k = 1; k <= 3; k++)
                if (j != k)
                    dp[i][j] += dp[i - j][k];
    }
    cout << dp[N][1] + dp[N][2] + dp[N][3] << '\n';

    return 0;
}