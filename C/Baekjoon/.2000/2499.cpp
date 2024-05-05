#include <iostream>
#include <cmath>
#define int long long
using namespace std;

int arr[30][30], subsum[30][30], sm;
bool dp[30][30][50000], checked;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    for (int j = 0; j < N; j++)
    {
        for (int i = 0; i < N; i++)
            cin >> arr[i][j];
    }

    for (int i = 0; i < N; i++)
    {
        subsum[i][0] = 0;
        for (int j = 1; j <= N; j++)
            subsum[i][j] = subsum[i][j - 1] + arr[i][j - 1];
    }

    for (int i = 0; i < N; i++)
    {
        if (i == 0)
        {
            dp[0][0][0] = true;
            for (int j = 1; j <= N; j++)
                dp[i][j][subsum[i][j]] = true;
            continue;
        }

        for (int j = 0; j <= N; j++)
        {
            for (int k = N; k >= j; k--)
            {
                for (int m = 0; m <= 40000 - subsum[i][j]; m++)
                {
                    if (dp[i - 1][k][m])
                        dp[i][j][m + subsum[i][j]] = true;
                }
            }
        }
    }

    for (int i = 0; i < N; i++)
        sm += subsum[i][N];

    int mn = 1000000, val, x, y;
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= sm / 2; j++)
        {
            if (dp[N - 1][i][(sm >> 1) - j] || dp[N - 1][i][(sm >> 1) + j])
            {
                if (dp[N - 1][i][(int)(sm / 2) - j])
                {
                    val = j * 2 + sm % 2;
                    if (val < mn)
                    {
                        mn = val;
                        x = i, y = (sm >> 1) - j;
                    }
                }
                else if (dp[N - 1][i][(sm >> 1) + j])
                {
                    val = abs(j * 2 - sm % 2);
                    if (val < mn)
                    {
                        mn = val;
                        x = i, y = (sm >> 1) + j;
                    }
                }
            }
        }
    }

    cout << mn << '\n';

    int res[N];
    res[N - 1] = x;

    for (int i = N - 1; i >= 1; i--)
    {
        y = y - subsum[i][x];
        for (int j = x; j <= N; j++)
        {
            if (dp[i - 1][j][y])
            {
                x = j;
                break;
            }
        }
        res[i - 1] = x;
    }

    for (int i = 0; i < N; i++)
        cout << N - res[i] << ' ';
}