#include <bits/stdc++.h>
#define int long long

using namespace std;

int res[30], dp[30][400], arr[30][400], track[30][400];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, K;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> K;
        for (int j = 1; j <= M; j++)
            cin >> arr[j][K];
    }

    for (int i = 1; i <= M; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            for (int k = 0; k <= j; k++)
            {
                if (dp[i - 1][j - k] + arr[i][k] > dp[i][j])
                {
                    dp[i][j] = dp[i - 1][j - k] + arr[i][k];
                    track[i][j] = k;
                }
            }
        }
    }

    cout << dp[M][N] << '\n';

    K = N;
    for (int i = M; i >= 1; i--)
    {
        res[i] = track[i][K];
        K -= track[i][K];
    }

    for (int i = 1; i <= M; i++)
        cout << res[i] << ' ';

    return 0;
}