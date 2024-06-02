#include <bits/stdc++.h>
#define int long long

using namespace std;

int N, arr[30][3], dp[30][30];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];

    dp[N][N] = 1;
    for (int i = N; i >= 1; i--)
    {
        for (int j = N; j > i; j--)
        {
            for (int k = i + 1; k <= N; k++)
            {
                if ((arr[k][0] - arr[i][0]) <= arr[i][1])
                    dp[i][j] += dp[k][j];
                if (arr[k][2] && (arr[k][0] - arr[i][0]) <= arr[k][1])
                    dp[j][i] += dp[j][k];
            }
        }
    }

    for (int i = 2; i <= N; i++)
    {
        if ((arr[i][0] - arr[1][0]) <= arr[1][1])
            dp[1][1] += dp[i][1];
    }

    if (!dp[1][1])
        cout << "I will solve 1000 problems.";
    else
        cout << dp[1][1];
    return 0;
}