#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;
typedef array<int, 3> tp;

const int MAX = 500000;
const int INF = 0x3f3f3f3f3f3f3f3f;

int dis[MAX];
map<int, int> color[MAX];
map<pr, int> num;
vector<pr> adj[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, A, B, C, P, V;
    pr X;

    cin >> N >> M, V = N;

    while (M--) {
        cin >> A >> B >> C >> P;
        adj[A].push_back({P, B}), adj[B].push_back({P, A});
        color[A][C] += P, color[B][C] += P;

        if (num.find({A, C}) == num.end())
            num[{A, C}] = ++V;
        if (num.find({B, C}) == num.end())
            num[{B, C}] = ++V;

        adj[A].push_back({0, num[{B, C}]}), adj[num[{A, C}]].push_back({-P, B});
        adj[B].push_back({0, num[{A, C}]}), adj[num[{B, C}]].push_back({-P, A});
    }

    for (pair<pr, int> i : num) {
        X = i.first, A = i.second;
        adj[X[0]].push_back({0, A});
        for (pr &j : adj[A])
            j[0] += color[X[0]][X[1]];
    }

    priority_queue<pr, vector<pr>, greater<pr>> pq;
    pr K;

    fill(dis, dis + V + 1, INF);
    pq.push({0, 1}), dis[1] = 0;

    while (!pq.empty()) {
        K = pq.top(), pq.pop();
        if (dis[K[1]] < K[0])
            continue;

        for (pr i : adj[K[1]]) {
            if (dis[i[1]] > K[0] + i[0]) {
                dis[i[1]] = K[0] + i[0];
                pq.push({dis[i[1]], i[1]});
            }
        }
    }

    cout << (dis[N] == INF ? -1 : dis[N]) << '\n';

    return 0;
}