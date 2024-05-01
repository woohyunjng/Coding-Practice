#include <iostream>
#define int long long
using namespace std;

int N, arr[101], dp[101][21];
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    dp[1][arr[0]] = 1;
    for (int i = 2; i <= N; i++)
    {
        for (int j = 0; j <= 20 - arr[i - 1]; j++)
            dp[i][j + arr[i - 1]] += dp[i - 1][j];
        for (int j = arr[i - 1]; j <= 20; j++)
            dp[i][j - arr[i - 1]] += dp[i - 1][j];
    }

    cout << dp[N][0];
}