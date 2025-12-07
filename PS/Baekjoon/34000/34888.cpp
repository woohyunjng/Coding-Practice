#include <bits/stdc++.h>
using namespace std;

const int MAX = 5002;
const int INF = 1e9;

int K, dp[MAX][MAX], P[MAX], C[MAX], S[MAX], cnt, V[MAX];
vector<int> adj[MAX];

void sz_dfs(int node) {
    V[node] = ++cnt, S[node] = 1;
    for (int i : adj[node])
        sz_dfs(i), S[node] += S[i];
}

void dfs(int node) {
    for (int i = 0; i <= K; i++) {
        dp[V[node] + S[node]][i] = max(dp[V[node] + S[node]][i], dp[V[node]][i]);
        if (i + 1 <= K)
            dp[V[node] + 1][i + 1] = max(dp[V[node] + 1][i + 1], dp[V[node]][i]);
        if (i + C[node] <= K)
            dp[V[node] + 1][i + C[node]] = max(dp[V[node] + 1][i + C[node]], dp[V[node]][i] + P[node]);
    }

    for (int i : adj[node])
        dfs(i);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X;

    cin >> N >> K;
    for (int i = 2; i <= N; i++) {
        cin >> X, adj[X].emplace_back(i);
        fill(dp[i], dp[i] + K + 1, -INF);
    }

    for (int i = 1; i <= N; i++)
        cin >> P[i];
    for (int i = 1; i <= N; i++)
        cin >> C[i];

    sz_dfs(1), dfs(1);
    cout << dp[N + 1][K] << '\n';

    return 0;
}