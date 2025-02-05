#include <bits/stdc++.h>
#define int long long

#define MAX 200
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;
typedef array<int, 2> pr;

vector<pr> adj[MAX];
int dis[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, Y, M, ans = INF, ans_num = -1, val;
    priority_queue<pr, vector<pr>, greater<pr>> pq;
    pr K;

    while (true) {
        cin >> N, ans = INF, ans_num = -1;
        if (N == 0)
            break;

        for (int i = 1; i <= N; i++) {
            cin >> M, adj[i].clear();
            while (M--) {
                cin >> X >> Y;
                adj[i].push_back({Y, X});
            }
        }

        for (int i = 1; i <= N; i++) {
            fill(dis, dis + N + 1, INF), dis[i] = 0;
            pq.push({0, i});

            while (!pq.empty()) {
                K = pq.top(), pq.pop();
                if (dis[K[1]] < K[0])
                    continue;

                for (pr j : adj[K[1]]) {
                    if (dis[j[1]] > K[0] + j[0]) {
                        dis[j[1]] = K[0] + j[0];
                        pq.push({dis[j[1]], j[1]});
                    }
                }
            }

            val = 0;
            for (int j = 1; j <= N; j++) {
                if (dis[j] == INF)
                    val = -1;
                if (val != -1 && dis[j] > val)
                    val = dis[j];
            }

            if (val != -1 && val < ans)
                ans = val, ans_num = i;
        }

        if (ans == INF)
            cout << "disjoint\n";
        else
            cout << ans_num << ' ' << ans << '\n';
    }

    return 0;
}