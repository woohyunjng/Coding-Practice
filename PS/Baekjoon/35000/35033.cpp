#include <bits/stdc++.h>
using namespace std;

const int MAX = 200001;

vector<int> adj[MAX];
int sz[MAX];

void dfs1(int node, int par) {
    sz[node] = 1;
    for (int &i : adj[node]) {
        if (i == par)
            continue;
        dfs1(i, node), sz[node] += sz[i];
        if (adj[node][0] == par || sz[adj[node][0]] < sz[i])
            swap(adj[node][0], i);
    }
}

void dfs2(int node, int par) {
    for (int i : adj[node]) {
        if (i == par)
            continue;
        dfs2(i, node);
    }
    cout << node << ' ';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, U, V;

    cin >> N;
    for (int i = 1; i < N; i++) {
        cin >> U >> V;
        adj[U].push_back(V), adj[V].push_back(U);
    }

    dfs1(1, 0), dfs2(1, 0), cout << '\n';
}