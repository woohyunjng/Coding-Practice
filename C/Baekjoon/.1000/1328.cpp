#include <iostream>
#include <cstring>
#define MOD 1000000007
using namespace std;

int main()
{
    int N, L, R;
    long long dp[101][101][101];
    cin >> N >> L >> R;

    memset(dp, 0, sizeof(dp));
    dp[1][1][1] = 1;

    for (int i = 2; i <= N; i++)
    {
        for (int l = 1; l <= N; l++)
        {
            for (int r = 1; r <= N + 1 - l; r++)
            {
                dp[i][l][r] = ((i - 2) * dp[i - 1][l][r] + dp[i - 1][l - 1][r] + dp[i - 1][l][r - 1]) % MOD;
            }
        }
    }

    cout << dp[N][L][R];
}