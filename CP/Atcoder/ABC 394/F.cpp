#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;

const int MAX = 300000;

int dp[MAX], ans = -1;

vector<int> adj[MAX];

void dfs(int node, int par) {
    vector<int> arr;
    int X;

    for (int i : adj[node]) {
        if (i == par)
            continue;
        dfs(i, node);
        if (dp[i] > 0)
            arr.push_back(dp[i]), ans = max(ans, dp[i] + 1);
        else
            arr.push_back(1);
    }

    sort(arr.begin(), arr.end(), greater<int>());

    if (arr.size() >= 4) {
        X = 1 + accumulate(arr.begin(), arr.begin() + 4, 0);
        ans = max(ans, X);
    }

    if (arr.size() >= 3)
        dp[node] = 1 + accumulate(arr.begin(), arr.begin() + 3, 0);
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