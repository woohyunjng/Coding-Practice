#include <bits/stdc++.h>
#define int long long

#define MAX 300000

using namespace std;
typedef array<int, 2> pr;

vector<pr> adj[MAX];
int depth[MAX], val[MAX][2], cycle = 0;

void dfs(int node, int par) {
    for (pr i : adj[node]) {
        if (i[1] == par)
            continue;
        if (!depth[i[0]]) {
            depth[i[0]] = depth[node] + 1, dfs(i[0], i[1]);
            val[node][0] += val[i[0]][0], val[node][1] += val[i[0]][1];
        } else {
            if (depth[i[0]] > depth[node])
                continue;
            if ((depth[i[0]] - depth[node]) & 1)
                val[node][0]++, val[i[0]][0]--;
            else
                cycle++, val[node][1]++, val[i[0]][1]--;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X, Y, ans = 0;
    cin >> N >> M;

    for (int i = 1; i <= M; i++) {
        cin >> X >> Y;
        adj[X].push_back({Y, i}), adj[Y].push_back({X, i});
    }

    for (int i = 1; i <= N; i++) {
        if (depth[i])
            continue;
        depth[i] = 1, dfs(i, 0);
    }

    for (int i = 1; i <= N; i++) {
        if (depth[i] == 1)
            continue;
        if (!val[i][0] && val[i][1] == cycle)
            ans++;
    }

    if (cycle == 1)
        ans++;
    cout << ans << '\n';

    return 0;
}