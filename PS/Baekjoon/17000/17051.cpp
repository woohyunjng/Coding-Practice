#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;

const int MAX = 100001;

vector<pr> adj[MAX];
vector<int> comp;

int sz[MAX], A[MAX], ans, tree[MAX * 8], S;
bool chk[MAX];

int get_sz(int node, int par) {
    sz[node] = 1;
    for (pr i : adj[node]) {
        if (i[0] == par || chk[i[0]])
            continue;
        sz[node] += get_sz(i[0], node);
    }
    return sz[node];
}

int get_cent(int node, int par, int cap) {
    for (pr i : adj[node]) {
        if (i[0] == par || chk[i[0]])
            continue;
        if (sz[i[0]] * 2 > cap)
            return get_cent(i[0], node, cap);
    }
    return node;
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

void update(int n, int s, int e, int idx, int v) {
    if (idx < s || e < idx)
        return;
    else if (s == e)
        tree[n] += v;
    else {
        int m = s + e >> 1;
        update(n << 1, s, m, idx, v), update(n << 1 | 1, m + 1, e, idx, v);
        tree[n] = tree[n << 1] + tree[n << 1 | 1];
    }
}

int query(int n) {
    n = lower_bound(comp.begin(), comp.end(), n) - comp.begin() + 1;
    return query(1, 1, S, 1, n);
}

void update(int n, int v) {
    n = lower_bound(comp.begin(), comp.end(), n) - comp.begin() + 1;
    update(1, 1, S, n, v);
}

void dfs0(int node, int par, int val, int mn, int sm1, int sm2) {
    comp.push_back(-val);
    if (A[node] + mn >= 0)
        comp.push_back(sm2);

    for (pr i : adj[node]) {
        if (i[0] == par || chk[i[0]])
            continue;
        dfs0(i[0], node, min(val, sm1 + A[node] - i[1]), min(0ll, mn + A[node]) - i[1], sm1 + A[node] - i[1], sm2 + A[i[0]] - i[1]);
    }
}

void dfs1(int node, int par, int val, int sm) {
    update(-val, 1);

    for (pr i : adj[node]) {
        if (i[0] == par || chk[i[0]])
            continue;
        dfs1(i[0], node, min(val, sm + A[node] - i[1]), sm + A[node] - i[1]);
    }
}

void dfs2(int node, int par, int mn, int sm) {
    if (A[node] + mn >= 0)
        ans += query(sm);

    for (pr i : adj[node]) {
        if (i[0] == par || chk[i[0]])
            continue;
        dfs2(i[0], node, min(0ll, mn + A[node]) - i[1], sm + A[i[0]] - i[1]);
    }
}

void dfs3(int node, int par, int val, int sm) {
    update(-val, -1);

    for (pr i : adj[node]) {
        if (i[0] == par || chk[i[0]])
            continue;
        dfs3(i[0], node, min(val, sm + A[node] - i[1]), sm + A[node] - i[1]);
    }
}

void dnc(int node) {
    int cent = get_cent(node, -1, get_sz(node, -1));
    chk[cent] = true, comp.clear();

    comp.push_back(0);
    for (pr i : adj[cent]) {
        if (chk[i[0]])
            continue;
        dfs0(i[0], cent, A[cent] - i[1], -i[1], A[cent] - i[1], A[i[0]] - i[1]);
    }

    sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end()), S = comp.size();

    update(0, 1);
    for (pr i : adj[cent]) {
        if (chk[i[0]])
            continue;
        dfs1(i[0], cent, A[cent] - i[1], A[cent] - i[1]);
    }

    ans += query(0);
    for (pr i : adj[cent]) {
        if (chk[i[0]])
            continue;
        dfs3(i[0], cent, A[cent] - i[1], A[cent] - i[1]);
        dfs2(i[0], cent, -i[1], A[i[0]] - i[1]);
        dfs1(i[0], cent, A[cent] - i[1], A[cent] - i[1]);
    }

    update(0, -1);
    for (pr i : adj[cent]) {
        if (chk[i[0]])
            continue;
        dfs3(i[0], cent, A[cent] - i[1], A[cent] - i[1]);
    }

    for (pr i : adj[cent]) {
        if (chk[i[0]])
            continue;
        dnc(i[0]);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, Y, Z;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    for (int i = 1; i < N; i++) {
        cin >> X >> Y >> Z;
        adj[X].push_back({Y, Z}), adj[Y].push_back({X, Z});
    }

    dnc(1);

    ans -= N;
    cout << ans << '\n';

    return 0;
}