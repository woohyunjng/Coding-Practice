#include <bits/stdc++.h>
using namespace std;

const int MAX = 10001;

int V[MAX], dp[MAX][2];
vector<int> adj[MAX];

void dfs(int node, int par) {
    dp[node][1] = V[node];
    for (int i : adj[node]) {
        if (i == par)
            continue;
        dfs(i, node);
        dp[node][0] += max(dp[i][0], dp[i][1]);
        dp[node][1] += dp[i][0];
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, Y;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> V[i];
    for (int i = 1; i < N; i++) {
        cin >> X >> Y;
        adj[X].push_back(Y), adj[Y].push_back(X);
    }

    dfs(1, 0);

    cout << max(dp[1][0], dp[1][1]) << '\n';

    return 0;
}