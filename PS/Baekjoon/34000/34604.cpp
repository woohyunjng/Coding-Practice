#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;

vector<int> adj[MAX];
int sz[MAX], depth[MAX], col[MAX];

int dfs(int node, int par, int c) {
    int res = 0;
    sz[node] = 1, depth[node] = depth[par] + 1;
    col[node] = c;
    for (int i : adj[node]) {
        if (i == par)
            continue;
        if (depth[i] == 0)
            res += dfs(i, node, 1 - c), sz[node] += sz[i];
        else if (depth[i] < depth[node])
            res += (col[node] != col[i]);
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X, Y, val = 0;

    cin >> N >> M;
    while (M--) {
        cin >> X >> Y;
        adj[X].push_back(Y), adj[Y].push_back(X);
    }

    for (int i = 1; i <= N; i++) {
        if (sz[i])
            continue;
        val += dfs(i, 0, 0) + sz[i] - 1;
    }

    cout << val + 1 << '\n';

    return 0;
}