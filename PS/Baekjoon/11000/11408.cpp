#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

const int MAX = 401;
const int INF = 0x3f3f3f3f3f3f3f3f;

// O(VE^2) Edmonds-Karp

int flow[MAX], cap[MAX], par[MAX], cost[MAX], dis[MAX], G[MAX][2];
bool chk[MAX];
vector<pr> adj[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, K, X, Y, cnt = 0, ans_f = 0, ans_c = 0;
    queue<int> q;

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> K;
        while (K--) {
            cin >> X >> Y;
            adj[i].push_back({X + N, cnt << 1}), adj[X + N].push_back({i, cnt << 1 | 1});
            G[cnt][0] = i, G[cnt][1] = X + N;
            cap[cnt << 1] = 1, cost[cnt << 1] = Y, cost[cnt << 1 | 1] = -Y, cnt++;
        }

        adj[0].push_back({i, cnt << 1}), adj[i].push_back({0, cnt << 1 | 1});
        G[cnt][0] = 0, G[cnt][1] = i;
        cap[cnt << 1] = 1, cnt++;
    }

    for (int i = 1; i <= M; i++) {
        adj[i + N].push_back({N + M + 1, cnt << 1}), adj[N + M + 1].push_back({i + N, cnt << 1 | 1});
        G[cnt][0] = i + N, G[cnt][1] = N + M + 1;
        cap[cnt << 1] = 1, cnt++;
    }

    while (true) {
        for (int i = 1; i <= N + M + 1; i++)
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

        if (par[N + M + 1] == -1)
            break;

        X = INF;
        for (Y = N + M + 1; Y != 0; Y = G[par[Y] >> 1][par[Y] & 1])
            X = min(X, cap[par[Y]] - flow[par[Y]]);
        for (Y = N + M + 1; Y != 0; Y = G[par[Y] >> 1][par[Y] & 1])
            flow[par[Y]] += X, flow[par[Y] ^ 1] -= X;
        ans_f += X, ans_c += dis[N + M + 1] * X;
    }

    cout << ans_f << '\n';
    cout << ans_c << '\n';

    return 0;
}