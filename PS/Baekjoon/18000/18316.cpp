#include <bits/stdc++.h>
#define int long long

#define MAX 1100
#define MAX_DAY 1100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int P[MAX], dp[MAX][MAX_DAY];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, C, X, Y, res = 0;
    vector<pr> arr;
    cin >> N >> M >> C;

    for (int i = 1; i <= N; i++)
        cin >> P[i];

    while (M--) {
        cin >> X >> Y;
        arr.push_back({X, Y});
    }

    fill(&dp[0][0], &dp[MAX][0], -INF);
    dp[1][0] = 0;

    for (int i = 1; i <= 1000; i++) {
        for (pr j : arr)
            dp[j.second][i] = max(dp[j.second][i], dp[j.first][i - 1] + P[j.second]);
        res = max(res, dp[1][i] - C * i * i);
    }

    cout << res << '\n';

    return 0;
}