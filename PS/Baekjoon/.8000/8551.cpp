#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef array<int, 2> pr;

const int MAX = 1000001;

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

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, U, V, ans = 0;
    queue<int> q;

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> U >> V;
        adj[U].push_back({V, i << 1}), adj[V].push_back({U, i << 1 | 1});
        cap[i << 1] = 1;
    }

    while (true) {
        fill(dis, dis + N + 1, -1), fill(work, work + N + 1, 0);

        q.push(1), dis[1] = 0;
        while (!q.empty()) {
            V = q.front(), q.pop();
            for (pr i : adj[V]) {
                if (dis[i[0]] != -1 || cap[i[1]] == flow[i[1]])
                    continue;
                q.push(i[0]), dis[i[0]] = dis[V] + 1;
            }
        }
        if (dis[N] == -1)
            break;

        while (true) {
            V = dfs(1, N, MAX);
            if (!V)
                break;
            ans += V;
        }
    }

    cout << ans << '\n';

    return 0;
}