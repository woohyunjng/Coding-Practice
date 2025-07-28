#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 300001;

vector<int> adj[MAX];
int M, dp[MAX][2];

void dfs(int node, int par) {
    vector<int> arr, L, R;

    dp[node][0] = 1;
    for (int i : adj[node]) {
        if (i == par)
            continue;
        dfs(i, node), arr.push_back(i);
    }

    L.push_back(1), R.push_back(1);
    for (int i : arr)
        L.push_back(L.back() * (dp[i][0] + dp[i][1]) % M);
    dp[node][0] = L.back();

    reverse(arr.begin(), arr.end());
    for (int i : arr)
        R.push_back(R.back() * (dp[i][0] + dp[i][1]) % M);

    reverse(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++) {
        dp[node][1] += (L[i] * R[arr.size() - 1 - i] % M * dp[arr[i]][0] % M) % M;
        dp[node][1] %= M;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, Y, ans = 1;

    cin >> N >> M;
    for (int i = 1; i < N; i++) {
        cin >> X >> Y;
        adj[X].push_back(Y), adj[Y].push_back(X);
    }

    for (int i = 1; i <= N; i++)
        ans = ans * 2 % M;

    dfs(1, 0);

    ans = (ans - dp[1][0] * 2 - dp[1][1] * 2 + M * 4) % M;
    cout << ans << '\n';

    return 0;
}