#include <bits/stdc++.h>
#define int long long
using namespace std;

int arr[100], dp[100][600000];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, sm = 0;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        sm += arr[i];
    }

    dp[0][arr[0]] = arr[0];
    for (int i = 1; i < N; i++)
    {
        dp[i][arr[i]] = max(arr[i], dp[i - 1][arr[i]]);
        for (int j = 0; j <= sm; j++)
        {
            if (!dp[i - 1][j])
                continue;
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            dp[i][j + arr[i]] = max(dp[i - 1][j] + arr[i], dp[i - 1][j + arr[i]]);
            if (j >= arr[i])
                dp[i][j - arr[i]] = max(dp[i][j - arr[i]], max(dp[i - 1][j - arr[i]], dp[i - 1][j]));
            else
                dp[i][arr[i] - j] = max(dp[i][arr[i] - j], max(dp[i - 1][arr[i] - j], dp[i - 1][j] - j + arr[i]));
        }
    }

    cout << (dp[N - 1][0] ? dp[N - 1][0] : -1);

    return 0;
}