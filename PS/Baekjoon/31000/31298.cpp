#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;

vector<int> adj[MAX], ans;
int depth[MAX];

int dfs(int node, int par) {
    int X = 0;
    for (int i : adj[node]) {
        if (i == par || depth[i] > depth[node])
            continue;
        if (depth[i] == 0)
            depth[i] = depth[node] + 1, X += dfs(i, node);
        else
            X++;
    }

    if (X > 1 || (X == 1 && par == 0))
        ans.push_back(node), X = 0;
    return X;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X, Y;

    cin >> N >> M;
    while (M--) {
        cin >> X >> Y;
        adj[X].push_back(Y), adj[Y].push_back(X);
    }

    depth[0] = 1, dfs(0, -1);

    cout << ans.size() << '\n';
    for (int i : ans)
        cout << i << ' ';
    cout << '\n';

    return 0;
}