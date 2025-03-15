#include <bits/stdc++.h>
using namespace std;

const int MAX = 40;

int dp[MAX][MAX][3]; // 0 -> 사람 X, 1 -> 사람 O(여유로운 사람), 2 -> 사람 O(여유롭지 않은 사람)

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K;

    cin >> N >> K;
    dp[0][0][1] = 1;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= K; j++)
            for (int k = 0; k <= 2; k++)
                dp[i][j][0] += dp[i - 1][j][k];
        for (int j = 1; j <= K; j++) {
            dp[i][j][1] = dp[i - 1][j - 1][0];
            dp[i][j][2] = dp[i - 1][j - 1][1];
        }
    }

    cout << dp[N][K][0] + dp[N][K][1] << '\n';

    return 0;
}