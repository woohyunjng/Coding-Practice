#include <bits/stdc++.h>
#define int long long

#define MAX 10100
using namespace std;

vector<int> adj[MAX], ans;
int vst[MAX], cnt = 0;

int dfs(int node, bool root) {
    int res = ++cnt, X, Y = 0;
    vst[node] = res;

    for (int i : adj[node]) {
        if (vst[i])
            res = min(res, vst[i]);
        else {
            X = dfs(i, false), Y++, res = min(res, X);
            if (!root && X >= vst[node])
                ans.push_back(node);
        }
    }

    if (root && Y > 1)
        ans.push_back(node);
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int V, E, A, B;
    cin >> V >> E;

    while (E--) {
        cin >> A >> B;
        adj[A].push_back(B), adj[B].push_back(A);
    }

    for (int i = 1; i <= V; i++) {
        if (vst[i])
            continue;
        dfs(i, true);
    }

    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    cout << ans.size() << '\n';
    for (int i : ans)
        cout << i << ' ';
    cout << '\n';

    return 0;
}