int sz[MAX], in[MAX], parent[MAX], depth[MAX], top[MAX], cnt;
vector<int> adj[MAX];

void dfs1(int node, int par) {
    sz[node] = 1, parent[node] = par, depth[node] = depth[par] + 1;
    for (int &i : adj[node]) {
        if (i == par)
            continue;
        dfs1(i, node), sz[node] += sz[i];
        if (sz[i] > sz[adj[node][0]])
            swap(i, adj[node][0]);
    }
}

void dfs2(int node, int par) {
    in[node] = ++cnt;
    for (int i : adj[node]) {
        if (i == par)
            continue;
        top[i] = i == adj[node][0] ? top[node] : i;
        dfs2(i, node);
    }
}