#include <bits/stdc++.h>
using namespace std;

const int MAX = 200001;

vector<int> adj[MAX];
bool chk[MAX];

int dfs(int node) {
    chk[node] = true;
    int V = adj[node].size() % 2;
    for (int i : adj[node])
        if (!chk[i])
            V += dfs(i);
    return V;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X, Y, ans = 0;

    cin >> N >> M;
    while (M--) {
        cin >> X >> Y;
        adj[X].push_back(Y), adj[Y].push_back(X);
    }

    for (int i = 1; i <= N; i++)
        if (!chk[i] && !adj[i].empty())
            ans += max(1, dfs(i) / 2);

    cout << ans << '\n';

    return 0;
}