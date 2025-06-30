#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;

const int MAX = 200001;
const int INF = 2e9;

vector<pr> adj[MAX];
int dp[MAX][2][2], V[MAX][2];

void dfs(int node, int par) {
    multiset<int> st;
    st.insert(-INF), st.insert(-INF);

    dp[node][0][1] = dp[node][1][1] = -INF;

    for (pr i : adj[node]) {
        if (i[0] == par)
            continue;
        dfs(i[0], node);
        V[i[0]][0] = max(dp[i[0]][0][0], dp[i[0]][0][1] + i[1]);
        V[i[0]][1] = max(dp[i[0]][1][0], dp[i[0]][1][1] + i[1]);

        dp[node][0][0] += V[i[0]][0];
        st.insert(-V[i[0]][0] + dp[i[0]][0][0] + i[1]);
    }

    for (pr i : adj[node]) {
        if (i[0] == par)
            continue;
        dp[node][0][1] = max(dp[node][0][1], dp[node][0][0] - V[i[0]][0] + dp[i[0]][0][0] + i[1]);
        dp[node][1][0] = max(dp[node][1][0], dp[node][0][0] - V[i[0]][0] + V[i[0]][1]);
        dp[node][1][1] = max(dp[node][1][1], dp[node][0][0] - V[i[0]][0] + dp[i[0]][1][0] + i[1]);

        st.erase(st.find(-V[i[0]][0] + dp[i[0]][0][0] + i[1]));
        dp[node][1][0] = max(dp[node][1][0], dp[node][0][0] - V[i[0]][0] + max(dp[i[0]][0][0], dp[i[0]][1][0]) + i[1] + *st.rbegin());
        st.insert(-V[i[0]][0] + dp[i[0]][0][0] + i[1]);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, Y, Z, ans = 0;

    cin >> N;
    for (int i = 1; i < N; i++) {
        cin >> X >> Y >> Z;
        adj[X].push_back({Y, Z}), adj[Y].push_back({X, Z});
    }

    dfs(1, 0);

    ans = max(dp[1][0][0], dp[1][1][0]);
    cout << ans << '\n';

    return 0;
}