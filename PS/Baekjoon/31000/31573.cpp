#include <bits/stdc++.h>
#define int long long

#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#define MAX 100100
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;
typedef pair<int, int> pr;

vector<int> tree_adj[MAX], depth[MAX];
vector<pr> adj[MAX * 40];
map<pr, int> num;

int N, sz[MAX], parent[MAX], max_depth[MAX], cnt = 0, node_num[MAX], us_num[MAX], dis[MAX * 40];
bool vst[MAX];

int get_size(int node, int par) {
    int res = 1;
    for (int i : tree_adj[node]) {
        if (i == par || vst[i])
            continue;
        res += get_size(i, node);
    }
    return sz[node] = res;
}

int get_centroid(int node, int par, int cap) {
    for (int i : tree_adj[node]) {
        if (i == par || vst[i])
            continue;
        if (sz[i] * 2 > cap)
            return get_centroid(i, node, cap);
    }
    return node;
}

int get_depth(int node, int par, int dep) {
    int res = dep;
    for (int i : tree_adj[node]) {
        if (i == par || vst[i])
            continue;
        res = max(res, get_depth(i, node, dep + 1));
    }
    return res;
}

void dfs(int node, int par, int dep, int cent) {
    depth[node].push_back(dep);
    adj[num[{cent + 1, dep}]].push_back({0, node_num[node]});
    adj[node_num[node] + 1].push_back({0, num[{-cent - 1, dep}]});

    for (int i : tree_adj[node]) {
        if (i == par || vst[i])
            continue;
        dfs(i, node, dep + 1, cent);
    }
}

void build_tree(int node, int par) {
    int cent = get_centroid(node, -1, get_size(node, -1));
    vst[cent] = true, parent[cent] = par;

    max_depth[cent] = get_depth(cent, -1, 0);

    for (int i = 0; i <= max_depth[cent]; i++)
        num[{cent + 1, i}] = ++cnt, num[{-cent - 1, i}] = ++cnt;

    dfs(cent, -1, 0, cent);
    for (int i = max_depth[cent]; i > 0; i--)
        adj[num[{cent + 1, i}]].push_back({0, num[{cent + 1, i - 1}]}), adj[num[{-cent - 1, i - 1}]].push_back({0, num[{-cent - 1, i}]});

    for (int i : tree_adj[cent]) {
        if (vst[i])
            continue;
        build_tree(i, cent);
    }
}

vector<int> find_spread(signed n, signed M, vector<signed> A, vector<signed> B, vector<signed> P, vector<signed> D, vector<signed> C) {
    vector<int> ans(M, INF);
    vector<pr> arr;
    int L, T, Z;
    N = n;

    for (int i = 0; i < N; i++) {
        node_num[i] = ++cnt, ++cnt;
        adj[node_num[i]].push_back({C[i], node_num[i] + 1});
    }

    for (int i = 0; i < N - 1; i++)
        tree_adj[A[i]].push_back(B[i]), tree_adj[B[i]].push_back(A[i]);
    build_tree(0, -1);

    for (int i = 0; i < M; i++) {
        T = P[i], us_num[i] = ++cnt, Z = depth[P[i]].size();
        while (T != -1) {
            L = depth[P[i]][--Z];
            if (D[i] - L >= 0) {
                adj[us_num[i]].push_back({0, num[{T + 1, min(max_depth[T], D[i] - L)}]});
                adj[num[{-T - 1, min(max_depth[T], D[i] - L)}]].push_back({0, us_num[i]});
            }
            T = parent[T];
        }
    }

    fill(dis, dis + cnt + 1, INF);

    priority_queue<pr, vector<pr>, greater<pr>> pq;
    queue<pr> q;
    pr X;

    q.push({0ll, us_num[0]}), dis[us_num[0]] = 0;
    while (!q.empty() || !pq.empty()) {
        if (!q.empty())
            X = q.front(), q.pop();
        else
            X = pq.top(), pq.pop();
        if (dis[X.second] < X.first)
            continue;
        for (pr i : adj[X.second]) {
            if (dis[i.second] > X.first + i.first) {
                dis[i.second] = X.first + i.first;
                if (i.first)
                    pq.push({dis[i.second], i.second});
                else
                    q.push({dis[i.second], i.second});
            }
        }
    }

    for (int i = 0; i < M; i++) {
        if (dis[us_num[i]] == INF)
            dis[us_num[i]] = -1;
        ans[i] = dis[us_num[i]];
    }
    return ans;
}