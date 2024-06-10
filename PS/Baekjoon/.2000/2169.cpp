#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef pair<int, int> pr;
typedef tuple<int, int, int> tp;

int arr[1010][1010], left_dp[1010][1010], right_dp[1010][1010], dp[1010][1010];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
            cin >> arr[i][j];
    }

    dp[1][1] = arr[1][1];
    for (int i = 2; i <= M; i++)
        dp[1][i] = arr[1][i] + dp[1][i - 1];

    for (int i = 2; i <= N; i++)
    {
        left_dp[i][1] = dp[i - 1][1] + arr[i][1];
        right_dp[i][M] = dp[i - 1][M] + arr[i][M];
        for (int j = M - 1; j >= 1; j--)
            right_dp[i][j] = max(right_dp[i][j + 1], dp[i - 1][j]) + arr[i][j];
        for (int j = 2; j <= M; j++)
            left_dp[i][j] = max(left_dp[i][j - 1], dp[i - 1][j]) + arr[i][j];
        for (int j = 1; j <= M; j++)
            dp[i][j] = max(left_dp[i][j], right_dp[i][j]);
    }

    cout << dp[N][M];

    return 0;
}