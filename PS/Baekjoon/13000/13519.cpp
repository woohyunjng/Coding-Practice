#include <bits/stdc++.h>
#define int long long

#define MAX 200000
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;

struct Node {
    int left_v, right_v, sm, mx;
};

Node tree[MAX * 4];
int V[MAX], SV[MAX], lazy[MAX * 4], in[MAX], top[MAX], sz[MAX], parent[MAX], depth[MAX], cnt = 0;
vector<int> adj[MAX];

Node merge(Node X, Node Y) {
    return {
        max(X.left_v, X.sm + Y.left_v),
        max(Y.right_v, X.right_v + Y.sm),
        X.sm + Y.sm,
        max({X.mx, Y.mx, X.right_v + Y.left_v})};
}

void lazy_propagate(int n, int s, int e) {
    if (lazy[n] == INF)
        return;
    if (lazy[n] <= 0)
        tree[n] = {0, 0, lazy[n] * (e - s + 1), 0};
    else
        tree[n] = {lazy[n] * (e - s + 1), lazy[n] * (e - s + 1), lazy[n] * (e - s + 1), lazy[n] * (e - s + 1)};
    if (s != e)
        lazy[n << 1] = lazy[n], lazy[n << 1 | 1] = lazy[n];
    lazy[n] = INF;
}

void init(int n, int s, int e) {
    lazy[n] = INF;
    if (s == e)
        tree[n] = {max(0ll, SV[s]), max(0ll, SV[s]), SV[s], max(0ll, SV[s])};
    else {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
        tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
    }
}

void update(int n, int s, int e, int l, int r, int v) {
    lazy_propagate(n, s, e);
    if (r < s || e < l)
        return;
    else if (l <= s && e <= r) {
        lazy[n] = v;
        lazy_propagate(n, s, e);
        return;
    } else {
        int m = s + e >> 1;
        update(n << 1, s, m, l, r, v), update(n << 1 | 1, m + 1, e, l, r, v);
        tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
    }
}

Node query(int n, int s, int e, int l, int r) {
    lazy_propagate(n, s, e);
    if (r < s || e < l)
        return {0, 0, 0, 0};
    else if (l <= s && e <= r)
        return tree[n];
    else {
        int m = s + e >> 1;
        return merge(
            query(n << 1, s, m, l, r),
            query(n << 1 | 1, m + 1, e, l, r));
    }
}

void dfs1(int node, int par) {
    sz[node] = 1, parent[node] = par, depth[node] = depth[par] + 1;
    for (int &i : adj[node]) {
        if (i == par)
            continue;
        dfs1(i, node), sz[node] += sz[i];
        if (adj[node][0] == par || sz[adj[node][0]] < sz[i])
            swap(adj[node][0], i);
    }
}

void dfs2(int node, int par) {
    in[node] = ++cnt;
    for (int i : adj[node]) {
        if (i == par)
            continue;
        top[i] = i == adj[node][0] ? top[node] : i;
        dfs2(i, node);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, X, Y, W, T;
    Node valX, valY, res;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> V[i];

    for (int i = 1; i < N; i++) {
        cin >> X >> Y;
        adj[X].push_back(Y), adj[Y].push_back(X);
    }

    dfs1(1, 0), top[1] = 1, dfs2(1, 0);
    for (int i = 1; i <= N; i++)
        SV[in[i]] = V[i];
    init(1, 1, N);

    cin >> Q;
    while (Q--) {
        cin >> T >> X >> Y;
        if (T == 1) {
            valX = {0, 0, 0, 0}, valY = {0, 0, 0, 0};
            while (top[X] ^ top[Y]) {
                if (depth[top[X]] > depth[top[Y]]) {
                    valX = merge(query(1, 1, N, in[top[X]], in[X]), valX);
                    X = parent[top[X]];
                } else {
                    valY = merge(query(1, 1, N, in[top[Y]], in[Y]), valY);
                    Y = parent[top[Y]];
                }
            }
            if (depth[X] > depth[Y])
                valX = merge(query(1, 1, N, in[Y], in[X]), valX);
            else
                valY = merge(query(1, 1, N, in[X], in[Y]), valY);
            swap(valX.left_v, valX.right_v);
            res = merge(valX, valY);
            cout << res.mx << '\n';
        } else {
            cin >> W;
            while (top[X] ^ top[Y]) {
                if (depth[top[X]] < depth[top[Y]])
                    swap(X, Y);
                update(1, 1, N, in[top[X]], in[X], W), X = parent[top[X]];
            }
            if (depth[X] > depth[Y])
                swap(X, Y);
            update(1, 1, N, in[X], in[Y], W);
        }
    }

    return 0;
}