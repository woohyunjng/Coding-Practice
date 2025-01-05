#include <bits/stdc++.h>
#define int long long

#define MAX 10100
using namespace std;
typedef pair<int, int> pr;

vector<int> adj[MAX], ans;
int vst[MAX], cnt = 0;

pr dfs(int node, bool root) {
    int res = ++cnt, X, Y = 0, Z = 0, mx = 0;
    pr K;
    vst[node] = res;

    for (int i : adj[node]) {
        if (vst[i])
            res = min(res, vst[i]);
        else {
            K = dfs(i, false), Y++, res = min(res, K.first), mx = max(mx, K.second);
            if (!root && K.first >= vst[node])
                Z++;
        }
    }
    mx = max(mx, Z);
    if (root && Y > 1)
        mx = Y - 1;

    if (root && adj[node].empty())
        return {res, -1};
    return {res, mx};
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int V, E, A, B, cnt = 0, res = 0;

    while (true) {
        cin >> V >> E, cnt = 0, res = -1;
        if (V == 0 && E == 0)
            break;

        while (E--) {
            cin >> A >> B;
            adj[A].push_back(B), adj[B].push_back(A);
        }

        for (int i = 0; i < V; i++) {
            if (vst[i])
                continue;
            res = max(res, dfs(i, true).second), cnt++;
        }

        cout << cnt + res << '\n';

        for (int i = 0; i < V; i++)
            adj[i].clear(), vst[i] = 0;
    }

    return 0;
}