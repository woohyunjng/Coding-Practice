#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 6001;
const int MOD = 1'000'000'007;

int V[MAX], dp[MAX][MAX], depth[MAX];
vector<int> adj[MAX];

void dfs(int node) {
    for (int i : adj[node])
        depth[i] = depth[node] + 1, dfs(i);

    int X, Y;
    for (int i = 0; i <= depth[node]; i++) {
        X = Y = 1;
        for (int j : adj[node]) {
            X *= dp[j][i + 1], X %= MOD;
            Y *= dp[j][i], Y %= MOD;
        }
        dp[node][i] = (X * (i + 1) - Y + MOD) % MOD;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, L, R, ans;
    vector<int> st;

    cin >> T;
    while (T--) {
        cin >> N, ans = 1;

        for (int i = 1; i <= N; i++)
            cin >> L >> R, V[L] = i, V[R] = -i;

        st.clear();
        for (int i = 1; i <= N << 1; i++) {
            if (V[i] > 0)
                st.push_back(V[i]);
            else {
                while (st.back() != -V[i])
                    adj[-V[i]].push_back(st.back()), st.pop_back();
            }
        }

        for (int i : st) {
            depth[i] = 0, dfs(i);
            ans *= dp[i][0], ans %= MOD;
        }

        cout << ans << '\n';
        for (int i = 1; i <= N; i++)
            adj[i].clear();
    }

    return 0;
}
