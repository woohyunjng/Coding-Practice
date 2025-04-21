#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 2001;

vector<int> adj[MAX];

vector<int> dfs(int node, int par) {
    vector<int> dp, tmp;
    vector<vector<int>> child;

    int X;

    for (int i : adj[node]) {
        if (i == par)
            continue;
        tmp = dfs(i, node);
        if (tmp.size() > dp.size())
            swap(tmp, dp);
        for (int j = 0; j < tmp.size(); j++) {
            if (j >= child.size())
                child.push_back({});
            child[j].push_back(tmp[(int)tmp.size() - j - 1]);
        }
    }

    for (int i = 0; i < child.size(); i++) {
        X = dp[(int)dp.size() - i - 1], child[i].push_back(X);
        sort(child[i].begin(), child[i].end(), greater<int>());
        for (int j = 0; j < child[i].size(); j++)
            X = max(X, child[i][j] + j);
        dp[(int)dp.size() - i - 1] = X;
    }

    dp.push_back(0);
    return dp;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, Y, ans = MAX * MAX;
    vector<int> dp;

    cin >> N;
    for (int i = 1; i < N; i++) {
        cin >> X >> Y;
        adj[X].push_back(Y), adj[Y].push_back(X);
    }

    for (int i = 1; i <= N; i++) {
        dp = dfs(i, 0), X = 0;
        for (int j : dp)
            X = max(X, j + 1);
        ans = min(ans, X);
    }

    cout << ans << '\n';

    return 0;
}