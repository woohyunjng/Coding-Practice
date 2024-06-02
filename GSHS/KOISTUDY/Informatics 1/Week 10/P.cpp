#include <bits/stdc++.h>
#define MOD 1000000007
#define int long long

using namespace std;

int dp[10010][10010];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, res = 0;
    cin >> N;

    dp[N][N] = 1;

    for (int i = N; i >= 0; i--)
    {
        for (int j = N; j > i; j--)
        {
            for (int k = i + 1; k <= i + 3; k++)
                dp[i][j] += dp[k][j];
            for (int k = i + 1; k <= i + 4; k++)
                dp[j][i] += dp[j][k];
            dp[i][j] %= MOD;
            dp[j][i] %= MOD;
        }
    }

    for (int i = 1; i <= 3; i++)
        dp[0][0] += dp[i][0];

    cout << dp[0][0] % MOD << '\n';
}