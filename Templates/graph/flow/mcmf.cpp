// O(Ef) SPFA MCMF

int flow[MAX], cap[MAX], par[MAX], cost[MAX], dis[MAX], G[MAX][2];
bool chk[MAX];
vector<pr> adj[MAX];

void init() {
    int S, E, X, Y, cnt = 0, res_f = 0, res_c = 0;
    queue<int> q;

    while (true) {
        for (int i = 1; i <= E + 1; i++)
            dis[i] = INF, chk[i] = false, par[i] = -1;

        q.push(S), dis[S] = 0, chk[S] = true;
        while (!q.empty()) {
            X = q.front(), q.pop();
            chk[X] = false;

            for (pr i : adj[X]) {
                if (flow[i[1]] == cap[i[1]] || dis[X] + cost[i[1]] >= dis[i[0]])
                    continue;
                dis[i[0]] = dis[X] + cost[i[1]], par[i[0]] = i[1];
                if (!chk[i[0]])
                    q.push(i[0]), chk[i[0]] = true;
            }
        }

        if (par[E] == -1)
            break;

        X = INF;
        for (Y = E; Y != S; Y = G[par[Y] >> 1][par[Y] & 1])
            X = min(X, cap[par[Y]] - flow[par[Y]]);
        for (Y = E; Y != S; Y = G[par[Y] >> 1][par[Y] & 1])
            flow[par[Y]] += X, flow[par[Y] ^ 1] -= X;
        res_f += X, res_c += dis[E] * X;
    }

    return 0;
}