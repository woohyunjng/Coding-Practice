#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

const int MAX = 300001;
const int INF = 0x3f3f3f3f3f3f3f3f;

int X[MAX], Y[MAX], C[MAX], dis[MAX];
vector<pr> adj[MAX];
map<pr, int> mp, F;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int M, N, K, V, W, A, B, D, ans = INF;

    cin >> M >> N >> K;
    cin >> V >> W, X[0] = -1, Y[0] = V;

    for (int i = 1; i <= M; i++) {
        cin >> X[i] >> Y[i] >> C[i];
        adj[X[i]].push_back({Y[i], i});
        if (mp.find({X[i], Y[i]}) == mp.end())
            mp[{X[i], Y[i]}] = i;
        else if (C[mp[{X[i], Y[i]}]] > C[i])
            mp[{X[i], Y[i]}] = i;
        else
            C[i] = INF;
    }

    while (K--) {
        cin >> A >> B >> D;
        F[{mp[{A, B}], mp[{B, D}]}] = 1;
    }

    priority_queue<pr, vector<pr>, greater<pr>> pq;
    pr P;

    fill(dis, dis + M + 1, INF);

    pq.push({0, 0}), dis[0] = 0;
    while (!pq.empty()) {
        P = pq.top(), pq.pop();
        if (P[0] > dis[P[1]])
            continue;

        for (pr i : adj[Y[P[1]]]) {
            if (F[{P[1], i[1]}])
                continue;
            A = P[0] + C[i[1]];
            if (A < dis[i[1]])
                pq.push({A, i[1]}), dis[i[1]] = A;
        }
    }

    for (int i = 0; i <= M; i++) {
        if (Y[i] != W)
            continue;
        ans = min(ans, dis[i]);
    }

    cout << (ans == INF ? -1 : ans) << '\n';

    return 0;
}