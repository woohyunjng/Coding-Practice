#include <bits/stdc++.h>
using namespace std;

const int MAX = 1001;

int S[MAX], T[MAX], dp[MAX][MAX][11];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    string _S, _T;
    int N, M, ans = MAX;

    cin >> _S >> _T;
    N = _S.size(), M = _T.size();

    for (int i = 1; i <= N; i++)
        S[i] = _S[i - 1] - '0';
    for (int i = 1; i <= M; i++)
        T[i] = _T[i - 1] - '0';

    for (int i = 0; i <= N; i++)
        for (int j = 0; j <= M; j++)
            fill(dp[i][j], dp[i][j] + 11, MAX);
    dp[0][0][0] = 0;

    for (int i = 1; i <= N; i++)
        for (int j = 0; j <= min(i - 1, M - 1); j++) {
            for (int k = 0; k <= 10; k++) {
                dp[i][j][(k + S[i]) % 10] = min(dp[i][j][(k + S[i]) % 10], dp[i - 1][j][k]);
                dp[i][j][k % 10] = min(dp[i][j][k % 10], dp[i - 1][j][k] + 1);
            }
            dp[i][j + 1][10] = dp[i][j][T[j + 1]];
            if (j + 1 == M)
                ans = min(ans, dp[i][j + 1][10] + N - i);
        }

    if (ans == MAX)
        ans = -1;
    cout << ans << '\n';

    return 0;
}