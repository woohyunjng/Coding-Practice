#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef pair<int, int> pr;
typedef tuple<int, int, int> tp;

pr arr[510];
int dp[510][510];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> arr[i].first >> arr[i].second;

    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j <= N - i; j++)
        {
            dp[j][i + j] = LLONG_MAX;
            for (int k = j; k <= i + j; k++)
                dp[j][i + j] = min(
                    dp[j][i + j],
                    dp[j][k] + dp[k + 1][i + j] + arr[j].first * arr[k].second * arr[j + i].second);
        }
    }

    cout << dp[1][N];

    return 0;
}