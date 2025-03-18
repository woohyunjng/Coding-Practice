#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<vector<int>, 2> knapsack_dp;

const int MAX = 310;

vector<int> adj[MAX];
int M, S[MAX], P[MAX], sz[MAX];

void hld(int node, int par) {
    sz[node] = 1;
    for (int &i : adj[node]) {
        if (i == par)
            continue;
        hld(i, node), sz[node] += sz[i];
        if (adj[node][0] == par || sz[adj[node][0]] < sz[i])
            swap(adj[node][0], i);
    }
}

knapsack_dp dfs(int node, int par, const vector<int> &dp) {
    vector<int> D = dp, E = dp;
    knapsack_dp res;

    if (!adj[node].empty() && adj[node][0] != par) {
        res = dfs(adj[node][0], node, dp);
        D = res[0], E = res[1];
    }

    for (int i = 1; i < adj[node].size(); i++) {
        if (adj[node][i] == par)
            continue;
        D = dfs(adj[node][i], node, D)[0], E = dfs(adj[node][i], node, E)[1];
    }

    for (int i = M; i >= 0; i--) {
        E[i] = D[i];
        if (i >= S[node])
            D[i] = max(D[i], E[i - S[node]] + P[node]);
    }

    return {D, E};
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, Y;

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        cin >> S[i] >> P[i];

    for (int i = 1; i < N; i++) {
        cin >> X >> Y;
        adj[X].push_back(Y), adj[Y].push_back(X);
    }

    hld(1, -1);

    knapsack_dp res = dfs(1, -1, vector<int>(M + 1, 0));
    cout << res[0][M] << '\n';

    return 0;
}