#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef tuple<int, int, int> tp;
typedef pair<int, int> pr;

int arr[1000][1000], dp[1000][1000];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, i, j, k, res = 0;
    cin >> N;

    vector<tp> vec;

    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= N; j++)
        {
            cin >> arr[i][j];
            vec.push_back({arr[i][j], i, j});
        }
    }
    sort(vec.begin(), vec.end());

    for (tp k : vec)
    {
        pr go[4] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        i = get<1>(k), j = get<2>(k);
        dp[i][j] = 1;

        for (pr m : go)
        {
            if (arr[i][j] > arr[i + m.first][j + m.second])
                dp[i][j] = max(dp[i][j], dp[i + m.first][j + m.second] + 1);
        }
        res = max(res, dp[i][j]);
    }

    cout << res;
    return 0;
}