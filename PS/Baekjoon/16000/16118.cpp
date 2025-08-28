#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;
typedef array<int, 3> tp;

const int MAX = 4001;
const int INF = 0x3f3f3f3f3f3f3f3f;

int dis[MAX][3];
vector<pr> adj[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, A, B, D, ans = 0;

    cin >> N >> M;
    while (M--) {
        cin >> A >> B >> D;
        adj[A].push_back({D, B}), adj[B].push_back({D, A});
    }

    for (int i = 1; i <= N; i++)
        fill(dis[i], dis[i] + 3, INF);

    priority_queue<tp, vector<tp>, greater<tp>> pq;
    tp K;

    pq.push({0, 1, 0}), pq.push({0, 1, 1});
    dis[1][0] = dis[1][1] = 0;

    while (!pq.empty()) {
        K = pq.top(), pq.pop();
        if (K[0] != dis[K[1]][K[2]])
            continue;

        for (pr i : adj[K[1]]) {
            if (K[2] == 0) {
                if (K[0] + i[0] < dis[i[1]][K[2]])
                    dis[i[1]][K[2]] = K[0] + i[0], pq.push({dis[i[1]][K[2]], i[1], K[2]});
            } else {
                if (K[0] + i[0] * (K[2] == 1 ? 1 : 4) < dis[i[1]][3 - K[2]])
                    dis[i[1]][3 - K[2]] = K[0] + i[0] * (K[2] == 1 ? 1 : 4), pq.push({dis[i[1]][3 - K[2]], i[1], 3 - K[2]});
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        if (dis[i][0] * 2 < min(dis[i][1], dis[i][2]))
            ans++;
    }

    cout << ans << '\n';

    return 0;
}