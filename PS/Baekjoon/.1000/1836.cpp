#include <bits/stdc++.h>
using namespace std;

int dp[205][205], MOD = 9901;

int main() {
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= 200; i++)
        dp[1][i] = 1;

    for (int i = 2; i <= n; i++)
        for (int j = 2; j <= k; j++) {
            for (int a = 1; a <= i - 2; a++)
                dp[i][j] += dp[a][j - 1] * dp[i - a - 1][j - 1];
            dp[i][j] %= MOD;
        }

    cout << (dp[n][k] - dp[n][k - 1] + MOD) % MOD;

    return 0;
}