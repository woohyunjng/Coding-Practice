#include <bits/stdc++.h>
#define int long long
#define MAX 10000000000

using namespace std;
typedef pair<int, int> pr;
typedef tuple<int, int, int> tp;

pr arr[2000];
tp track[2000][2000];
int dp[2000][2000], res[2000];

int dis(pr A, pr B) { return abs(A.first - B.first) + abs(A.second - B.second); };

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, W, A, B, mn = MAX;
    cin >> N;
    cin >> W;

    for (int i = 1; i <= W; i++)
        cin >> arr[i].first >> arr[i].second;

    for (int i = 1; i <= W; i++)
    {
        dp[0][i] = dp[0][i - 1] + dis(i != 1 ? arr[i - 1] : (pr){N, N}, arr[i]);
        track[0][i] = {2, 0, i - 1};

        dp[i][0] = dp[i - 1][0] + dis(i != 1 ? arr[i - 1] : (pr){1, 1}, arr[i]);
        track[i][0] = {1, i - 1, 0};

        dp[i][i] = MAX;
    }

    for (int i = 1; i <= W; i++)
    {
        for (int j = 1; j < i; j++)
        {
            dp[i][j] = MAX;
            dp[j][i] = MAX;
            if (i == j + 1)
            {
                for (int k = 0; k < j; k++)
                {
                    A = dp[k][j] + dis(k ? arr[k] : (pr){1, 1}, arr[i]), B = dp[j][k] + dis(k ? arr[k] : (pr){N, N}, arr[i]);
                    if (A < dp[i][j])
                    {
                        dp[i][j] = A;
                        track[i][j] = {1, k, j};
                    }

                    if (B < dp[j][i])
                    {
                        dp[j][i] = B;
                        track[j][i] = {2, j, k};
                    }
                }
            }
            else
            {
                dp[i][j] = dp[i - 1][j] + dis(arr[i - 1], arr[i]);
                track[i][j] = {1, i - 1, j};

                dp[j][i] = dp[j][i - 1] + dis(arr[i - 1], arr[i]);
                track[j][i] = {2, j, i - 1};
            }
        }
    }

    for (int i = 0; i < W; i++)
    {
        if (dp[i][W] < mn)
        {
            mn = dp[i][W];
            A = i, B = W;
        }

        if (dp[W][i] < mn)
        {
            mn = dp[W][i];
            A = W, B = i;
        }
    }
    cout << mn << '\n';

    for (int i = W; i >= 1; i--)
    {
        tp K = track[A][B];
        res[i] = get<0>(K), A = get<1>(K), B = get<2>(K);
    }

    for (int i = 1; i <= W; i++)
        cout << res[i] << '\n';
    return 0;
}