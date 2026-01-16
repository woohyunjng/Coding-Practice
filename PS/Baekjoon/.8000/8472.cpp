#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

const int INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 200001;

int A[MAX], flow[MAX], cap[MAX], par[MAX], cost[MAX], dis[MAX], G[MAX][2];
bool chk[MAX];
vector<pr> adj[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, X, Y, C = 0, ans = 0, S = 0, E;

    cin >> N >> K, E = N * 3 + 1;
    for (int i = 1; i <= N * 3; i++)
        cin >> A[i];

    for (int i = 1; i + 1 <= N * 3; i++) {
        adj[i].push_back({i + 1, C << 1}), adj[i + 1].push_back({i, C << 1 | 1});
        G[C][0] = i, G[C][1] = i + 1;
        cap[C << 1] = INF, C++;
    }

    for (int i = 1; i <= N * 3; i++) {
        X = min(N * 3 + 1, i + N);
        adj[i].push_back({X, C << 1}), adj[X].push_back({i, C << 1 | 1});
        G[C][0] = i, G[C][1] = X, cap[C << 1] = 1;
        cost[C << 1] = -A[i], cost[C << 1 | 1] = A[i], C++;
    }

    adj[0].push_back({1, C << 1}), adj[1].push_back({0, C << 1 | 1});
    G[C][0] = 0, G[C][1] = 1, cap[C << 1] = K, C++;

    queue<int> q;

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
        ans -= dis[E] * X;
    }

    cout << ans << '\n';

    return 0;
}