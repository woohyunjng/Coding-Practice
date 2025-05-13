#include <bits/stdc++.h>
using namespace std;

const int MAX = 2001;

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

    dfs(1);

    return 0;
}