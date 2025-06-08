int D[MAX], cnt;
bool vst[MAX];
vector<int> adj[MAX], rvt_adj[MAX], st;

void dfs1(int node) {
    vst[node] = true;
    for (int i : adj[node])
        if (!vst[i])
            dfs1(i);
    st.push_back(node);
}

void dfs2(int node) {
    D[node] = cnt;
    for (int i : rvt_adj[node])
        if (!D[i])
            dfs2(i);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X, Y;
    bool flag = true;

    cin >> N >> M;
    while (M--) {
        cin >> X >> Y;
        X = X < 0 ? -(X + 1) * 2 + 1 : (X - 1) * 2, Y = Y < 0 ? -(Y + 1) * 2 + 1 : (Y - 1) * 2;
        adj[X ^ 1].push_back(Y), adj[Y ^ 1].push_back(X);
        rvt_adj[Y].push_back(X ^ 1), rvt_adj[X].push_back(Y ^ 1);
    }

    for (int i = 0; i < N << 1; i++)
        if (!vst[i])
            dfs1(i);

    while (!st.empty()) {
        X = st.back(), st.pop_back();
        if (!D[X])
            cnt++, dfs2(X);
    }

    for (int i = 0; i < N; i++)
        flag &= D[i << 1] != D[i << 1 | 1];

    if (!flag)
        cout << 0 << '\n';
    else {
        cout << 1 << '\n';
        for (int i = 0; i < N; i++)
            cout << (D[i << 1] > D[i << 1 | 1]) << ' ';
        cout << '\n';
    }
}