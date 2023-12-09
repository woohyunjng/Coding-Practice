#include <iostream>
#include <cstring>
#define MAX 20
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long dp[MAX + 1][MAX + 1][MAX + 1];

    memset(dp, 0, sizeof(dp));
    dp[1][1][1] = 1;

    for (int i = 2; i <= MAX; i++)
    {
        for (int l = 1; l <= MAX; l++)
        {
            for (int r = 1; r <= MAX + 1 - l; r++)
            {
                dp[i][l][r] = ((i - 2) * dp[i - 1][l][r] + dp[i - 1][l - 1][r] + dp[i - 1][l][r - 1]);
            }
        }
    }

    int T, N, L, R;
    cin >> T;

    while (T--)
    {
        cin >> N >> L >> R;
        cout << dp[N][L][R] << '\n';
    }
}