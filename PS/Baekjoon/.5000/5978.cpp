#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;

const int MAX = 100000;

vector<pr> adj[MAX];
vector<int> ans;
bool vst[MAX];

bool dfs(int node, int edge) {
    int st = 1;
    vst[node] = true;
    for (pr i : adj[node]) {
        if (vst[i[0]])
            continue;
        st ^= dfs(i[0], i[1]);
    }
    if (st)
        ans.push_back(edge);
    return st;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X, Y;
    bool chk = true;

    cin >> N >> M;

    for (int i = 1; i <= M; i++) {
        cin >> X >> Y;
        adj[X].push_back({Y, i}), adj[Y].push_back({X, i});
    }

    for (int i = 1; i <= N; i++) {
        if (vst[i])
            continue;
        chk &= dfs(i, 0) ^ 1;
    }

    if (!chk) {
        cout << -1 << '\n';
        return 0;
    }

    cout << ans.size() << '\n';
    for (int i : ans)
        cout << i << '\n';

    return 0;
}