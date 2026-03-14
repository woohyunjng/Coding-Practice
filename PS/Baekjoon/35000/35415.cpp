#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

const int MAX = 100001;
const int INF = 0x3f3f3f3f3f3f3f3f;

int D[3][MAX];
vector<pr> adj[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, K, T, U, V, W, ans = INF;

    cin >> N >> M >> K >> T;
    while (M--) {
        cin >> U >> V >> W;
        adj[U].push_back({V, W}), adj[V].push_back({U, W});
    }

    priority_queue<pr, vector<pr>, greater<pr>> pq;
    pr X;

    for (int t = 0; t < 3; t++) {
        fill(D[t], D[t] + N + 1, INF);
        U = (t == 0 ? 1 : (t == 1 ? K : N));

        D[t][U] = 0, pq.push({0, U});
        while (!pq.empty()) {
            X = pq.top(), pq.pop();
            if (D[t][X[1]] ^ X[0])
                continue;

            for (pr i : adj[X[1]]) {
                if (D[t][i[0]] > X[0] + i[1])
                    D[t][i[0]] = X[0] + i[1], pq.push({D[t][i[0]], i[0]});
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        if (D[0][i] == INF || D[1][i] == INF || D[2][i] == INF)
            continue;
        if (D[1][i] > T)
            continue;
        ans = min(ans, D[0][i] + (i == K ? 0 : T) + D[2][i]);
    }

    cout << (ans == INF ? -1 : ans) << '\n';

    return 0;
}