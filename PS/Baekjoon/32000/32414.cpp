#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;

const int MAX = 1500000;

vector<pr> adj[MAX];
int V[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X, Y, Z;
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        cin >> V[i];

    while (M--) {
        cin >> X >> Y >> Z;
        adj[X].push_back({Z, Y}), adj[Y].push_back({Z, X});
    }

    priority_queue<pr> pq;
    pr P;

    for (int i = 1; i <= N; i++)
        pq.push({V[i], i});

    while (!pq.empty()) {
        P = pq.top(), pq.pop();
        if (V[P[1]] > P[0])
            continue;

        for (pr i : adj[P[1]]) {
            if (V[i[1]] < P[0] - i[0]) {
                V[i[1]] = P[0] - i[0];
                pq.push({V[i[1]], i[1]});
            }
        }
    }

    for (int i = 1; i <= N; i++)
        cout << V[i] << '\n';

    return 0;
}