#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 100001;
const int INF = 0x3f3f3f3f3f3f3f3f;

vector<int> adj[MAX];
int N, dp[MAX], sz[MAX], ans = INF;

void dfs(int node, int par) {
    sz[node] = 1, dp[node] = 0;
    for (int i : adj[node]) {
        if (i == par)
            continue;
        dfs(i, node), sz[node] += sz[i];
        dp[node] += dp[i] + sz[i] - sz[i] * sz[i];
    }
    dp[node] += (sz[node] - 1) * (sz[node] - 1);
}

void calc(int node, int par, int val) {
    int prs = N - sz[node], res = val + prs - prs * prs, K;
    for (int i : adj[node]) {
        if (i == par)
            continue;
        res += dp[i] + sz[i] - sz[i] * sz[i];
    }
    ans = min(ans, res + (N - 1) * (N - 1));

    for (int i : adj[node]) {
        if (i == par)
            continue;
        K = res - (dp[i] + sz[i] - sz[i] * sz[i]);
        K += (N - sz[i] - 1) * (N - sz[i] - 1);
        calc(i, node, K);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int U, V;

    cin >> N;
    for (int i = 1; i < N; i++) {
        cin >> U >> V;
        adj[U].push_back(V), adj[V].push_back(U);
    }

    dfs(1, 0), calc(1, 0, 0);

    cout << ans << '\n';

    return 0;
}