#include <bits/stdc++.h>
#define int long long
#define MAX 3000

using namespace std;
typedef pair<int, int> pr;

pr dp[1000][1000], track[1000][1000];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    string S;
    cin >> S;

    for (int i = 2; i <= N; i += 2)
    {
        for (int j = 0; j <= N; j++)
            dp[j][i] = {MAX, 0};
    }

    for (int i = 2; i <= N; i += 2)
    {
        for (int j = 0; j <= N - i; j++)
        {
            if ((S[j] == '0' && S[j + i - 1] == '1') || (S[j] == '1' && S[j + i - 1] == '0'))
            {
                if (dp[j + 1][i - 2].first + dp[j + 1][i - 2].second * 2 + i + 1 < dp[j][i].first)
                {
                    dp[j][i] = {
                        dp[j + 1][i - 2].first + dp[j + 1][i - 2].second * 2 + i + 1,
                        dp[j + 1][i - 2].second + 1};
                    track[j][i] = {0, 0};
                }
            }
            for (int k = 2; k < i; k += 2)
            {
                if (dp[j][k].first + dp[j + k][i - k].first < dp[j][i].first)
                {
                    dp[j][i] = {
                        dp[j][k].first + dp[j + k][i - k].first,
                        max(dp[j][k].second, dp[j + k][i - k].second)};
                    track[j][i] = {1, k};
                }
            }
        }
    }
    cout << dp[0][N].first << '\n';

    vector<pr> res;
    stack<pr> st;
    st.push({0, N});

    while (!st.empty())
    {
        pr i = st.top();
        st.pop();
        if (i.second == 2)
        {
            res.push_back({i.first + 1, i.first + 2});
            continue;
        }

        pr j = track[i.first][i.second];
        if (j.first)
        {
            st.push({i.first, j.second});
            st.push({i.first + j.second, i.second - j.second});
        }
        else
        {
            res.push_back({i.first + 1, i.first + i.second});
            st.push({i.first + 1, i.second - 2});
        }
    }

    sort(res.begin(), res.end());
    for (pr i : res)
        cout << i.first << ' ' << i.second << '\n';
    return 0;
}