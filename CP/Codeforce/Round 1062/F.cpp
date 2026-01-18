#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 200001;

int N, K, ans, sz[MAX];
vector<int> adj[MAX];

void dfs(int node, int par) {
    sz[node] = 1, ans++;
    for (int i : adj[node]) {
        if (i == par)
            continue;
        dfs(i, node), sz[node] += sz[i];
    }

    if (sz[node] >= K)
        ans += N - sz[node];
    for (int i : adj[node]) {
        if (i == par)
            continue;
        if (N - sz[i] >= K)
            ans += sz[i];
    }
}

void solve() {
    int U, V;

    cin >> N >> K;
    for (int i = 1; i < N; i++) {
        cin >> U >> V;
        adj[U].push_back(V), adj[V].push_back(U);
    }

    ans = 0, dfs(1, 0), cout << ans << '\n';

    for (int i = 1; i <= N; i++)
        adj[i].clear(), sz[i] = 0;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;

    while (T--)
        solve();

    return 0;
}