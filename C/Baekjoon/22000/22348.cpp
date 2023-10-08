#include <bits/stdc++.h>
#define MAX 450
#define MOD 1000000007
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T, A, B, K, N = (int)(MAX * (MAX + 1) / 2) + 1;
    long long int sum[MAX][N], dp[MAX][N], res;

    memset(sum, 0, sizeof(sum));
    memset(dp, 0, sizeof(dp));

    dp[0][0] = 1;

    for (int i = 1; i < MAX; i++)
    {
        A = (int)(i * (i + 1) / 2);
        for (int j = 0; j <= A; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= i)
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - i]) % MOD;
            }
        }
    }

    for (int i = 1; i < MAX; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (j)
                sum[i][j] = (dp[i][j] + sum[i][j - 1]) % MOD;
            else
                sum[i][j] = dp[i][j];
        }
    }

    cin >> T;
    while (T--)
    {
        cin >> A >> B;
        res = 0;

        for (int i = 1; i <= MAX && (A + B) >= (int)(i * (i + 1) / 2); i++)
        {
            K = i * (i + 1) / 2;
            res = (res + sum[i][A] + MOD - (K > B ? sum[i][K - B - 1] : 0)) % MOD;
        }

        cout << res << '\n';
    }
}