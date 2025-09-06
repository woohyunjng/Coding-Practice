#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 200001;
const int INF = 0x3f3f3f3f3f3f3f3f;

int V[MAX], dp[MAX][3], ans = -INF;
vector<int> adj[MAX];

void dfs(int node) {
    vector<int> arr;

    dp[node][0] = V[node];
    for (int i : adj[node]) {
        dfs(i), arr.push_back(dp[i][2]);
        dp[node][2] = max(dp[node][2], dp[i][2]);

        if (dp[i][0] > 0)
            dp[node][0] += dp[i][0], dp[node][1] = max(dp[node][1], dp[i][1]);
        else
            dp[node][1] = max(dp[node][1], dp[i][2]);
    }
    dp[node][2] = max(dp[node][2], dp[node][0]);
    ans = max(ans, dp[node][0] + dp[node][1]);

    sort(arr.begin(), arr.end(), greater<int>());
    if (arr.size() >= 2)
        ans = max(ans, arr[0] + arr[1]);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> V[i] >> X;
        if (X != -1)
            adj[X].push_back(i);
        fill(dp[i], dp[i] + 3, -INF);
    }

    dfs(1);
    cout << ans << '\n';

    return 0;
}