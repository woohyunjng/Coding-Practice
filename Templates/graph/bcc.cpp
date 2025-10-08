void dfs(int node, int par) {
    int X;

    vst[node] = true, parent[node] = par;
    for (int i : adj[node]) {
        if (i == par)
            continue;

        if (!vst[i])
            depth[i] = depth[node] + 1, dfs(i, node);
        else if (depth[i] < depth[node]) {
            X = node;
            while (find(X) != find(i))
                uni(X, parent[X]), X = find(X);
        }
    }
}
