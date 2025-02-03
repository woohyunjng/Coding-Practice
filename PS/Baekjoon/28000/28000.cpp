#include <bits/stdc++.h>
#define int long long

#define MAX 200000

using namespace std;
typedef array<int, 2> pr;
typedef array<int, 3> tp;

vector<pr> queries[MAX];
vector<int> adj[MAX];
set<tp> st;

int N, M, C[MAX], ans[MAX], in[MAX], top[MAX], parent[MAX], depth[MAX], sz[MAX], tree[MAX * 4], cnt = 0;

void dfs(int node, int par) {
    depth[node] = depth[par] + 1, parent[node] = par, sz[node] = 1;
    for (int &i : adj[node]) {
        if (i == par)
            continue;
        dfs(i, node), sz[node] += sz[i];
        if (adj[node][0] == par || sz[adj[node][0]] < sz[i])
            swap(adj[node][0], i);
    }
}

void hld(int node, int par) {
    in[node] = ++cnt;
    for (int i : adj[node]) {
        if (i == par)
            continue;
        top[i] = i == adj[node][0] ? top[node] : i;
        hld(i, node);
    }
}

int query(int n, int s, int e, int l, int r) {
    if (r < s || e < l)
        return 0;
    else if (l <= s && e <= r)
        return tree[n];
    else {
        int m = s + e >> 1;
        return query(n << 1, s, m, l, r) + query(n << 1 | 1, m + 1, e, l, r);
    }
}

void update(int n, int s, int e, int x, int v) {
    if (x < s || e < x)
        return;
    else if (s == e)
        tree[n] += v;
    else {
        int m = s + e >> 1;
        update(n << 1, s, m, x, v), update(n << 1 | 1, m + 1, e, x, v);
        tree[n] = tree[n << 1] + tree[n << 1 | 1];
    }
}

void upd(int s, int e, int v) {
    set<tp>::iterator iter;
    tp K;

    iter = prev(st.lower_bound({s, N + 1, 0})), K = *iter;
    while (K[1] <= e) {
        st.erase(iter), update(1, 1, M, K[2], -(K[1] - K[0] + 1));
        if (K[0] < s)
            st.insert({K[0], s - 1, K[2]}), update(1, 1, M, K[2], s - K[0]);
        iter = st.lower_bound({s, N + 1, 0}), K = iter == st.end() ? (tp){0, N + 1, 0} : *iter;
    }
    if (iter != st.end() && K[0] <= e) {
        st.erase(iter), update(1, 1, M, K[2], -(K[1] - K[0] + 1));
        if (K[0] < s)
            st.insert({K[0], s - 1, K[2]}), update(1, 1, M, K[2], s - K[0]);
        st.insert({e + 1, K[1], K[2]}), update(1, 1, M, K[2], K[1] - e);
    }
    st.insert({s, e, v}), update(1, 1, M, v, e - s + 1);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int Q, X, Y;
    cin >> N >> M >> Q;

    for (int i = 1; i < N; i++) {
        cin >> X >> Y;
        adj[X].push_back(Y), adj[Y].push_back(X);
    }

    dfs(1, 0), top[1] = 1, hld(1, 0);
    st.insert({1, N, 1}), update(1, 1, M, 1, N);

    for (int i = 1; i <= M; i++)
        cin >> C[i];

    for (int i = 1; i <= Q; i++) {
        cin >> X >> Y;
        queries[Y].push_back({i, X});
    }

    for (int i = 2; i <= M; i++) {
        X = C[i - 1], Y = C[i];
        while (top[X] ^ top[Y]) {
            if (depth[top[X]] < depth[top[Y]])
                swap(X, Y);
            upd(in[top[X]], in[X], i), X = parent[top[X]];
        }
        if (depth[X] > depth[Y])
            swap(X, Y);
        upd(in[X], in[Y], i);

        for (pr j : queries[i])
            ans[j[0]] = query(1, 1, M, j[1] + 1, i);
    }

    for (int i = 1; i <= Q; i++)
        cout << max(1ll, ans[i]) << '\n';

    return 0;
}