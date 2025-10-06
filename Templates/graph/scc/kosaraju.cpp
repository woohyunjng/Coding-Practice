vector<int> adj[MAX], rev[MAX], scc[MAX], st;
bool chk[MAX];
int cnt = 0, grp[MAX];

void dfs1(int node) {
    chk[node] = true;
    for (int i : adj[node])
        if (!chk[i])
            dfs1(i);
    st.push(node);
}

void dfs2(int node) {
    chk[node] = true;
    for (int i : rev[node]) {
        if (!chk[i])
            dfs2(i);
    }
    scc[cnt].push_back(node), grp[node] = cnt;
}

void init() {
    int X;

    for (int i = 1; i <= N; i++)
        if (!chk[i])
            dfs1(i);

    fill(chk, chk + N + 1, false);
    while (!st.empty()) {
        X = st.back(), st.pop_back();
        if (!chk[X])
            dfs2(X), cnt++;
    }
}