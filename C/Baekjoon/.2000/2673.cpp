#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, A, B, dp[102][102];
    memset(dp, 0, sizeof(dp));

    cin >> N;
    pair<int, int> arr[N];
    for (int i = 0; i < N; i++)
    {
        cin >> A >> B;
        arr[i] = {min(A, B), max(A, B)};
    }

    for (int i = 0; i < 100; i++)
    {
        for (int j = 1; j <= 100 - i; j++)
        {
            int k = j + i;

            for (pair<int, int> p : arr)
            {
                if (j <= p.first && p.second <= k)
                {
                    dp[j][k] = max(dp[p.first + 1][p.second - 1] + dp[j][p.first - 1] + dp[p.second + 1][k] + 1, dp[j][k]);
                }
            }
        }
    }

    cout << dp[1][100];
}
