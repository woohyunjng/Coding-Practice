#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

const int MAX = 429001;
const int INF = 0x3f3f3f3f3f3f3f3f;

vector<pr> adj[MAX];
int depth[MAX], parent[MAX], val[MAX], cost[MAX],
    S[MAX];
bool chk[MAX];

void dfs(int node) {
    for (pr i : adj[node]) {
        if (i[1] == val[node])
            continue;
        if (!depth[i[0]]) {
            depth[i[0]] = depth[node] + 1, parent[i[0]] = node, val[i[0]] = i[1];
            dfs(i[0]), S[node] += S[i[0]];
        } else if (depth[i[0]] > depth[node])
            S[node]++;
        else
            S[node]--;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X, Y, Z, K, ans = INF;

    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        cin >> X >> Y >> Z, cost[i] = Z;
        adj[X].push_back({Y, i}), adj[Y].push_back({X, i});
    }

    depth[1] = 1, dfs(1);
    X = N, Y = INF, chk[N] = true;

    while (X != 1) {
        if (S[X] == 0)
            ans = min(ans, cost[val[X]]);
        Y = min(Y, cost[val[X]]), X = parent[X], chk[X] = true;
        for (pr i : adj[X]) {
            if (val[i[0]] == i[1] || depth[i[0]] < depth[X])
                continue;
            K = i[0], Z = cost[i[1]];
            while (!chk[K])
                Z = min(Z, cost[val[K]]), K = parent[K];
            if (K != X)
                ans = min(ans, Y + Z), Y = INF;
        }
    }

    cout << ans << '\n';

    return 0;
}