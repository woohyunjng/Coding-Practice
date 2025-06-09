#include <bits/stdc++.h>
using namespace std;

const int MAX = 101;

vector<int> adj[MAX];
bool vst[MAX];

void dfs(int node) {
    cout << node << ' ';
    vst[node] = true;

    for (int i : adj[node])
        if (!vst[i])
            dfs(i);
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

    for (int i = 1; i <= N; i++)
        sort(adj[i].begin(), adj[i].end());

    dfs(1);

    return 0;
}