#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

const int MAX = 50001;
const int MAX_K = 11;
const int INF = 0x3f3f3f3f3f3f3f3f;

int A[MAX_K], C[MAX][MAX_K], dis[MAX_K], assign[MAX], track[MAX_K];
bool vst[MAX_K];

vector<pr> adj[MAX_K];
priority_queue<pr, vector<pr>, greater<pr>> pq, cost[MAX_K][MAX_K];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, X, ans = 0, val, ps;
    queue<int> q;
    vector<int> path;

    cin >> N >> K;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= K; j++)
            cin >> C[i][j];
    for (int i = 1; i <= K; i++)
        cin >> A[i];

    for (int i = 1; i <= N; i++) {
        path.clear();
        for (int j = 0; j <= K; j++)
            adj[j].clear();

        for (int j = 1; j <= K; j++) {
            if (A[j] > 0)
                continue;
            for (int k = 1; k <= K; k++) {
                while (!cost[j][k].empty() && assign[cost[j][k].top()[1]] != j)
                    cost[j][k].pop();
                if (cost[j][k].empty())
                    continue;
                adj[j].push_back({cost[j][k].top()[0], k});
            }
        }
        for (int j = 1; j <= K; j++)
            adj[0].push_back({C[i][j], j});

        fill(dis, dis + K + 1, INF), val = INF, ps = -1;

        q.push(0), dis[0] = 0;
        while (!q.empty()) {
            X = q.front(), q.pop(), vst[X] = false;
            for (pr j : adj[X]) {
                if (dis[X] + j[0] < dis[j[1]]) {
                    dis[j[1]] = dis[X] + j[0], track[j[1]] = X;
                    if (!vst[j[1]])
                        vst[j[1]] = true, q.push(j[1]);
                }
            }
        }

        for (int i = 1; i <= K; i++) {
            if (A[i] > 0 && val > dis[i])
                val = dis[i], ps = i;
        }
        ans += val;

        while (ps != 0)
            path.push_back(ps), ps = track[ps];
        path.push_back(0), reverse(path.begin(), path.end());

        A[path.back()]--;
        for (int j = 0; j + 1 < path.size(); j++) {
            X = j == 0 ? i : cost[path[j]][path[j + 1]].top()[1];
            assign[X] = path[j + 1];

            for (int k = 1; k <= K; k++)
                cost[path[j + 1]][k].push({C[X][k] - C[X][path[j + 1]], X});
        }
    }

    cout << ans << '\n';

    return 0;
}