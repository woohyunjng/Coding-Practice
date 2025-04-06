#include <bits/stdc++.h>
using namespace std;

const int MAX = 10001;
const int MAX_V = 101;

int V[MAX];
bool dp[MAX][MAX_V];
vector<int> adj[MAX];

void dfs(int node) {
    for (int i : adj[node])
        dfs(i);

    dp[node][V[node]] = true;
    for (int i = V[node] - 1; i >= 1; i--) {
        if (!dp[node][i + 1])
            continue;
        for (int j : adj[node]) {
            if (V[j] > i || !dp[j][i])
                continue;
            for (int k = 1; k <= V[j]; k++)
                dp[node][k] |= dp[j][k];
        }
    }

    for (int i = V[node] + 1; i < MAX_V; i++) {
        if (!dp[node][i - 1])
            continue;
        for (int j : adj[node]) {
            if (V[j] < i || !dp[j][i])
                continue;
            for (int k = V[j]; k < MAX_V; k++)
                dp[node][k] |= dp[j][k];
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, Y, ans = 0;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> V[i];

    for (int i = 1; i < N; i++) {
        cin >> X >> Y;
        adj[X].push_back(Y);
    }

    dfs(1);

    X = 0, Y = 0;
    for (int i = 1; i <= V[1]; i++)
        X += dp[1][i];
    for (int i = V[1]; i < MAX_V; i++)
        Y += dp[1][i];
    ans = X * Y;

    cout << ans << '\n';

    return 0;
}