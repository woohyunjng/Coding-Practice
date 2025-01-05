#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

vector<pr> ans;
vector<int> adj[MAX];
int vst[MAX], cnt = 0;

int dfs(int node, int par) {
    int res = ++cnt, X, Y = 0;
    vst[node] = res;

    for (int i : adj[node]) {
        if (i == par)
            continue;
        else if (vst[i])
            res = min(res, vst[i]);
        else {
            X = dfs(i, node), Y++, res = min(res, X);
            if (X > vst[node])
                ans.push_back({min(node, i), max(node, i)});
        }
    }

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
        dfs(i, -1);
    }

    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    cout << ans.size() << '\n';
    for (pr i : ans)
        cout << i.first << ' ' << i.second << '\n';

    return 0;
}