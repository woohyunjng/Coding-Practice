#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef pair<int, int> pr;

int dp[1600][20000];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, V, C, K, A;
    vector<pr> arr;

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> V >> C >> K;
        while (K)
        {
            A = K - (K >> 1);
            arr.push_back({V * A, C * A});
            K >>= 1;
        }
    }
    for (int i = 1; i <= arr.size(); i++)
    {
        for (int j = 0; j <= M; j++)
        {
            if (arr[i - 1].first <= j)
                dp[i][j] = dp[i - 1][j - arr[i - 1].first] + arr[i - 1].second;
            dp[i][j] = max(dp[i][j], max(dp[i - 1][j], dp[i][j - 1]));
        }
    }

    cout << dp[arr.size()][M];

    return 0;
}