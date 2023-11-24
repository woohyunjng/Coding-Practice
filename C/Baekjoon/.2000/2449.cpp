#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K, A;
    cin >> N >> K;

    int arr[N], dp[N][N];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < N; i++)
    {
        cin >> A;
        arr[i] = A - 1;
    }

    for (int i = 0; i < N; i++)
        dp[i][i] = 0;

    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < N - i; j++)
        {
            dp[j][i + j] = 100000000;
            for (int k = 0; k < i; k++)
                dp[j][i + j] = min(dp[j][i + j], dp[j][j + k] + dp[j + k + 1][i + j] + (int)(arr[j] != arr[j + k + 1]));
        }
    }

    cout << dp[0][N - 1];
}