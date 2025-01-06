#include <bits/stdc++.h>
#define int long long

#define MAX 20
#define INF 0x7f7f7f7f7f7f7f7f

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

vector<pr> adj[MAX];
int D[MAX], dis[MAX][1 << MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, K, A, B, C;
    tp X;
    priority_queue<tp, vector<tp>, greater<tp>> pq;

    cin >> N >> M >> K;

    while (M--) {
        cin >> A >> B >> C;
        adj[A].push_back({C, B}), adj[B].push_back({C, A});
    }

    for (int i = 0; i < K; i++)
        cin >> D[i];

    for (int i = 1; i <= N; i++) {
        fill(&dis[0][0], &dis[MAX][0], INF);
        dis[i][0] = 0, pq.push({0, i, 0});

        while (!pq.empty()) {
            X = pq.top(), pq.pop();
            if (dis[X[1]][X[2]] < X[0])
                continue;

            for (pr j : adj[X[1]]) {
                if (dis[j.second][X[2]] > dis[X[1]][X[2]] + j.first) {
                    dis[j.second][X[2]] = dis[X[1]][X[2]] + j.first;
                    pq.push({-dis[j.second][X[2]], j.second, X[2]});
                }
                if (X[2] < K && dis[j.second][X[2] + 1] > dis[X[1]][X[2]]) {
                    dis[j.second][X[2] + 1] = dis[X[1]][X[2]];
                    pq.push({-dis[j.second][X[2] + 1], j.second, X[2] + 1});
                }
            }
        }
    }

    return 0;
}