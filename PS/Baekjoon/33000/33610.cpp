#include <bits/stdc++.h>
#define int long long

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;
typedef array<int, 2> pr;
typedef array<int, 3> tp;

const int MAX = 1500000;

vector<int> adj[MAX], dfs_tree_adj[MAX];
vector<pr> graph_adj[MAX];

int S, dp[MAX], sz[MAX], depth[MAX], parent[MAX], parent_edge[MAX], color[MAX], group[MAX], ans = 0;
bool vst[MAX];

void graph_dfs(int node, int par, int edge) {
    vst[node] = true, depth[node] = depth[par] + 1, parent[node] = par, parent_edge[node] = edge;

    for (pr i : graph_adj[node]) {
        if (vst[i[0]])
            continue;
        dfs_tree_adj[node].push_back(i[0]), graph_dfs(i[0], node, i[1]);
    }
}

void color_dfs(int node) {
    int X;

    for (pr i : graph_adj[node]) {
        if (depth[i[0]] < depth[node] || parent_edge[i[0]] == i[1])
            continue;
        X = i[0];
        while (color[X] != color[node])
            color[X] = color[node], X = parent[X];
    }

    for (int i : dfs_tree_adj[node])
        color_dfs(i);
}

void dfs(int node, int par) {
    sz[node] = group[node], dp[node] = 0;
    for (int i : adj[node]) {
        if (i == par)
            continue;
        dfs(i, node), sz[node] += sz[i];
    }

    vector<pr> arr;
    bool flag;

    for (int i : adj[node]) {
        if (i == par)
            continue;
        dp[node] = max(dp[node], dp[i] + (sz[node] - sz[i]) * sz[i]);
        ans = max(ans, dp[i] + sz[i] * (S - sz[i]));
        arr.push_back({-sz[i], dp[i] + sz[i] * (S - sz[i])});
    }

    if (arr.empty())
        return;
    sort(arr.begin(), arr.end());

    vector<tp> F;
    tp K;

    int X = 0;
    F.push_back({arr[0][0], arr[0][1], 0});

    for (int i = 1; i < arr.size(); i++) {
        while (X + 1 < F.size() && F[X + 1][2] < -arr[i][0])
            X++;
        ans = max(ans, F[X][1] + arr[i][1] - F[X][0] * arr[i][0]);
        K = {arr[i][0], arr[i][1], 0}, flag = true;
        while (!F.empty()) {
            if (K[0] == F.back()[0]) {
                if (K[1] <= F.back()[1]) {
                    flag = false;
                    break;
                }
            } else {
                K[2] = (F.back()[1] - K[1]) / (K[0] - F.back()[0]);
                if (F.back()[2] < K[2])
                    break;
            }
            F.pop_back();
            if (F.size() == X)
                --X;
        }
        if (flag)
            F.push_back(K);
    }
}

int max_diversity(signed N, signed M, vector<signed> U, vector<signed> V) {
    S = N;

    for (int i = 0; i < M; i++) {
        graph_adj[U[i] + 1].push_back({V[i] + 1, i + 1});
        graph_adj[V[i] + 1].push_back({U[i] + 1, i + 1});
    }

    for (int i = 1; i <= N; i++)
        color[i] = i;

    graph_dfs(1, 0, 0), color_dfs(1);

    vector<int> comp;
    for (int i = 1; i <= N; i++)
        comp.push_back(color[i]);

    sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end());
    for (int i = 1; i <= N; i++)
        color[i] = lower_bound(comp.begin(), comp.end(), color[i]) - comp.begin() + 1, group[color[i]]++;

    for (int i = 1; i <= N; i++) {
        for (pr j : graph_adj[i]) {
            if (color[i] == color[j[0]])
                continue;
            adj[color[i]].push_back(color[j[0]]);
        }
    }

    N = comp.size();
    for (int i = 1; i <= N; i++)
        sort(adj[i].begin(), adj[i].end()), adj[i].erase(unique(adj[i].begin(), adj[i].end()), adj[i].end());

    dfs(1, 0), ans = max(dp[1], ans);

    return ans;
}