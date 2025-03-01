#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 600000;
const int MAX_LOG = 20;

int V[MAX], sz[MAX], sm[MAX][2], depth[MAX], parent[MAX][MAX_LOG];
vector<int> adj[MAX];

void dfs(int node, int par) {
    depth[node] = depth[par] + 1, sz[node] = 1;
    sm[node][0] = V[node] * depth[node], sm[node][1] = V[node];

    parent[node][0] = par;
    for (int i = 1; i < MAX_LOG; i++)
        parent[node][i] = parent[parent[node][i - 1]][i - 1];

    for (int i : adj[node]) {
        dfs(i, node);
        sz[node] += sz[i];
        sm[node][0] += sm[i][0], sm[node][1] += sm[i][1];
    }
}

int up(int X, int K) {
    for (int i = 0; K; i++) {
        if (K & 1)
            X = parent[X][i];
        K >>= 1;
    }
    return X;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, X, Y, Z, K;

    cin >> N >> Q;
    for (int i = 1; i <= N; i++)
        cin >> V[i];

    for (int i = 2; i <= N; i++)
        cin >> X, adj[X].push_back(i);

    dfs(1, 0);

    while (Q--) {
        cin >> X >> Y;
        K = sm[Y][0] - depth[Y] * sm[Y][1] - (depth[X] - depth[Y]) * V[X] + V[X];
        Z = up(X, depth[X] - depth[Y] - 1), K += sm[Z][1] - sm[X][1];
        cout << K << '\n';
    }

    return 0;
}