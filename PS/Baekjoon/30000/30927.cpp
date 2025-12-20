#include <bits/stdc++.h>
using namespace std;

const int MAX = 101;

int dp[MAX][MAX], X[MAX], Y[MAX];
bool ans[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, K, A, B;
    string S;

    cin >> T;
    while (T--) {
        cin >> N >> S, dp[0][0] = 1;
        for (int i = 1; i <= N; i++) {
            X[i] = X[i - 1], Y[i] = Y[i - 1];
            if (S[i - 1] == 'R')
                X[i]++;
            else
                Y[i]++;

            dp[0][i] = dp[i][0] = 1, ans[i] = false;
            for (int j = 1; j <= N; j++)
                dp[i][j] = 2;
        }

        for (int t = 1; t <= N; t++) {
            for (int i = 1; i <= N; i++) {
                A = X[N] - X[i - 1], B = Y[N] - Y[i - 1];
                for (int j = 0; j <= A + B; j++)
                    if (dp[j][A + B - j] + dp[A][B] == 3)
                        dp[j][A + B - j] = 0;
                ans[i] |= dp[A][B] == 1;
            }
            for (int i = 0; i <= N; i++) {
                for (int j = (i == 0 ? 1 : 0); j <= N; j++) {
                    if (dp[i][j] == 0)
                        continue;
                    dp[i][j] = (i > 0 ? dp[i - 1][j] > 0 : 0) + (j > 0 ? dp[i][j - 1] > 0 : 0);
                }
            }
        }

        for (int i = 1; i <= N; i++)
            cout << ans[i], ans[i] = 0;
        cout << '\n';
    }

    return 0;
}