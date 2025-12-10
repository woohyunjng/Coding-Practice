#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 300000;

vector<int> adj[MAX];

bool chk[MAX];
int ans = 0;

void dfs(int node, int par, bool val) { // val : nut이 있는가
    val |= chk[node];

    int K = 0;
    for (int i : adj[node]) {
        if (i == par)
            continue;
        K += !chk[i];
    }
    if (val && K == 0)
        return;
    if (K > 1)
        val = 0;

    ans++;
    for (int i : adj[node]) {
        if (i == par)
            continue;
        dfs(i, node, val > 0);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X, Y;

    cin >> N >> M;
    for (int i = 1; i < N; i++) {
        cin >> X >> Y;
        adj[X].push_back(Y), adj[Y].push_back(X);
    }

    while (M--)
        cin >> X, chk[X] = true;

    dfs(1, 0, 0);

    cout << ans << '\n';

    return 0;
}