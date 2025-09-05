#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;

vector<int> adj[MAX][2];
int R[2];
bool chk[MAX][2];

void dfs(int node, int t) {
    chk[node][t] = true, R[t]++;
    for (int i : adj[node][t]) {
        if (!chk[i][t])
            dfs(i, t);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X, U, V;

    cin >> N >> M >> X;
    while (M--) {
        cin >> U >> V;
        adj[U][0].push_back(V);
        adj[V][1].push_back(U);
    }

    dfs(X, 0), dfs(X, 1);

    cout << R[1] << ' ' << N - R[0] + 1 << '\n';

    return 0;
}