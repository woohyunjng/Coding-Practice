#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;
typedef array<int, 3> tp;

const int MAX = 500001;
const int INF = 0x3f3f3f3f3f3f3f3f;

vector<pr> adj[MAX];
int dis[MAX][2];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, U, V, T, ans = 0;
    tp K;

    cin >> N >> M;
    while (M--) {
        cin >> U >> V >> T;
        adj[U].push_back({T, V}), adj[V].push_back({T, U});
    }

    priority_queue<tp, vector<tp>, greater<tp>> pq;
    for (int i = 2; i <= N; i++)
        dis[i][0] = dis[i][1] = INF;
    pq.push({0, 0, 1});

    while (!pq.empty()) {
        K = pq.top(), pq.pop();
        if (dis[K[2]][0] < K[0] || dis[K[2]][1] < K[1])
            continue;

        for (pr i : adj[K[2]]) {
            V = i[0] + K[0];
            if (V > dis[i[1]][0] || (V == dis[i[1]][0] && dis[i[1]][1] <= i[0]))
                continue;
            dis[i[1]][0] = V, dis[i[1]][1] = i[0], pq.push({dis[i[1]][0], dis[i[1]][1], i[1]});
        }
    }

    for (int i = 2; i <= N; i++)
        ans += dis[i][1];

    cout << ans << '\n';

    return 0;
}