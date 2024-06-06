#include <bits/stdc++.h>
#define int long long
using namespace std;

int dp[3000];
bool check[3000][3000];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string S;
    cin >> S;

    int N = S.size();

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - i; j++)
        {
            if (!i)
                check[j][j] = true;
            else
            {
                if (S[j] == S[j + i] && (i == 1 || check[j + 1][j + i - 1]))
                    check[j][j + i] = true;
            }
        }
    }

    dp[0] = 1;
    for (int i = 1; i < N; i++)
    {
        dp[i] = dp[i - 1] + 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (check[j][i])
            {
                if (!j)
                    dp[i] = 1;
                else
                    dp[i] = min(dp[i], dp[j - 1] + 1);
            }
        }
    }
    cout << dp[N - 1];
    return 0;
}