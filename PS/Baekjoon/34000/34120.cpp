#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;
typedef array<int, 3> tp;

const int MAX = 2001;
const int INF = 0x3f3f3f3f3f3f3f3f;

vector<pr> adj[MAX];
int dis[MAX][MAX], C[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X, Y, T, A, B, D, ans = INF;

    priority_queue<tp, vector<tp>, greater<tp>> pq;
    tp K;

    cin >> N >> M;
    while (M--) {
        cin >> X >> Y >> T;
        adj[X].push_back({T, Y});
    }
    for (int i = 1; i <= N; i++)
        cin >> C[i], fill(dis[i], dis[i] + N + 1, INF);
    cin >> A >> B;

    pq.push({0, 1, 1}), dis[1][1] = 0;

    while (!pq.empty()) {
        K = pq.top(), pq.pop();
        T = K[0], X = K[1], Y = K[2];
        if (T > dis[X][Y])
            continue;

        for (pr i : adj[Y]) {
            D = i[0] + T;
            if (D % (A + B) > A || T / (A + B) != D / (A + B))
                continue;
            if (D < dis[X][i[1]])
                dis[X][i[1]] = D, pq.push({D, X, i[1]});
            D = (dis[X][i[1]] / (A + B) + 1) * (A + B);
            if (!C[i[1]] && D < dis[i[1]][i[1]])
                dis[i[1]][i[1]] = D, pq.push({D, i[1], i[1]});
        }
    }

    for (int i = 1; i <= N; i++)
        ans = min(ans, dis[i][N]);
    cout << (ans == INF ? -1 : ans) << '\n';

    return 0;
}