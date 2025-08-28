#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000001;
const int INF = 2e9;

int dp[MAX][6], A[MAX], B[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, ans = INF;
    string _A, _B;

    cin >> N >> _A >> _B;
    for (int i = 1; i <= N; i++)
        A[i] = _A[i - 1] - '0', B[i] = _B[i - 1] - '0';

    for (int i = 0; i <= N; i++)
        fill(dp[i], dp[i] + 6, INF);
    dp[0][0] = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 5; j >= 0; j--) {
            if (((j % 3 == 0 ? A[i] : j % 3 - 1) ^ (j / 3)) != B[i])
                continue;
            dp[i][j] = min({dp[i][j], dp[i - 1][j], dp[i - 1][j - j % 3] + 1, dp[i - 1][j - j / 3 * 3] + 1, dp[i - 1][0] + 2});
            dp[i][j - j % 3] = min(dp[i][j - j % 3], dp[i][j]);
            dp[i][j - j / 3 * 3] = min(dp[i][j - j / 3 * 3], dp[i][j]);
        }
    }

    for (int i = 0; i < 6; i++)
        ans = min(ans, dp[N][i]);

    cout << ans << '\n';

    return 0;
}