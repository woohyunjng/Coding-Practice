#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;

const int MAX = 200000;

vector<pr> adj[MAX];
vector<int> num[MAX], dfs_adj[MAX], tree_adj[MAX], arr;

int depth[MAX], parent_edge[MAX], parent[MAX], color[MAX];
bool vst[MAX];

void dfs(int node, int par, int edge) {
    vst[node] = true, depth[node] = depth[par] + 1, parent_edge[node] = edge, parent[node] = par;
    for (pr i : adj[node]) {
        if (vst[i[0]])
            continue;
        dfs_adj[node].push_back(i[0]), dfs(i[0], node, i[1]);
    }
}

void tree_dfs(int node) {
    int X;
    for (pr i : adj[node]) {
        if (depth[i[0]] < depth[node] || parent_edge[i[0]] == i[1])
            continue;
        X = i[0];
        while (color[X] != color[node])
            color[X] = color[node], X = parent[X];
    }
    for (int i : dfs_adj[node])
        tree_dfs(i);
}

void leaf_dfs(int node, int par) {
    if (tree_adj[node].size() == 1)
        arr.push_back(num[node][0]);
    for (int i : tree_adj[node]) {
        if (i == par)
            continue;
        leaf_dfs(i, node);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X, Y;
    cin >> N >> M;

    for (int i = 1; i <= M; i++) {
        cin >> X >> Y;
        adj[X].push_back({Y, i}), adj[Y].push_back({X, i});
    }

    for (int i = 1; i <= N; i++)
        color[i] = i;

    dfs(1, 0, 0), tree_dfs(1);

    for (int i = 1; i <= N; i++) {
        num[color[i]].push_back(i);
        for (pr j : adj[i]) {
            if (color[i] == color[j[0]])
                continue;
            tree_adj[color[i]].push_back(color[j[0]]);
        }
    }

    leaf_dfs(1, 0);

    cout << (arr.size() + 1) / 2 << '\n';
    for (int i = 0; i < arr.size() / 2; i++)
        cout << arr[i] << ' ' << arr[i + arr.size() / 2] << '\n';
    if (arr.size() % 2)
        cout << arr[0] << ' ' << arr[arr.size() - 1] << '\n';

    return 0;
}