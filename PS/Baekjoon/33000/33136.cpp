#include <bits/stdc++.h>
using namespace std;

typedef array<int, 2> pr;

const int MAX = 200001;

vector<pr> adj[MAX];
vector<int> ans;

int D[MAX], parent[MAX][2], ansX, ansY, ansZ, ansD;

void dfs(int node, int par) {
    for (pr i : adj[node]) {
        if (i[0] == par || D[i[0]] > D[node])
            continue;
        if (D[i[0]] == 0) {
            D[i[0]] = D[node] + 1, parent[i[0]][0] = node, parent[i[0]][1] = i[1];
            dfs(i[0], node);
        } else if (D[i[0]] < D[node] && ansD < D[i[0]])
            ansD = D[i[0]], ansX = node, ansY = i[0], ansZ = i[1];
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X, Y;

    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        cin >> X >> Y;
        adj[X].push_back({Y, i}), adj[Y].push_back({X, i});
    }

    D[1] = 1, dfs(1, 0);

    ans.push_back(ansZ);
    while (ansX != ansY)
        ans.push_back(parent[ansX][1]), ansX = parent[ansX][0];

    cout << ans.size() << '\n';
    for (int i : ans)
        cout << i << ' ';
    cout << '\n';

    return 0;
}