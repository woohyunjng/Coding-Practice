#include <bits/stdc++.h>
#define int long long

#define MAX 5100

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

bool black[MAX];
int N, dp[MAX][MAX][2], res[MAX][2], sz[MAX], temp[MAX][2];
vector<int> adj[MAX];

void dfs(int node, int par) {
    for (int i = 0; i <= N; i++)
        dp[node][i][0] = MAX, dp[node][i][1] = -1;
    sz[node] = 1, dp[node][1][0] = dp[node][1][1] = black[node];

    for (int i : adj[node]) {
        if (i == par)
            continue;
        dfs(i, node);

        for (int j = sz[node]; j >= 1; j--)
            for (int k = 0; k <= sz[i]; k++) {
                dp[node][j + k][0] = min(dp[node][j + k][0], dp[node][j][0] + dp[i][k][0]);
                dp[node][j + k][1] = max(dp[node][j + k][1], dp[node][j][1] + dp[i][k][1]);
            }

        sz[node] += sz[i];
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int B, X, Y, Q, ans = 0;
    bool flag;

    cin >> N >> B;

    while (B--)
        cin >> X, black[X] = true;

    for (int i = 1; i < N; i++) {
        cin >> X >> Y;
        adj[X].push_back(Y), adj[Y].push_back(X);
    }

    dfs(1, 0);

    for (int i = 1; i <= N; i++) {
        res[i][0] = MAX, res[i][1] = -1;
        for (int j = 1; j <= N; j++)
            if (dp[j][i][0] != -1)
                res[i][0] = min(res[i][0], dp[j][i][0]), res[i][1] = max(res[i][1], dp[j][i][1]);
    }

    cin >> Q;
    while (Q--) {
        cin >> X >> Y;
        flag = res[X][0] <= Y && Y <= res[X][1];
        ans += flag;
    }
    cout << ans << '\n';

    return 0;
}