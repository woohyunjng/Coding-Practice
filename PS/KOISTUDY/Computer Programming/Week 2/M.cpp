#include <bits/stdc++.h>
using namespace std;

const int MAX = 20;

int dp[MAX][4][4];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, ans = 0;

    dp[0][0][0] = dp[1][0][1] = dp[2][0][2] = dp[2][1][1] = 1;

    cin >> N;
    for (int i = 3; i <= N; i++) {
        for (int j = 1; j <= 3; j++)
            for (int k = 0; k <= 3; k++)
                for (int l = 0; l <= 3; l++) {
                    if (k == l && k == j)
                        continue;
                    dp[i][l][j] += dp[i - j][k][l];
                }
    }

    for (int i = 0; i <= 3; i++)
        for (int j = 0; j <= 3; j++)
            ans += dp[N][i][j];
    cout << ans << '\n';

    return 0;
}