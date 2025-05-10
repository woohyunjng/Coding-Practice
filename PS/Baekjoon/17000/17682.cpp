#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 3001;
const int MOD = 1000000007;

int dp[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int H, W;

    cin >> H >> W;

    for (int i = 0; i <= max(H, W); i++)
        dp[i][0] = dp[0][i] = 1;

    for (int i = 1; i <= H; i++)
        for (int j = 1; j <= W; j++) {
            dp[i][j] = (i * dp[i - 1][j - 1] * 4 + dp[i][j - 1]) % MOD;
            if (i >= 2)
                dp[i][j] = (dp[i][j] + i * (i - 1) / 2 % MOD * dp[i - 2][j - 1]) % MOD;
            if (j >= 2)
                dp[i][j] = (dp[i][j] + i * (j - 1) % MOD * dp[i - 1][j - 2]) % MOD;
        }

    cout << (dp[H][W] - 1 + MOD) % MOD << '\n';

    return 0;
}