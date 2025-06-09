#include <bits/stdc++.h>
using namespace std;

typedef array<int, 3> tp;

const int MAX = 11;

int N, M, K, X, Y, Z;
bool vst[MAX];

vector<int> ans;
vector<tp> adj[MAX], edges;

void dfs(int node, int V, bool chk) {
    if (node == N && chk) {
        ans.push_back(V);
        return;
    }

    vst[node] = true;
    for (tp i : adj[node])
        if (!vst[i[0]])
            dfs(i[0], V + i[1], chk || i[2] == X);
    vst[node] = false;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> N >> M >> K;

    for (int i = 0; i < M; i++) {
        cin >> X >> Y >> Z;
        edges.push_back({X, Y, Z});
    }
    for (int i = 0; i < M; i++) {
        for (int j = 1; j <= N; j++)
            adj[j].clear();
        for (int j = 0; j < M; j++) {
            X = edges[j][0], Y = edges[j][1], Z = i == j ? edges[j][2] / 2 : edges[j][2];
            adj[X].push_back({Y, Z, j}), adj[Y].push_back({X, Z, j});
        }

        X = i, dfs(1, 0, false);
    }

    sort(ans.begin(), ans.end());
    if (ans.size() < K)
        cout << -1 << '\n';
    else
        cout << ans[K - 1] << '\n';

    return 0;
}