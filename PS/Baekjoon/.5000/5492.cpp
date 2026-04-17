#include <bits/stdc++.h>
#define int long long

#define MAX 20100
#define MAX_S 4010
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;

int dp[2][MAX_S][2], X[MAX], Y[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, res = INF;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> X[i] >> Y[i], X[i] += 1500, Y[i] += 1500;

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < MAX_S; j++)
            for (int k = 0; k < 2; k++)
                dp[i][j][k] = INF;

    dp[0][1500][0] = dp[0][1500][1] = 0;
    X[0] = Y[0] = 1500;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < MAX_S; j++) {
            dp[i & 1 ^ 1][X[i]][1] = min(dp[i & 1 ^ 1][X[i]][1], dp[i & 1][j][0] + abs(j - Y[i + 1]));
            dp[i & 1 ^ 1][j][0] = min(dp[i & 1 ^ 1][j][0], dp[i & 1][j][0] + abs(X[i + 1] - X[i]));
            dp[i & 1 ^ 1][Y[i]][0] = min(dp[i & 1 ^ 1][Y[i]][0], dp[i & 1][j][1] + abs(j - X[i + 1]));
            dp[i & 1 ^ 1][j][1] = min(dp[i & 1 ^ 1][j][1], dp[i & 1][j][1] + abs(Y[i + 1] - Y[i]));
        }

        fill(&dp[i & 1][0][0], &dp[i & 1][MAX_S][2], INF);
    }

    for (int i = 0; i < MAX_S; i++)
        res = min({res, dp[N & 1][i][0], dp[N & 1][i][1]});
    cout << res << '\n';

    return 0;
}