// O(V^2 * E) Dinic

int flow[MAX], cap[MAX],
    work[MAX], dis[MAX];
vector<pr> adj[MAX];

int dfs(int node, int E, int val) {
    if (node == E)
        return val;

    pr X;
    int F;

    for (int &i = work[node]; i < adj[node].size(); i++) {
        X = adj[node][i];
        if (dis[X[0]] != dis[node] + 1 || cap[X[1]] == flow[X[1]])
            continue;
        F = dfs(X[0], E, min(val, cap[X[1]] - flow[X[1]]));
        if (F) {
            flow[X[1]] += F, flow[X[1] ^ 1] -= F;
            return F;
        }
    }
    return 0;
}

void init() {
    int U, V, res = 0, S, E;
    queue<int> q;

    for (int i = 0; i < M; i++) {
        cin >> U >> V;
        adj[U].push_back({V, i << 1}), adj[V].push_back({U, i << 1 | 1});
        cap[i << 1] = 1;
    }

    while (true) {
        fill(dis + 1, dis + N + 1, -1), fill(work + 1, work + N + 1, 0);

        q.push(S), dis[S] = 0;
        while (!q.empty()) {
            V = q.front(), q.pop();
            for (pr i : adj[V]) {
                if (dis[i[0]] != -1 || cap[i[1]] == flow[i[1]])
                    continue;
                q.push(i[0]), dis[i[0]] = dis[V] + 1;
            }
        }
        if (dis[E] == -1)
            break;

        while (true) {
            V = dfs(S, E, INF);
            if (!V)
                break;
            res += V;
        }
    }
}