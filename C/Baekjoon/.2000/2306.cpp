#include <bits/stdc++.h>
#define int long long
using namespace std;

int dp[1000][1000];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string S;
    cin >> S;

    int N = S.size();
    for (int i = 2; i <= N; i++)
    {
        for (int j = 0; j <= N - i; j++)
        {
            if ((S[j] == 'a' && S[j + i - 1] == 't') || (S[j] == 'g' && S[j + i - 1] == 'c'))
                dp[j][i] = max(dp[j][i], dp[j + 1][i - 2] + 2);
            for (int k = 0; k < i; k++)
                dp[j][i] = max(dp[j][i], dp[j][k] + dp[j + k][i - k]);
        }
    }

    cout << dp[0][N];
    return 0;
}