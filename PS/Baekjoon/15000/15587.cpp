#include <bits/stdc++.h>
#define int long long

#define MAX 100100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

vector<int> adj[MAX];
int deg[MAX], depth[MAX], dp[MAX];

int dfs(int K, int pr) {
    int res = 0;

    depth[K] = depth[pr] + 1;
    dp[K] = deg[K] == 1 ? depth[K] : INF;

    for (int i : adj[K]) {
        if (i == pr)
            continue;
        res += dfs(i, K);
        dp[K] = min(dp[K], dp[i]);
    }

    if (depth[K] * 2 >= dp[K])
        res = 1;
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, X, Y;
    cin >> N >> K;

    for (int i = 1; i < N; i++) {
        cin >> X >> Y;
        adj[X].push_back(Y), adj[Y].push_back(X);
        deg[X]++, deg[Y]++;
    }

    depth[0] = -1;
    cout << dfs(K, 0) << '\n';

    return 0;
}