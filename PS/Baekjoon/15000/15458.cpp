#include <bits/stdc++.h>
#define int long long

#define MAX 100100
#define MOD 1000000007

using namespace std;

int color[MAX], dp[MAX][4];
vector<int> adj[MAX];

int dfs(int K, int pr, int C) {
    if (color[K] != 0 && color[K] != C)
        return 0;
    if (dp[K][C] != 0)
        return dp[K][C];

    int res = 1, val;
    for (int i : adj[K]) {
        if (i == pr)
            continue;
        val = 0;
        for (int j = 1; j <= 3; j++) {
            if (j == C)
                continue;
            val = (val + dfs(i, K, j)) % MOD;
        }
        res = (res * val) % MOD;
    }

    return dp[K][C] = res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, X, Y;
    cin >> N >> K;

    for (int i = 1; i < N; i++) {
        cin >> X >> Y;
        adj[X].push_back(Y), adj[Y].push_back(X);
    }

    while (K--) {
        cin >> X >> Y;
        color[X] = Y;
    }

    cout << (dfs(1, 0, 1) + dfs(1, 0, 2) + dfs(1, 0, 3)) % MOD << '\n';

    return 0;
}