#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 501
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    int arr[N], dp[N][MAX];
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    memset(dp, 0, sizeof(dp));
    dp[0][arr[0]] = arr[0];

    for (int i = 1; i < N; i++)
    {
        dp[i][arr[i]] = max(dp[i][arr[i]], max(arr[i], dp[i - 1][arr[i]]));
        for (int j = 0; j < MAX - arr[i]; j++)
        {
            if (!dp[i - 1][j])
                continue;

            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            dp[i][arr[i] + j] = max(dp[i][arr[i] + j], max(dp[i - 1][arr[i] + j], dp[i - 1][j] + arr[i]));
            if (j >= arr[i])
                dp[i][j - arr[i]] = max(dp[i][j - arr[i]], max(dp[i - 1][j - arr[i]], dp[i - 1][j]));
            else
                dp[i][arr[i] - j] = max(dp[i][arr[i] - j], max(dp[i - 1][arr[i] - j], dp[i - 1][j] - j + arr[i]));
        }
    }

    cout << (dp[N - 1][0] ? dp[N - 1][0] : -1);
}
