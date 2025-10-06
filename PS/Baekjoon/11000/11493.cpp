#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

using namespace std;

typedef array<int, 2> pr;

const int MAX_N = 501;
const int MAX = 600001;
const int INF = 1e9;

int D[MAX_N][MAX_N], A[MAX], B[MAX],
    flow[MAX], cap[MAX], par[MAX], cost[MAX], dis[MAX], G[MAX][2];
bool chk[MAX];
vector<pr> adj[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, M, X, Y, ans = 0, cnt, S, E;
    queue<int> q;
    vector<int> V[2];

    cin >> T;
    while (T--) {
        cin >> N >> M;
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                D[i][j] = i == j ? 0 : INF;

        while (M--) {
            cin >> X >> Y;
            D[X][Y] = D[Y][X] = 1;
        }

        for (int k = 1; k <= N; k++)
            for (int i = 1; i <= N; i++)
                for (int j = 1; j <= N; j++)
                    D[i][j] = min(D[i][j], D[i][k] + D[k][j]);

        for (int i = 1; i <= N; i++)
            cin >> A[i];
        for (int i = 1; i <= N; i++) {
            cin >> X;
            if (A[i] ^ X)
                V[X].push_back(i);
        }

        N = V[0].size();
        S = 0, E = N << 1 | 1, ans = cnt = 0;

        for (int i = 0; i <= (N << 1 | 1); i++)
            adj[i].reserve(N + 1);

        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++) {
                adj[i].push_back({j + N, cnt << 1}), adj[j + N].push_back({i, cnt << 1 | 1});
                cap[cnt << 1] = 1, cost[cnt << 1] = D[V[0][i - 1]][V[1][j - 1]], cost[cnt << 1 | 1] = -cost[cnt << 1];
                G[cnt][0] = i, G[cnt][1] = j + N, cnt++;
            }

        for (int i = 1; i <= N; i++) {
            adj[S].push_back({i, cnt << 1}), adj[i].push_back({S, cnt << 1 | 1});
            cap[cnt << 1] = 1;
            G[cnt][0] = S, G[cnt][1] = i, cnt++;

            adj[i + N].push_back({E, cnt << 1}), adj[E].push_back({i + N, cnt << 1 | 1});
            cap[cnt << 1] = 1;
            G[cnt][0] = i + N, G[cnt][1] = E, cnt++;
        }

        while (true) {
            for (int i = 0; i <= E; i++)
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
            ans += dis[E] * X;
        }

        cout << ans << '\n';

        V[0].clear(), V[1].clear();
        for (int i = 0; i <= (N << 1 | 1); i++)
            adj[i].clear();
        for (int i = 0; i <= (cnt << 1 | 1); i++)
            flow[i] = cap[i] = cost[i] = G[i][0] = G[i][1] = 0;
    }

    return 0;
}