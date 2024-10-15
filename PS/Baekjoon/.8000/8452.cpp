#include <bits/stdc++.h>

#define int long long
#define MAX 201000

using namespace std;

vector<int> adj[MAX];
int dis[MAX], adj_q[MAX][2], query[MAX][2], ans[MAX];
bool deleted[MAX];

void bfs(int K) {
    queue<int> q;
    q.push(K);

    if (dis[K] == -1)
        return;

    while (!q.empty()) {
        K = q.front(), q.pop();

        for (int i : adj[K]) {
            if (dis[i] == -1 || dis[i] > dis[K] + 1) {
                dis[i] = dis[K] + 1;
                q.push(i);
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, Q, K;
    char T;
    cin >> N >> M >> Q;

    for (int i = 1; i <= M; i++)
        cin >> adj_q[i][0] >> adj_q[i][1];

    for (int i = 1; i <= Q; i++) {
        cin >> T >> query[i][1];
        if (T == 'U') {
            query[i][0] = 1;
            deleted[query[i][1]] = true;
        } else
            query[i][0] = 2;
    }

    for (int i = 1; i <= M; i++) {
        if (!deleted[i])
            adj[adj_q[i][0]].push_back(adj_q[i][1]);
    }

    queue<int> q;
    fill(dis, dis + N + 1, -1);

    dis[1] = 0;
    bfs(1);

    for (int i = Q; i >= 1; i--) {
        if (query[i][0] == 1) {
            K = adj_q[query[i][1]][0];
            adj[K].push_back(adj_q[query[i][1]][1]);
            bfs(K);
        } else
            ans[i] = dis[query[i][1]];
    }

    for (int i = 1; i <= Q; i++) {
        if (query[i][0] == 2)
            cout << ans[i] << '\n';
    }

    return 0;
}