#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 100001;
const int MAX_LOG = 20;

int parent[MAX][MAX_LOG], depth[MAX], queries[MAX][2], root[MAX], dia[MAX][2];
vector<int> adj[MAX];

void dfs(int node, int par) {
    parent[node][0] = par, depth[node] = depth[par] + 1;
    for (int i = 1; i < MAX_LOG; i++)
        parent[node][i] = parent[parent[node][i - 1]][i - 1];

    for (int i : adj[node])
        dfs(i, node);
}

int lca(int X, int Y) {
    if (depth[X] < depth[Y])
        swap(X, Y);

    int diff = depth[X] - depth[Y];
    for (int i = 0; i < MAX_LOG; i++)
        if (diff & (1 << i))
            X = parent[X][i];

    for (int i = MAX_LOG - 1; i >= 0; i--)
        if (parent[X][i] != parent[Y][i])
            X = parent[X][i], Y = parent[Y][i];
    if (X != Y)
        X = parent[X][0];
    return X;
}

int dis(int X, int Y) { return depth[X] + depth[Y] - 2 * depth[lca(X, Y)]; }

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N = 0, Q, X, R;
    char C;

    cin >> Q;

    for (int i = 1; i <= Q; i++) {
        cin >> C >> X;
        if (C == 'B') {
            if (X != -1)
                adj[X].push_back(++N), root[N] = root[X];
            else
                ++N, root[N] = N;
            queries[i][0] = N, queries[i][1] = 0;
        } else
            queries[i][0] = X, queries[i][1] = 1;
    }

    for (int i = 1; i <= N; i++)
        if (root[i] == i)
            dfs(i, 0);

    for (int i = 1; i <= Q; i++) {
        X = queries[i][0], R = root[X];
        if (queries[i][1] == 0) {
            if (R == X)
                dia[R][0] = X, dia[R][1] = X;
            else {
                if (dis(dia[R][0], X) > dis(dia[R][0], dia[R][1]))
                    dia[R][1] = X;
                else if (dis(dia[R][1], X) > dis(dia[R][0], dia[R][1]))
                    dia[R][0] = X;
            }
        } else
            cout << max(dis(dia[root[X]][0], X), dis(dia[root[X]][1], X)) << '\n';
    }

    return 0;
}