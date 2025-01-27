#include <bits/stdc++.h>
#define int long long

#define MAX 300000
using namespace std;

typedef array<int, 2> pr;

vector<int> adj[MAX];
vector<pr> st;

int C[MAX], ans[MAX], depth[MAX], L, cur[MAX], res;

void dfs_depth(int node, int par) {
    depth[node] = depth[par] + 1;
    for (int i : adj[node]) {
        if (i == par)
            continue;
        dfs_depth(i, node);
    }
}

void dfs_mx(int node, int par) {
    int X = 0;
    for (int i : adj[node]) {
        if (i == par)
            continue;
        dfs_mx(i, node), X = max(X, depth[i]);
    }
    depth[node] = X + 1;
}

void dfs(int node, int par, int dpt) {
    int X = 0, Y = 0, K;
    pr Z;

    for (int i = 0; i < adj[node].size(); i++) {
        if (adj[node][i] == par)
            continue;
        if (depth[adj[node][i]] > X)
            Y = X, X = depth[adj[node][i]], swap(adj[node][0], adj[node][i]);
        else
            Y = max(Y, depth[adj[node][i]]);
    }

    for (int i : adj[node]) {
        if (i == par)
            continue;
        K = depth[i] == X ? Y : X;
        while (!st.empty() && st.back()[1] >= dpt - K) {
            Z = st.back(), st.pop_back();
            if (!--cur[C[Z[0]]])
                res--;
        }

        st.push_back({node, dpt});
        if (!cur[C[node]]++)
            res++;
        dfs(i, node, dpt + 1);
    }

    while (!st.empty() && st.back()[1] >= dpt - depth[node] + 1) {
        Z = st.back(), st.pop_back();
        if (!--cur[C[Z[0]]])
            res--;
    }

    ans[node] = max(ans[node], res);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X, Y, T[2] = {0, 0};
    cin >> N >> M;

    for (int i = 1; i < N; i++) {
        cin >> X >> Y;
        adj[X].push_back(Y), adj[Y].push_back(X);
    }

    for (int i = 1; i <= N; i++)
        cin >> C[i];

    dfs_depth(1, 0), T[0] = max_element(depth + 1, depth + N + 1) - depth;
    dfs_depth(T[0], 0), T[1] = max_element(depth + 1, depth + N + 1) - depth;

    dfs_mx(T[0], 0), L = depth[T[0]], dfs(T[0], 0, 1);
    dfs_mx(T[1], 0), L = depth[T[1]], dfs(T[1], 0, 1);

    for (int i = 1; i <= N; i++)
        cout << ans[i] << '\n';

    return 0;
}