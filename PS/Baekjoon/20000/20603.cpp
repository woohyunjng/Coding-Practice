#include <bits/stdc++.h>
#pragma GCC optimize("o3,Ofast,unroll-loops")
using namespace std;

const int MAX = 500001;
const int K = 60;
const int INF = 1e9;

int N, C[MAX], in[MAX], inv[MAX], top[MAX], sz[MAX], parent[MAX], depth[MAX], cnt,
    tree[K][MAX * 4], R[K][MAX];
vector<int> adj[MAX];

void dfs1(int node, int par) {
    depth[node] = depth[par] + 1, sz[node] = 1, parent[node] = par;
    for (int i = 0; i < adj[node].size(); i++) {
        if (adj[node][i] == par)
            continue;
        dfs1(adj[node][i], node), sz[node] += sz[adj[node][i]];
        if (adj[node][0] == par || sz[adj[node][0]] < sz[adj[node][i]])
            swap(adj[node][0], adj[node][i]);
    }
}

void dfs2(int node, int par) {
    in[node] = ++cnt, inv[in[node]] = node;
    for (int i : adj[node]) {
        if (i == par)
            continue;
        top[i] = adj[node][0] == i ? top[node] : i, dfs2(i, node);
    }
}

void init(int t) {
    for (int i = 1; i <= N; i++)
        tree[t][i + N - 1] = R[t][C[inv[i]]];
    for (int i = N - 1; i > 0; i--)
        tree[t][i] = min(tree[t][i << 1], tree[t][i << 1 | 1]);
}

int seg_query(int t, int l, int r) {
    int res = INF;
    for (l += N - 1, r += N; l < r; l >>= 1, r >>= 1) {
        if (l & 1)
            res = min(res, tree[t][l]), l++;
        if (r & 1)
            --r, res = min(res, tree[t][r]);
    }
    return res;
}

void update(int t, int x, int v) {
    for (tree[t][x += N - 1] = v; x > 1; x >>= 1)
        tree[t][x >> 1] = min(tree[t][x], tree[t][x ^ 1]);
}

int query(int t, int s, int e) {
    int res = INF;
    while (top[s] ^ top[e]) {
        if (depth[top[s]] < depth[top[e]])
            swap(s, e);
        res = min(res, seg_query(t, in[top[s]], in[s])), s = parent[top[s]];
    }
    if (depth[s] > depth[e])
        swap(s, e);
    res = min(res, seg_query(t, in[s], in[e]));
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, Q, U, V, TP, X, Y, Z, W, res;

    mt19937 mt(6969);
    uniform_int_distribution<int> dist(1, 1e5);

    cin >> T;
    while (T--) {
        cin >> N >> Q, cnt = 0;
        for (int i = 1; i <= N; i++)
            cin >> C[i], adj[i].clear();

        for (int i = 0; i < K; i++)
            for (int j = 1; j <= N; j++)
                R[i][j] = dist(mt);

        for (int i = 1; i < N; i++) {
            cin >> U >> V;
            adj[U].push_back(V), adj[V].push_back(U);
        }

        top[1] = 1, dfs1(1, 0), dfs2(1, 0);
        for (int i = 0; i < K; i++)
            init(i);

        V = 0;
        while (Q--) {
            cin >> TP;
            if (TP == 1) {
                cin >> X >> Y, X ^= V, Y ^= V;
                for (int i = 0; i < K; i++)
                    update(i, in[X], R[i][Y]);
            } else {
                cin >> X >> Y >> Z >> W, res = 0;
                X ^= V, Y ^= V, Z ^= V, W ^= V;
                for (int i = 0; i < K; i++) {
                    if (query(i, X, Y) < query(i, Z, W))
                        res++;
                    else if (query(i, X, Y) > query(i, Z, W))
                        res--;
                }
                cout << (res > 0 ? "Yes" : "No") << '\n', V += res > 0;
            }
        }
    }

    return 0;
}