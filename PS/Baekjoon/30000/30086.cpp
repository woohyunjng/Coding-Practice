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
int N, vst[MAX], sz[MAX], ans, cnt = 0;

int dfs(int node, int par) {
    int res = ++cnt, X;
    vst[node] = res, sz[node] = 1;

    for (pr i : adj[node]) {
        if (i.first == par)
            continue;
        else if (!vst[i.first]) {
            X = dfs(i.first, node);
            if (X > vst[node] && sz[i.first] == N)
                ans = i.second;
            sz[node] += sz[i.first];
        } else
            res = min(res, vst[i.first]);
    }

    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int M, U, V;
    cin >> N >> M;

    for (int i = 1; i <= M; i++) {
        cin >> U >> V;
        adj[U].push_back({V, i}), adj[V].push_back({U, i});
    }

    for (int i = 1; i <= N * 2; i++) {
        if (vst[i])
            continue;
        dfs(i, -1);
    }

    cout << ans << '\n';

    return 0;
}