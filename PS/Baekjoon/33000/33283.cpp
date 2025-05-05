#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 200001;
const int MAX_LOG = 20;

int uf[MAX], parent[MAX][MAX_LOG], depth[MAX];
vector<int> adj[MAX];

int find(int X) { return X == uf[X] ? X : uf[X] = find(uf[X]); }
void uni(int X, int Y) {
    X = find(X), Y = find(Y);
    if (X != Y)
        uf[max(X, Y)] = min(X, Y);
}

void dfs(int node, int par) {
    depth[node] = depth[par] + 1, parent[node][0] = par;
    for (int i = 1; i < MAX_LOG; i++)
        parent[node][i] = parent[parent[node][i - 1]][i - 1];

    for (int i : adj[node]) {
        if (i == par)
            continue;
        dfs(i, node);
    }
}

int lca(int X, int Y) {
    if (depth[X] < depth[Y])
        swap(X, Y);

    int diff = depth[X] - depth[Y];

    for (int i = 0; i < MAX_LOG; i++) {
        if (diff & 1)
            X = parent[X][i];
        diff >>= 1;
    }

    for (int i = MAX_LOG - 1; i >= 0; i--) {
        if (parent[X][i] != parent[Y][i])
            X = parent[X][i], Y = parent[Y][i];
    }

    if (X != Y)
        X = parent[X][0];
    return X;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, Q, X, Y;

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        uf[i] = i;

    while (M--) {
        cin >> X >> Y;
        if (find(X) == find(Y))
            continue;
        uni(X, Y), adj[X].push_back(Y), adj[Y].push_back(X);
    }

    dfs(1, 0);

    cin >> Q;
    while (Q--) {
        cin >> X >> Y;
        cout << depth[X] + depth[Y] - 2 * depth[lca(X, Y)] - 1 << '\n';
    }

    return 0;
}