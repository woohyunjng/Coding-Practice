#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

const int MAX = 200001;
const int INF = 0x3f3f3f3f3f3f3f3f;

// O(Ef) SPFA MCMF

int flow[MAX], cap[MAX], par[MAX], cost[MAX], dis[MAX], G[MAX][2], cnt;
bool chk[MAX];
vector<pr> adj[MAX];

void add_edge(int U, int V, int CP, int W) {
    adj[U].push_back({V, cnt << 1}), adj[V].push_back({U, cnt << 1 | 1});
    cap[cnt << 1] = CP, G[cnt][0] = U, G[cnt][1] = V;
    cost[cnt << 1] = W, cost[cnt << 1 | 1] = -W, cnt++;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, S, E, X, Y, U, V, W, res_f = 0, res_c = 0;
    queue<int> q;

    cin >> N >> M;

    while (M--) {
        cin >> W >> U >> V;
        add_edge(U << 1 | 1, V << 1, 1, W), add_edge(V << 1 | 1, U << 1, 1, W);
    }

    cin >> S >> E, add_edge(0, S << 1, 2, 0);
    for (int i = 1; i <= N; i++)
        add_edge(i << 1, i << 1 | 1, (i == S || i == E) ? 2 : 1, 0);

    while (true) {
        for (int i = 1; i <= (N << 1 | 1); i++)
            dis[i] = INF, chk[i] = false, par[i] = -1;

        q.push(0), dis[0] = 0, chk[0] = true;
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

        if (par[E << 1 | 1] == -1)
            break;

        X = INF;
        for (Y = E << 1 | 1; Y != 0; Y = G[par[Y] >> 1][par[Y] & 1])
            X = min(X, cap[par[Y]] - flow[par[Y]]);
        for (Y = E << 1 | 1; Y != 0; Y = G[par[Y] >> 1][par[Y] & 1])
            flow[par[Y]] += X, flow[par[Y] ^ 1] -= X;
        res_f += X, res_c += dis[E << 1 | 1] * X;
    }

    if (res_f < 2)
        cout << -1 << '\n';
    else
        cout << res_c << '\n';

    return 0;
}