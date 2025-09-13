#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

const int MAX = 250001;

vector<int> adj[MAX], arr;
int depth[MAX], V[MAX], D;

random_device rd;
mt19937 mt(rd());

void dfs(int node, int par) {
    int X;
    depth[node] = depth[par] + 1;

    for (int i : adj[node]) {
        if (i == par)
            continue;
        else if (depth[i] == 0)
            dfs(i, node), V[node] ^= V[i];
        else if (depth[i] < depth[node]) {
            X = mt(), arr.push_back(X);
            V[node] ^= X, V[i] ^= X;
            if (depth[i] % 2 == depth[node] % 2)
                D ^= X;
        }
    }
    if (node != 1)
        arr.push_back(V[node]);
}

int count_ways(signed N, vector<signed> U, vector<signed> V) {
    int M = U.size(), ans = 0;
    for (int i = 0; i < M; i++) {
        adj[U[i]].push_back(V[i]);
        adj[V[i]].push_back(U[i]);
    }

    dfs(1, 0);

    if (D == 0)
        return 1;
    for (int i : arr)
        if (i == D)
            ans++;
    if (ans != 0)
        return ans;

    map<int, int> mp;
    ans = 0;
    for (int i : arr)
        ans += mp[i ^ D], mp[i]++;
    return ans;
}
