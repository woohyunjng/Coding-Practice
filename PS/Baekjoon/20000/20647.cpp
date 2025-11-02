#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;

vector<int> adj[MAX];
int ans;

void dfs(int node, int par) {
    int V = 0, X = 1;
    for (int i : adj[node]) {
        if (i == par)
            continue;
        dfs(i, node), V++;
    }

    while (X <= V)
        X <<= 1, ans++;
    ans += V;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, Y;

    cin >> N;
    for (int i = 1; i < N; i++) {
        cin >> X >> Y;
        adj[X].push_back(Y), adj[Y].push_back(X);
    }

    dfs(1, 0);

    cout << ans << '\n';

    return 0;
}