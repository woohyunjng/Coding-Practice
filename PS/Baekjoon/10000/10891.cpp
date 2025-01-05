#include <bits/stdc++.h>
#define int long long

#define MAX 100100
using namespace std;

vector<int> adj[MAX];
int cnt, vst[MAX];
bool cact[MAX];

int dfs(int node, int par) {
    int res = ++cnt, X = 0, Y = 0;
    vst[node] = res;

    for (int i : adj[node]) {
        if (i == par)
            continue;

        if (!vst[i])
            X += dfs(i, node);
        else if (vst[i] < vst[node])
            X++;
        else
            Y++;
    }

    cact[node] = X <= 1;
    return X - Y;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, U, V;
    bool res = true;
    cin >> N >> M;

    while (M--) {
        cin >> U >> V;
        adj[U].push_back(V), adj[V].push_back(U);
    }

    dfs(1, -1);

    for (int i = 1; i <= N; i++)
        res &= cact[i];
    cout << (res ? "Cactus" : "Not cactus") << '\n';

    return 0;
}