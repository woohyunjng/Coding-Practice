// O(VE^2) Edmonds-Karp

int flow[MAX], cap[MAX], par[MAX], G[MAX][2];
vector<pr> adj[MAX];

void init() {
    int U, V, res = 0, S, E;
    queue<int> q;

    for (int i = 0; i < M; i++) {
        cin >> U >> V;
        adj[U].push_back({V, i << 1}), adj[V].push_back({U, i << 1 | 1});
        cap[i << 1] = 1, G[i][0] = U, G[i][1] = V;
    }

    while (true) {
        fill(par + 1, par + N + 1, -1);

        q.push(S), par[S] = 0;
        while (!q.empty()) {
            V = q.front(), q.pop();
            for (pr i : adj[V]) {
                if (par[i[0]] != -1 || flow[i[1]] == cap[i[1]])
                    continue;
                q.push(i[0]), par[i[0]] = i[1];
            }
        }
        if (par[E] == -1)
            break;

        U = INF;
        for (V = E; V != S; V = G[par[V] >> 1][par[V] & 1])
            U = min(U, cap[par[V]] - flow[par[V]]);
        for (V = E; V != S; V = G[par[V] >> 1][par[V] & 1])
            flow[par[V]] += U, flow[par[V] ^ 1] -= U;
        res += U;
    }
}