#include <bits/stdc++.h>
using namespace std;

const int MAX = 2001;

vector<int> adj[MAX], ans[MAX], leaf;
int in[MAX], depth[MAX], parent[MAX], change[MAX][2], cnt;

void dfs1(int node, int par) {
    in[node] = ++cnt, parent[node] = par, depth[node] = depth[par] + 1;
    if (adj[node].size() == 1)
        leaf.push_back(node);
    for (int i : adj[node]) {
        if (i == par)
            continue;
        dfs1(i, node);
    }
}

void dfs2(int node) {
    for (int i : adj[node]) {
        if (i == parent[node])
            continue;
        ans[i] = ans[node], ans[i][change[i][0]] += change[i][1], dfs2(i);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, D, X, Y, Z;
    cin >> N;

    for (int i = 1; i < N; i++) {
        cin >> X >> Y;
        adj[X].push_back(Y), adj[Y].push_back(X);
    }

    dfs1(1, 0);

    sort(leaf.begin(), leaf.end(), [&](int x, int y) { return in[x] < in[y]; }), D = leaf.size() / 2;
    for (int i = 0; i + D < leaf.size(); i++) {
        X = leaf[i], Y = leaf[i + D], Z = 1;
        while (X != Y) {
            if (depth[X] < depth[Y])
                swap(X, Y), Z = -Z;
            if (X != 1 && change[X][1] == 0)
                change[X][0] = i, change[X][1] = Z;
            X = parent[X];
        }
    }
    if (leaf.size() % 2) {
        X = leaf.back();
        while (X != 1 && change[X][1] == 0)
            change[X][0] = D, change[X][1] = 1, X = parent[X];
    }

    ans[1].resize((leaf.size() + 1) / 2, 0), dfs2(1);

    cout << (leaf.size() + 1) / 2 << '\n';
    for (int i = 1; i <= N; i++) {
        for (int j : ans[i])
            cout << j << ' ';
        cout << '\n';
    }

    return 0;
}