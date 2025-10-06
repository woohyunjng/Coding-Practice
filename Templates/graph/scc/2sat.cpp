int D[MAX], cnt;
bool vst[MAX];
vector<int> adj[MAX], rev[MAX], st;

void dfs1(int node) {
    vst[node] = true;
    for (int i : adj[node])
        if (!vst[i])
            dfs1(i);
    st.push_back(node);
}

void dfs2(int node) {
    D[node] = cnt;
    for (int i : rev[node])
        if (!D[i])
            dfs2(i);
}

void add(int X, int Y) { // X or Y (X, Y가 음수면 not)
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X, Y;

    X = X < 0 ? -(X + 1) << 1 | 1 : (X - 1) << 1, Y = Y < 0 ? -(Y + 1) << 1 | 1 : (Y - 1) << 1;
    adj[X ^ 1].push_back(Y), adj[Y ^ 1].push_back(X);
    rev[Y].push_back(X ^ 1), rev[X].push_back(Y ^ 1);
}

void init() {
    for (int i = 0; i < N << 1; i++)
        if (!vst[i])
            dfs1(i);

    while (!st.empty()) {
        X = st.back(), st.pop_back();
        if (!D[X])
            cnt++, dfs2(X);
    }

    bool flag = true;
    for (int i = 0; i < N; i++)
        flag &= D[i << 1] != D[i << 1 | 1]; // flag -> 모순 판별

    for (int i = 0; i < N; i++)
        D[i << 1] > D[i << 1 | 1] // D[i<<1] > D[i<<1|1] -> true
}