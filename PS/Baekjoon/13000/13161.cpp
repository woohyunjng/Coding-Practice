#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef array<int, 2> pr;

const int MAX = 500001;
const int INF = 1'000'000'000'000;

int flow[MAX], cap[MAX], G[MAX][2],
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

    int N, U, V, cnt = 0, ans = 0;
    queue<int> q;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> V;
        if (V == 1) {
            adj[0].push_back({i, cnt << 1}), adj[i].push_back({0, cnt << 1 | 1});
            cap[cnt << 1] = INF, cnt++;
        } else if (V == 2) {
            adj[i].push_back({N + 1, cnt << 1}), adj[N + 1].push_back({i, cnt << 1 | 1});
            cap[cnt << 1] = INF, cnt++;
        }
    }

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++) {
            cin >> U;
            if (i >= j)
                continue;
            adj[i].push_back({j, cnt << 1}), adj[j].push_back({i, cnt << 1 | 1});
            cap[cnt << 1] = U, cap[cnt << 1 | 1] = U, cnt++;
        }

    while (true) {
        fill(dis, dis + N + 2, -1), fill(work, work + N + 2, 0);

        q.push(0), dis[0] = 0;
        while (!q.empty()) {
            V = q.front(), q.pop();
            for (pr i : adj[V]) {
                if (dis[i[0]] != -1 || cap[i[1]] == flow[i[1]])
                    continue;
                q.push(i[0]), dis[i[0]] = dis[V] + 1;
            }
        }
        if (dis[N + 1] == -1)
            break;

        while (true) {
            V = dfs(0, N + 1, INF);
            if (!V)
                break;
            ans += V;
        }
    }

    cout << ans << '\n';

    fill(work, work + N + 2, 0);

    q.push(0), work[0] = 1;
    while (!q.empty()) {
        V = q.front(), q.pop();
        for (pr i : adj[V]) {
            if (work[i[0]] || cap[i[1]] == flow[i[1]])
                continue;
            q.push(i[0]), work[i[0]] = 1;
        }
    }

    for (int i = 1; i <= N; i++)
        if (work[i])
            cout << i << ' ';
    cout << '\n';
    for (int i = 1; i <= N; i++)
        if (!work[i])
            cout << i << ' ';
    cout << '\n';

    return 0;
}