#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 3> tp;

const int MAX = 200001;

vector<tp> adj[MAX];
tp tree[MAX * 4];

int V[MAX], ans[MAX], lazy[MAX * 4], depth[MAX], in[MAX], out[MAX], G[MAX], num[MAX], parent[MAX], cnt;
bool chk[MAX];

int dfs1(int node, int par) {
    int res = 0;
    for (tp i : adj[node]) {
        if (i[0] == par)
            continue;
        res += i[2] + dfs1(i[0], node);
    }
    return res;
}

void dfs2(int node, int par, int val) {
    V[node] = val;
    for (tp i : adj[node]) {
        if (i[0] == par)
            continue;
        dfs2(i[0], node, val + i[1] - i[2]);
    }
}

void dfs3(int node, int par) {
    for (tp i : adj[node]) {
        if (i[0] == par)
            continue;
        depth[i[0]] = depth[node] + i[1], dfs3(i[0], node);
    }
}

void dfs4(int node, int par) {
    in[node] = ++cnt, parent[node] = par;
    for (tp i : adj[node]) {
        if (i[0] == par)
            continue;
        G[i[0]] = i[1], depth[i[0]] = depth[node] + i[1];
        dfs4(i[0], node);
    }
    out[node] = cnt;
}

tp merge(tp A, tp B) {
    if (A[0] != B[0])
        return A[0] < B[0] ? A : B;
    else if (A[1] != B[1])
        return A[1] > B[1] ? A : B;
    else
        return A[2] < B[2] ? A : B;
}

void init(int n, int s, int e) {
    if (s == e)
        tree[n][0] = 0, tree[n][1] = depth[num[s]], tree[n][2] = num[s];
    else {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
        tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
    }
}

void lazy_update(int n, int s, int e) {
    if (lazy[n] == 0)
        return;
    tree[n][1] += lazy[n];
    if (s ^ e)
        lazy[n << 1] += lazy[n], lazy[n << 1 | 1] += lazy[n];
    lazy[n] = 0;
}

void update(int n, int s, int e, int l, int r, int v) {
    lazy_update(n, s, e);
    if (r < s || e < l)
        return;
    else if (l <= s && e <= r)
        lazy[n] += v, lazy_update(n, s, e);
    else {
        int m = s + e >> 1;
        update(n << 1, s, m, l, r, v), update(n << 1 | 1, m + 1, e, l, r, v);
        tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
    }
}

void toggle(int n, int s, int e, int x) {
    lazy_update(n, s, e);
    if (x < s || e < x)
        return;
    else if (s == e)
        tree[n][0] = 1;
    else {
        int m = s + e >> 1;
        toggle(n << 1, s, m, x), toggle(n << 1 | 1, m + 1, e, x);
        tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
    }
}

tp query(int n, int s, int e, int l, int r) {
    lazy_update(n, s, e);
    if (r < s || e < l)
        return {1, 0, 0};
    else if (l <= s && e <= r)
        return tree[n];
    else {
        int m = s + e >> 1;
        return merge(query(n << 1, s, m, l, r), query(n << 1 | 1, m + 1, e, l, r));
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, A, B, C, D, R, X, Y, S = 0;
    tp K;

    cin >> N;
    for (int i = 1; i < N; i++) {
        cin >> A >> B >> C >> D, S += C + D;
        adj[A].push_back({B, C, D}), adj[B].push_back({A, D, C});
    }

    dfs2(1, 0, dfs1(1, 0));
    for (int i = 1; i <= N; i++)
        ans[1] = max(ans[1], V[i]);

    dfs3(1, 0), R = 0;
    for (int i = 1; i <= N; i++)
        if (depth[i] > depth[R])
            R = i;

    depth[R] = 0, dfs4(R, 0), X = V[R];
    for (int i = 1; i <= N; i++)
        num[in[i]] = i;

    init(1, 1, N), chk[R] = true;

    for (int i = 2; i <= N; i++) {
        K = query(1, 1, N, 1, N), X += K[1], Y = K[2];
        toggle(1, 1, N, in[Y]);
        while (!chk[Y])
            chk[Y] = true, update(1, 1, N, in[Y], out[Y], -G[Y]), Y = parent[Y];
        ans[i] = X;
    }

    for (int i = 1; i <= N; i++)
        ans[i] = S - ans[i];

    cin >> Q;
    while (Q--) {
        cin >> X;
        cout << ans[X] << '\n';
    }

    return 0;
}
