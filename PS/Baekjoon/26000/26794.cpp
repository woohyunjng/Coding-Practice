#include <bits/stdc++.h>
using namespace std;

const int MAX = 1'000'002;

int T[MAX], U[MAX], V[MAX],
    par[MAX],
    RT[MAX], dfs_ordering,
    in[MAX], out[MAX], L[MAX], R[MAX],
    tree[2][MAX * 4], lazy[MAX * 4];
bool vst[MAX];

vector<int> adj[MAX];

void lazy_update(int n, int s, int e) {
    if (lazy[n] == 0)
        return;
    tree[0][n] += lazy[n];
    if (s ^ e)
        lazy[n << 1] += lazy[n], lazy[n << 1 | 1] += lazy[n];
    lazy[n] = 0;
}

void update(int t, int n, int s, int e, int l, int r, int v) {
    lazy_update(n, s, e);
    if (r < s || e < l)
        return;
    else if (l <= s && e <= r) {
        if (t == 0)
            lazy[n] += v, lazy_update(n, s, e);
        else
            tree[t][n] += v;
    } else {
        int m = s + e >> 1;
        update(t, n << 1, s, m, l, r, v), update(t, n << 1 | 1, m + 1, e, l, r, v);
        tree[t][n] = tree[t][n << 1] + tree[t][n << 1 | 1];
    }
}

int query(int t, int n, int s, int e, int l, int r) {
    lazy_update(n, s, e);
    if (r < s || e < l)
        return 0;
    else if (l <= s && e <= r)
        return tree[t][n];
    else {
        int m = s + e >> 1;
        return query(t, n << 1, s, m, l, r) + query(t, n << 1 | 1, m + 1, e, l, r);
    }
}

void dfs(int node) {
    in[node] = dfs_ordering++, vst[node] = true;
    for (int i : adj[node]) {
        if (i < 0)
            L[-i] = dfs_ordering;
        else
            dfs(i);
    }

    out[node] = dfs_ordering - 1;
    for (int i : adj[node])
        if (i < 0)
            R[-i] = out[node];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int Q, N = 1, ans;
    char C;

    cin >> Q;

    fill(par, par + Q + 2, -1);
    fill(L, L + Q + 2, -1), fill(R, R + Q + 2, -1);

    par[1] = 0, adj[0].push_back(-1);
    RT[0] = 0, RT[1] = 1;

    for (int i = 0; i < Q; i++) {
        cin >> C >> U[i], U[i]--;
        if (C == '?')
            T[i] = 0;
        else if (C == 'W') {
            T[i] = 1, V[i] = ++N, RT[N] = N;
            adj[U[i]].push_back(-N), par[N] = U[i];
        } else {
            T[i] = 2, V[i] = ++N, RT[N] = RT[U[i]], adj[U[i]].push_back(N);
            par[N] = par[U[i]];
        }
    }

    for (int i = 0; i <= N; i++) {
        if (vst[i])
            continue;
        dfs(i);
    }

    update(0, 1, 0, N, in[0], in[0], 1);
    update(0, 1, 0, N, L[1], R[1], 1);

    for (int i = 0; i < Q; i++) {
        if (T[i] == 0) {
            ans = query(0, 1, 0, N, in[U[i]], in[U[i]]);
            if (par[RT[U[i]]] != -1)
                ans++;
            ans += query(1, 1, 0, N, L[RT[U[i]]], R[RT[U[i]]]);
            cout << ans << '\n';
        } else if (T[i] == 1) {
            update(0, 1, 0, N, in[U[i]], in[U[i]], 1);
            update(0, 1, 0, N, L[V[i]], R[V[i]], 1);
        } else {
            update(0, 1, 0, N, L[RT[V[i]]], R[RT[V[i]]], 1);
            update(1, 1, 0, N, in[V[i]], in[V[i]], 1);
            if (par[RT[V[i]]] != -1)
                update(0, 1, 0, N, in[par[RT[V[i]]]], in[par[RT[V[i]]]], 1);
        }
    }

    return 0;
}