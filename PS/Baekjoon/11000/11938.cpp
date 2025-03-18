#include <bits/stdc++.h>
using namespace std;

const int MAX = 1001;

vector<int> adj[MAX];
int res[MAX], cnt;

void dfs(int node, int par, int dep) {
    if (dep & 1)
        res[node] = cnt++;
    for (int i : adj[node]) {
        if (i == par)
            continue;
        dfs(i, node, dep + 1);
    }
    if (!(dep & 1))
        res[node] = cnt++;
}

vector<int> label(int N, int K, vector<int> U, vector<int> V) {
    vector<int> labels(N);

    for (int i = 0; i < N - 1; i++)
        adj[U[i]].push_back(V[i]), adj[V[i]].push_back(U[i]);

    cnt = 0, dfs(0, -1, 0);

    for (int i = 0; i < N; i++)
        labels[i] = res[i];

    for (int i = 0; i < N; i++)
        adj[i].clear();

    return labels;
}

int find_next_station(int s, int t, vector<int> c) {
    if (c.back() < s)
        reverse(c.begin(), c.end());
    for (int i : c) {
        if (min(i, s) <= t && t <= max(i, s))
            return i;
    }
    return c.back();
}