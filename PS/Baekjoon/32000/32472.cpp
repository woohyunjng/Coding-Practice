#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 150000;
const int SZ = 600;
const int MOD = 1000000007;

int A, B, dp[MAX][SZ], sz[MAX];
vector<int> adj[MAX];

void dfs(int node, int par) {
    dp[node][1] = 1, sz[node] = 1;

    for (int i : adj[node]) {
        if (i == par)
            continue;
        dfs(i, node);
        for (int j = min(B, sz[node]); j >= 1; j--) {
            for (int k = 1; k <= min(B - j, sz[i]); k++)
                dp[node][j + k] = (dp[node][j + k] + dp[node][j] * dp[i][k]) % MOD;
            dp[node][j] = dp[node][j] * dp[i][0] % MOD;
        }
        sz[node] += sz[i];
    }
    dp[node][0] = (dp[node][A] + dp[node][B]) % MOD;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, Y;

    cin >> N >> A >> B;
    for (int i = 1; i < N; i++) {
        cin >> X >> Y;
        adj[X].push_back(Y), adj[Y].push_back(X);
    }

    dfs(1, 0);

    cout << dp[1][0] << '\n';

    return 0;
}