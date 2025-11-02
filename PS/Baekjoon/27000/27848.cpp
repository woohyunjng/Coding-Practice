#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;
typedef array<int, 3> tp;

const int MAX = 200001;
const int INF = 0x3f3f3f3f3f3f3f3f;

int D[MAX], A[MAX];
vector<tp> adj[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X, Y, Z, W;

    cin >> N >> M, fill(D + 1, D + N + 1, INF);
    while (M--) {
        cin >> X >> Y >> Z >> W;
        adj[X].push_back({Z, Y, W});
    }

    for (int i = 1; i <= N; i++)
        cin >> A[i], sort(adj[i].begin(), adj[i].end(), [&](tp x, tp y) { return x[1] < y[1]; });

    priority_queue<pr, vector<pr>, greater<pr>> pq;
    pr K;
    tp V;

    pq.push({D[1] = 0, 1});
    while (!pq.empty()) {
        K = pq.top(), pq.pop();
        if (D[K[1]] < K[0])
            continue;
        X = K[0] + (K[1] == 1 ? 0 : A[K[1]]);

        while (!adj[K[1]].empty() && adj[K[1]].back()[1] >= X) {
            V = adj[K[1]].back(), adj[K[1]].pop_back();
            if (D[V[0]] <= V[2])
                continue;
            pq.push({D[V[0]] = V[2], V[0]});
        }
    }

    for (int i = 1; i <= N; i++)
        cout << (D[i] == INF ? -1 : D[i]) << '\n';

    return 0;
}