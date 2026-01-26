#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 100001;
const int MAX_LOG = 20;

vector<int> adj[MAX], arr[MAX];
int N, A[MAX], B[MAX], C[MAX],
    parent[MAX][MAX_LOG], depth[MAX], cnt, in[MAX], out[MAX],
    tree[MAX * 4], lazy[MAX * 4],
    dp[MAX], S[MAX];

void lazy_update(int n, int s, int e) {
    if (lazy[n] == 0)
        return;
    if (s ^ e)
        lazy[n << 1] += lazy[n], lazy[n << 1 | 1] += lazy[n];
    else
        tree[n] += lazy[n];
    lazy[n] = 0;
}

void update(int n, int s, int e, int l, int r, int v) {
    lazy_update(n, s, e);
    if (r < s || e < l)
        return;
    else if (l <= s && e <= r)
        lazy[n] = v;
    else {
        int m = s + e >> 1;
        update(n << 1, s, m, l, r, v), update(n << 1 | 1, m + 1, e, l, r, v);
        tree[n] = tree[n << 1] + tree[n << 1 | 1];
    }
}

int query(int n, int s, int e, int x) {
    lazy_update(n, s, e);
    if (x < s || e < x)
        return 0;
    else if (s == e)
        return tree[n];
    else {
        int m = s + e >> 1;
        return query(n << 1, s, m, x) + query(n << 1 | 1, m + 1, e, x);
    }
}

void lca_dfs(int node, int par) {
    in[node] = ++cnt;
    parent[node][0] = par, depth[node] = depth[par] + 1;
    for (int i = 1; i < MAX_LOG; i++)
        parent[node][i] = parent[parent[node][i - 1]][i - 1];

    for (int i : adj[node]) {
        if (i == par)
            continue;
        lca_dfs(i, node);
    }
    out[node] = cnt;
}

int lca(int X, int Y) {
    if (depth[X] < depth[Y])
        swap(X, Y);

    int diff = depth[X] - depth[Y];
    for (int i = 0; i < MAX_LOG; i++)
        if (diff & (1 << i))
            X = parent[X][i];

    for (int i = MAX_LOG - 1; i >= 0; i--)
        if (parent[X][i] != parent[Y][i])
            X = parent[X][i], Y = parent[Y][i];
    if (X ^ Y)
        X = parent[X][0];
    return X;
}

void dfs(int node, int par) {
    for (int i : adj[node]) {
        if (i == par)
            continue;
        dfs(i, node), S[node] += dp[i];
    }
    dp[node] = S[node];

    for (int i : arr[node])
        dp[node] = max(dp[node], C[i] + S[node] + query(1, 1, N, in[A[i]]) + query(1, 1, N, in[B[i]]));
    update(1, 1, N, in[node], out[node], S[node] - dp[node]);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int M, U, V, ans = 0;

    cin >> N;
    for (int i = 1; i < N; i++) {
        cin >> U >> V;
        adj[U].push_back(V), adj[V].push_back(U);
    }

    lca_dfs(1, 0);

    cin >> M;
    for (int i = 1; i <= M; i++) {
        cin >> A[i] >> B[i] >> C[i];
        arr[lca(A[i], B[i])].push_back(i);
    }

    dfs(1, 0);

    ans = dp[1], cout << ans << '\n';

    return 0;
}