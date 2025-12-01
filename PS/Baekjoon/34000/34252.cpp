#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef array<int, 2> pr;

const int MAX = 100001;
const int MOD = 998244353;

vector<pr> adj[MAX];
int dp[MAX][2], depth[MAX];

ll inv(ll N) {
    ll K = MOD - 2, res = 1;
    while (K) {
        if (K & 1)
            res = res * N % MOD;
        K >>= 1, N = N * N % MOD;
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X, Y, Z;

    cin >> N >> M;
    while (M--) {
        cin >> X >> Y >> Z;
        adj[X].push_back({Y, Z}), adj[Y].push_back({X, Z});
    }

    queue<int> q;
    q.push(1), depth[1] = 1;

    dp[1][0] = 1, dp[1][1] = 0;

    while (!q.empty()) {
        X = q.front(), q.pop();
        for (pr i : adj[X]) {
            if (depth[i[0]] == 0)
                depth[i[0]] = depth[X] + 1, q.push(i[0]);
            if (depth[i[0]] == depth[X] + 1) {
                dp[i[0]][0] += dp[X][0];
                dp[i[0]][1] += ((ll)dp[X][1] + (ll)dp[X][0] * i[1]) % MOD;
                dp[i[0]][0] %= MOD, dp[i[0]][1] %= MOD;
            }
        }
    }

    for (int i = 2; i <= N; i++)
        cout << dp[i][1] * inv(dp[i][0]) % MOD << '\n';

    return 0;
}