#include <bits/stdc++.h>
#define int long long

#define MAX 200000
#define MAX_LOG 20
using namespace std;

typedef array<int, 2> pr;

int N, edge[MAX][2], depth[MAX], in[MAX], out[MAX], tree[MAX * 4][2], lazy[MAX * 4][2], val[MAX], ecnt[MAX], L[MAX], R[MAX], K[MAX], S[MAX], T[MAX], X[MAX], Y[MAX], ans[MAX], parent[MAX][MAX_LOG], cnt = 0;
vector<pr> adj[MAX];
vector<int> arr[MAX];
pr checkpoint[MAX];

void dfs(int node, int par, int sm) {
    in[node] = ++cnt, val[node] = sm, depth[node] = depth[par] + 1, parent[node][0] = par;
    for (int i = 1; i < MAX_LOG; i++)
        parent[node][i] = parent[parent[node][i - 1]][i - 1];

    for (pr i : adj[node]) {
        if (i[0] == par)
            continue;
        dfs(i[0], node, sm + ecnt[i[1]]);
    }

    out[node] = cnt;
}

void lazy_propagate(int t, int n, int s, int e) {
    if (lazy[n][t] == 0)
        return;
    if (s == e)
        tree[n][t] += lazy[n][t];
    else
        lazy[n << 1][t] += lazy[n][t], lazy[n << 1 | 1][t] += lazy[n][t];
    lazy[n][t] = 0;
}

void update(int t, int n, int s, int e, int l, int r, int v) {
    lazy_propagate(t, n, s, e);
    if (r < s || e < l)
        return;
    else if (l <= s && e <= r)
        lazy[n][t] += v, lazy_propagate(t, n, s, e);
    else {
        int m = s + e >> 1;
        update(t, n << 1, s, m, l, r, v), update(t, n << 1 | 1, m + 1, e, l, r, v);
    }
}

int query(int t, int n, int s, int e, int x) {
    lazy_propagate(t, n, s, e);
    if (x < s || e < x)
        return 0;
    else if (s == e)
        return tree[n][t];
    else {
        int m = s + e >> 1;
        return query(t, n << 1, s, m, x) + query(t, n << 1 | 1, m + 1, e, x);
    }
}

int lca(int x, int y) {
    if (depth[x] < depth[y])
        swap(x, y);

    int diff = depth[x] - depth[y];
    for (int i = MAX_LOG - 1; i >= 0; i--)
        if (diff & (1ll << i))
            diff ^= 1ll << i, x = parent[x][i];

    for (int i = MAX_LOG - 1; i >= 0; i--)
        if (parent[x][i] != parent[y][i])
            x = parent[x][i], y = parent[y][i];
    if (x != y)
        x = parent[x][0];
    return x;
}

int get(int t, int x) {
    int a = S[x], b = T[x], c = K[x];
    if (t == 2)
        return val[a] + val[b] - val[c] * 2;
    return query(t, 1, 1, N, in[a]) + query(t, 1, 1, N, in[b]) - 2 * query(t, 1, 1, N, in[c]);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int M, Q;
    bool flag;
    cin >> N >> M >> Q;

    for (int i = 1; i < N; i++) {
        cin >> edge[i][0] >> edge[i][1];
        adj[edge[i][0]].push_back({edge[i][1], i}), adj[edge[i][1]].push_back({edge[i][0], i});
    }

    for (int i = 1; i <= M; i++)
        cin >> checkpoint[i][1] >> checkpoint[i][0], ecnt[checkpoint[i][1]]++;
    sort(checkpoint + 1, checkpoint + M + 1);

    dfs(1, 0, 0);
    for (int i = 1; i < N; i++)
        if (depth[edge[i][0]] < depth[edge[i][1]])
            swap(edge[i][0], edge[i][1]);

    for (int i = 1; i <= Q; i++) {
        cin >> S[i] >> T[i] >> X[i] >> Y[i], L[i] = 0, R[i] = M;
        ans[i] = get(2, i), K[i] = lca(S[i], T[i]);
    }

    while (true) {
        for (int i = 1; i <= N * 4; i++)
            tree[i][0] = tree[i][1] = lazy[i][0] = lazy[i][1] = 0;

        flag = false;
        for (int i = 1; i <= Q; i++)
            if (L[i] <= R[i])
                arr[L[i] + R[i] >> 1].push_back(i), flag = true;
        if (!flag)
            break;

        for (int i = 0; i <= M; i++) {
            if (i) {
                update(0, 1, 1, N, in[edge[checkpoint[i][1]][0]], out[edge[checkpoint[i][1]][0]], 1);
                update(1, 1, 1, N, in[edge[checkpoint[i][1]][0]], out[edge[checkpoint[i][1]][0]], checkpoint[i][0]);
            }

            for (int j : arr[i]) {
                if (Y[j] >= get(1, j))
                    L[j] = i + 1, ans[j] = get(2, j) - get(0, j);
                else
                    R[j] = i - 1;
            }
            arr[i].clear();
        }
    }

    for (int i = 1; i <= Q; i++) {
        if (ans[i] > X[i])
            cout << -1 << '\n';
        else
            cout << X[i] - ans[i] << '\n';
    }

    return 0;
}