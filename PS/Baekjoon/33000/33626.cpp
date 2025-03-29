#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 100001;

vector<int> adj[MAX];
int P, val[MAX], depth[MAX];

int dfs(int node, int par, int len) {
    int res = 0;
    val[node] = MAX * 2, depth[node] = depth[par] + 1;
    for (int i : adj[node]) {
        if (i == par)
            continue;
        res += dfs(i, node, len);
        val[node] = min(val[node], val[i]);
    }
    if (node != P && val[node] - depth[node] > len)
        val[node] = depth[node], res++;
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X, Y, st, en, md, ans = -1;

    cin >> N >> M >> P;

    for (int i = 1; i < N; i++) {
        cin >> X >> Y;
        adj[X].push_back(Y), adj[Y].push_back(X);
    }

    st = 0, en = N;
    while (st <= en) {
        md = st + en >> 1;
        if (dfs(P, 0, md) <= M)
            en = md - 1, ans = md + 1;
        else
            st = md + 1;
    }

    cout << ans << '\n';

    return 0;
}