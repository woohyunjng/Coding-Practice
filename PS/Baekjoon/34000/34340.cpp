#include <bits/stdc++.h>
using namespace std;

typedef array<int, 3> tp;

const int MAX = 3001;

int V[MAX][3], G[MAX], cnt;
vector<int> go[MAX];
vector<tp> adj[MAX];

int dnc(int l, int r) {
    int X = ++cnt, Y, K, W = 0;

    for (int i = l; i < r; i++) {
        if (go[i].empty())
            continue;
        Y = go[i].back(), go[i].pop_back(), K = dnc(i, Y);
        adj[K].push_back({X, i, Y}), adj[X].push_back({K, i, Y});
        W = i == l ? Y : i, i = Y - 1;
    }

    V[X][0] = l, V[X][1] = r, V[X][2] = W == 0 ? l + 1 : W;
    G[X] = V[X][0] ^ V[X][1] ^ V[X][2];
    return X;
}

void dfs(int node, int par) {
    if (par == 0)
        cout << V[node][0] << ' ' << V[node][1] << ' ' << V[node][2] << '\n';
    /*
        cout << node << ' ' << par << "node\n";
        cout << V[node][0] << ' ' << V[node][1] << ' ' << V[node][2] << "tri\n";*/

    int C = 0;

    for (tp i : adj[node]) {
        if (i[0] == par)
            continue;
        cout << i[1] << ' ' << i[2] << ' ' << (C == 0 ? (G[node] ^ i[1] ^ i[2]) : C) << ' ' << (G[i[0]] ^ i[1] ^ i[2]) << '\n';
        dfs(i[0], node), C = G[i[0]] ^ i[1] ^ i[2];
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, U, V;

    cin >> N;
    for (int i = 0; i < N - 3; i++) {
        cin >> U >> V;
        go[U].push_back(V);
    }

    for (int i = 1; i <= N; i++)
        sort(go[i].begin(), go[i].end());

    dnc(1, N), dfs(1, 0);

    return 0;
}