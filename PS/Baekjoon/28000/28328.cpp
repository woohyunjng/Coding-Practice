#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 300000;

vector<int> adj[MAX];
int dp[MAX][2], state[MAX];
bool chk[MAX][2];

void dfs(int node, int par) {
    dp[node][1] = 1;
    for (int i : adj[node]) {
        if (i == par)
            continue;
        dfs(i, node);
        dp[node][0] += max(dp[i][0], dp[i][1]);
        dp[node][1] += dp[i][0];
    }
}

void dfs_ans(int node, int par, int mode) {
    if (chk[node][mode])
        return;
    state[node] &= mode, chk[node][mode] = true;

    for (int i : adj[node]) {
        if (i == par)
            continue;
        if (mode == 1)
            dfs_ans(i, node, 0);
        else {
            if (dp[i][0] >= dp[i][1])
                dfs_ans(i, node, 0);
            if (dp[i][0] <= dp[i][1])
                dfs_ans(i, node, 1);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, Y, ans = 0;
    cin >> N;

    for (int i = 1; i < N; i++) {
        cin >> X >> Y;
        adj[X].push_back(Y), adj[Y].push_back(X);
    }

    fill(state, state + N + 1, 1);
    dfs(1, 0);
    if (dp[1][0] >= dp[1][1])
        dfs_ans(1, 0, 0);
    if (dp[1][0] <= dp[1][1])
        dfs_ans(1, 0, 1);

    for (int i = 1; i <= N; i++)
        ans += state[i];

    cout << N * (N - 1) / 2 - ans * (ans - 1) / 2 << '\n';

    return 0;
}