#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef array<int, 2> pr;

const int MAX = 200001;

vector<pr> adj[MAX];
int parent[MAX], depth[MAX], P[MAX][2], L[MAX], QR[MAX][3], tree[MAX * 8], lazy[MAX * 8];
bool vst[MAX];

void dfs1(int node, int par) {
    for (pr i : adj[node]) {
        if (i[0] == par)
            continue;
        depth[i[0]] = depth[node] + i[1], parent[i[0]] = node;
        dfs1(i[0], node);
    }
}

void dfs2(int node, int par, int M) {
    P[node][0] = M, P[node][1] = depth[node] - depth[M];
    vst[node] = true;

    for (pr i : adj[node]) {
        if (i[0] == par || vst[i[0]])
            continue;
        dfs2(i[0], node, M);
    }
}

void lazy_update(int n, int s, int e) {
    if (lazy[n] == 0)
        return;
    tree[n] += lazy[n];
    if (s ^ e)
        lazy[n << 1] += lazy[n], lazy[n << 1 | 1] += lazy[n];
    lazy[n] = 0;
}

int query(int n, int s, int e, int l, int r) {
    lazy_update(n, s, e);
    if (r < s || e < l)
        return MAX;
    else if (l <= s && e <= r)
        return tree[n];
    else {
        int m = s + e >> 1;
        return min(query(n << 1, s, m, l, r), query(n << 1 | 1, m + 1, e, l, r));
    }
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
        tree[n] = min(tree[n << 1], tree[n << 1 | 1]);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, X, Y, Z, S;
    bool ans;

    vector<int> comp;

    cin >> N >> Q;
    for (int i = 1; i < N; i++) {
        cin >> X >> Y >> Z;
        adj[X].push_back({Y, Z});
        adj[Y].push_back({X, Z});
    }

    dfs1(1, 0), X = N;
    while (X) {
        comp.push_back(depth[X]);
        dfs2(X, parent[X], X), X = parent[X];
    }

    for (int i = 1; i <= Q; i++) {
        cin >> QR[i][0];
        if (QR[i][0] == 1)
            cin >> QR[i][1] >> QR[i][2];
        else {
            cin >> QR[i][1];
            QR[i][2] = QR[QR[i][1]][2], QR[i][1] = QR[QR[i][1]][1];
            continue;
        }

        QR[i][2] = max(0ll, QR[i][2] - P[QR[i][1]][1]), QR[i][1] = P[QR[i][1]][0];
        X = max(0ll, depth[QR[i][1]] - QR[i][2]), Y = min(depth[N], depth[QR[i][1]] + QR[i][2]);
        comp.push_back(X), comp.push_back(Y), QR[i][1] = X, QR[i][2] = Y;
    }

    sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end()), S = comp.size();

    for (int i = 1; i <= Q; i++) {
        QR[i][1] = lower_bound(comp.begin(), comp.end(), QR[i][1]) - comp.begin() + 1;
        QR[i][2] = lower_bound(comp.begin(), comp.end(), QR[i][2]) - comp.begin();

        if (QR[i][0] == 1)
            update(1, 1, S - 1, QR[i][1], QR[i][2], 1);
        else
            update(1, 1, S - 1, QR[i][1], QR[i][2], -1);

        ans = query(1, 1, S - 1, 1, S - 1) > 0;
        cout << (ans ? "YES" : "NO") << '\n';
    }

    return 0;
}