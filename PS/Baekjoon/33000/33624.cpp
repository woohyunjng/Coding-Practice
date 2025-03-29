#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 100001;
const int MOD = 1000000007;

int sz[MAX], two[MAX];
vector<int> adj[MAX];

int dfs(int node, int par) {
    int res = 1;
    sz[node] = 1;
    for (int i : adj[node]) {
        if (i == par)
            continue;
        res = res * dfs(i, node) % MOD, sz[node] += sz[i];
    }
    return (two[sz[node] - 1] - res + MOD) % MOD;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, R, X, Y;
    cin >> N >> R;

    two[0] = 1;
    for (int i = 1; i < N; i++)
        two[i] = two[i - 1] * 2 % MOD;

    for (int i = 1; i < N; i++) {
        cin >> X >> Y;
        adj[X].push_back(Y), adj[Y].push_back(X);
    }

    cout << dfs(R, 0) << '\n';

    return 0;
}