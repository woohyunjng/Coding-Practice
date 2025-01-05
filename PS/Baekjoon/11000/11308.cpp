#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

vector<pr> adj[MAX];
pr edge[MAX];
int vst[MAX], cnt = 0, cyc = 0;

int dfs(int node, int par) {
    int res = ++cnt, X, Y = 0;
    vst[node] = res;

    for (pr i : adj[node]) {
        if (i.first == par)
            continue;
        else if (vst[i.first])
            res = min(res, vst[i.first]), edge[i.second] = {i.first, node};
        else {
            X = dfs(i.first, node), Y++, res = min(res, X);
            edge[i.second] = {node, i.first};
            if (X > vst[node])
                cyc = 1;
        }
    }

    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, V, E, A, B;
    cin >> T;

    while (T--) {
        cin >> V >> E, cyc = 0;

        for (int i = 1; i <= E; i++) {
            cin >> A >> B;
            adj[A].push_back({B, i}), adj[B].push_back({A, i});
            edge[i] = {A, B};
        }

        for (int i = 1; i <= V; i++) {
            if (vst[i])
                continue;
            dfs(i, -1);
        }

        if (cyc)
            cout << "NO" << '\n';
        else {
            cout << "YES" << '\n';
            for (int i = 1; i <= E; i++)
                cout << edge[i].first << ' ' << edge[i].second << '\n';
        }

        for (int i = 1; i <= V; i++)
            adj[i].clear(), vst[i] = 0;
    }

    return 0;
}