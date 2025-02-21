#include <bits/stdc++.h>
#define int long long
#define ll __int128_t

using namespace std;

const int MAX = 5001;

vector<int> adj[MAX];
int K, S, sz[MAX];
ll dp[MAX][MAX], val[MAX];

void dfs(int node, int par) {
    dp[node][1] = 1, sz[node] = 1;
    for (int i : adj[node]) {
        if (i == par)
            continue;
        dfs(i, node), sz[node] += sz[i];
        for (int j = sz[node] - sz[i]; j >= 1; j--)
            for (int k = 1; k <= sz[i]; k++)
                dp[node][j + k] += dp[node][j] * dp[i][k];
    }
    for (int i = 1; i <= sz[node]; i++)
        val[i] += dp[node][i];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, X, Y, st, en, md, ans;
    ll cnt = 0;
    cin >> N >> K;

    for (int i = 1; i < N; i++) {
        cin >> X >> Y;
        adj[X].push_back(Y), adj[Y].push_back(X);
    }

    dfs(1, 0);

    for (int i = 1; i <= N; i++) {
        cnt += val[i];
        if (cnt >= K) {
            cout << i << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';

    return 0;
}