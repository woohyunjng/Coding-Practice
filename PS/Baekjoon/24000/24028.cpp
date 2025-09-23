#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 5001;
const int INF = 0x3f3f3f3f3f3f3f3f;

int A[MAX], dp[MAX][MAX][2];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, B, C;

    cin >> N >> K >> B >> C;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    for (int i = 0; i <= N; i++)
        for (int j = 0; j <= N; j++)
            dp[i][j][0] = dp[i][j][1] = INF;
    dp[0][0][0] = 0;

    for (int i = 1; i <= N; i++)
        for (int j = 0; j <= N; j++) {
            dp[i][j][0] = dp[i - 1][j][0] + A[i];
            dp[i][j][1] = dp[i - 1][j][1] + A[i];

            if (j > 0)
                dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j - 1][0] - i * C + B);
            if (j + 1 <= N)
                dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j + 1][1] + i * C + B);

            if (j * 2 >= K)
                dp[i][j][1] = min(dp[i][j][1], dp[i][j][0] - j * j * C);
            if (j * 2 + 1 >= K)
                dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j][0] - j * (j + 1) * C + B);

            if (j == 0)
                dp[i][j][0] = min(dp[i][j][0], dp[i][j][1]);
        }

    cout << dp[N][0][0] << '\n';

    return 0;
}