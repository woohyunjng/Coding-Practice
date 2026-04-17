#include <bits/stdc++.h>
using namespace std;

const int MAX = 7004;
const int INF = MAX * MAX;

int dp[2][MAX][16], A[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, X, Y, ans;
    string S;

    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> S, N = S.size(), ans = INF;
        for (int i = 1; i <= N; i++)
            A[i] = S[i - 1] - 'A' + 1;

        for (int i = 0; i <= N + 2; i++)
            fill(dp[0][i], dp[0][i] + 16, INF);
        dp[0][0][0] = 0;

        for (int i = 1; i <= N; i++) {
            for (int j = 0; j <= i + 3; j++)
                fill(dp[i & 1][j], dp[i & 1][j] + 16, INF);
            for (int j = 1; j <= i; j++)
                for (int k = 0; k < 4; k++) {
                    if ((j >= 2 && k == 0) || k == A[i] || (j == 1 && k != 0))
                        continue;
                    X = k * 4 + A[i], Y = 6 - A[i] - k;
                    dp[i & 1][j][X] = min(dp[i & 1][j][X], dp[i & 1 ^ 1][j][X] + 1);
                    if (j == 1) {
                        for (int l = 1; l < 4; l++) {
                            if (l == A[i])
                                continue;
                            dp[i & 1][j][X] = min(dp[i & 1][j][X], dp[i & 1 ^ 1][j + 1][A[i] * 4 + l] + 2);
                            dp[i & 1][j][X] = min(dp[i & 1][j][X], dp[i & 1 ^ 1][j + 2][l * 4 + 6 - l - A[i]] + 3);
                        }
                        dp[i & 1][j][X] = min(dp[i & 1][j][X], dp[i & 1 ^ 1][j - 1][0] + 2);
                    } else {
                        dp[i & 1][j][X] = min(dp[i & 1][j][X], dp[i & 1 ^ 1][j + 1][A[i] * 4 + Y] + 2);
                        dp[i & 1][j][X] = min(dp[i & 1][j][X], dp[i & 1 ^ 1][j + 2][Y * 4 + k] + 3);
                        if (j == 2)
                            dp[i & 1][j][X] = min(dp[i & 1][j][X], dp[i & 1 ^ 1][j - 1][k] + 2);
                        else
                            dp[i & 1][j][X] = min(dp[i & 1][j][X], dp[i & 1 ^ 1][j - 1][Y * 4 + k] + 2);
                    }
                }
        }

        for (int i = 1; i <= N; i++)
            for (int j = 0; j < 16; j++)
                ans = min(ans, dp[N & 1][i][j] + i);

        cout << "Case #" << t << ": " << ans << '\n';
    }

    return 0;
}