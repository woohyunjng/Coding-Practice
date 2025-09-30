#include <bits/stdc++.h>
using namespace std;

typedef array<int, 2> pr;

const int MAX = 101;

int V[MAX], in[MAX];
vector<pr> adj[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X, Y, Z;

    cin >> N >> M;
    while (M--) {
        cin >> X >> Y >> Z;
        adj[X].push_back({Y, Z}), in[Y]++;
    }

    queue<int> q;
    q.push(N), V[N] = 1;

    while (!q.empty()) {
        X = q.front(), q.pop();

        for (pr i : adj[X]) {
            V[i[0]] += V[X] * i[1];
            if (--in[i[0]] == 0)
                q.push(i[0]);
        }
    }

    for (int i = 1; i <= N; i++)
        if (adj[i].empty())
            cout << i << ' ' << V[i] << '\n';

    return 0;
}