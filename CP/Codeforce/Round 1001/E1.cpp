#include <bits/stdc++.h>
#define int long long

#define MAX 500000
#define MAX_LOG 23
using namespace std;

typedef array<int, 2> pr;

int W[MAX], parent[MAX][MAX_LOG], depth[MAX], mx[MAX];
vector<int> adj[MAX], arr[MAX];

void dfs(int node, int par) {
    parent[node][0] = par, depth[node] = depth[par] + 1;
    for (int i = 1; i < MAX_LOG; i++)
        parent[node][i] = parent[parent[node][i - 1]][i - 1];

    for (int i : adj[node]) {
        if (i == par)
            continue;
        dfs(i, node);
    }
}

int lca(int x, int y) {
    if (depth[x] < depth[y])
        swap(x, y);
    int diff = depth[x] - depth[y];
    for (int i = 0; diff; i++) {
        if (diff & 1)
            x = parent[x][i];
        diff >>= 1;
    }

    for (int i = MAX_LOG - 1; i >= 0; i--) {
        if (parent[x][i] != parent[y][i])
            x = parent[x][i], y = parent[y][i];
    }
    if (x != y)
        x = parent[x][0];

    return x;
}

void solve() {
    int N, X = 0, Y, res = 0;
    pr A, B;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> W[i], arr[W[i]].push_back(i);

    for (int i = 1; i < N; i++) {
        cin >> X >> Y;
        adj[X].push_back(Y), adj[Y].push_back(X);
    }

    dfs(1, 0);

    for (int i = 1; i <= N; i++) {
        if (arr[i].size() == 0)
            continue;
        mx[i] = arr[i][0];
        for (int j = 1; j < arr[i].size(); j++)
            mx[i] = lca(mx[i], arr[i][j]);
    }

    X = 0;
    for (int i = N; i >= 1; i--) {
        if (arr[i].size() == 0)
            continue;
        if (X == 0) {
            X = mx[i];
            continue;
        }

        for (int j : arr[i])
            if (lca(X, j) != j && res == 0)
                res = j;
        X = lca(X, mx[i]);
    }

    cout << res << '\n';

    for (int i = 1; i <= N; i++) {
        adj[i].clear(), arr[i].clear(), mx[i] = 0, depth[i] = 0;
        for (int j = 0; j < MAX_LOG; j++)
            parent[i][j] = 0;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;

    while (T--)
        solve();

    return 0;
}