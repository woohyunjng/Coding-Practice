#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

const int MAX = 100001;
const int MD = 200000000000000;
const int INF = 0x3f3f3f3f3f3f3f3f;

struct Node {
    int l = -1, r = -1, val = INF, lazy = 0;
    Node(int l = -1, int r = -1) : l(l), r(r) {};
};

int A[MAX], B[MAX], D[MAX], S[MAX];
vector<pr> adj[MAX], arr;
vector<Node> tree[MAX];

void lazy_update(int t, int n, int s, int e) {
    if (tree[t][n].lazy == 0)
        return;
    tree[t][n].val += tree[t][n].lazy;
    if (s ^ e) {
        if (tree[t][n].l != -1)
            tree[t][tree[t][n].l].lazy += tree[t][n].lazy;
        if (tree[t][n].r != -1)
            tree[t][tree[t][n].r].lazy += tree[t][n].lazy;
    }
    tree[t][n].lazy = 0;
}

void update(int t, int n, int s, int e, int x, int v) {
    lazy_update(t, n, s, e);
    if (x < s || e < x)
        return;
    else if (s == e)
        tree[t][n].val = min(tree[t][n].val, v);
    else {
        int m = s + e >> 1;
        if (x <= m || tree[t][n].l != -1) {
            if (tree[t][n].l == -1)
                tree[t][n].l = tree[t].size(), tree[t].push_back(Node());
            update(t, tree[t][n].l, s, m, x, v);
        }
        if (m + 1 <= x || tree[t][n].r != -1) {
            if (tree[t][n].r == -1)
                tree[t][n].r = tree[t].size(), tree[t].push_back(Node());
            update(t, tree[t][n].r, m + 1, e, x, v);
        }
        tree[t][n].val = min(tree[t][n].l == -1 ? INF : tree[t][tree[t][n].l].val,
                             tree[t][n].r == -1 ? INF : tree[t][tree[t][n].r].val);
    }
}

void update_s(int t, int n, int s, int e, int l, int r, int v) {
    lazy_update(t, n, s, e);
    if (r < s || e < l)
        return;
    else if (l <= s && e <= r)
        tree[t][n].lazy = v, lazy_update(t, n, s, e);
    else {
        int m = s + e >> 1;
        if (tree[t][n].l != -1)
            update_s(t, tree[t][n].l, s, m, l, r, v);
        if (tree[t][n].r != -1)
            update_s(t, tree[t][n].r, m + 1, e, l, r, v);
        tree[t][n].val = min(tree[t][n].l == -1 ? INF : tree[t][tree[t][n].l].val,
                             tree[t][n].r == -1 ? INF : tree[t][tree[t][n].r].val);
    }
}

int query(int t, int n, int s, int e, int l, int r) {
    lazy_update(t, n, s, e);
    if (r < s || e < l)
        return INF;
    else if (l <= s && e <= r)
        return tree[t][n].val;
    else {
        int m = s + e >> 1, res = INF;
        if (tree[t][n].l != -1)
            res = min(res, query(t, tree[t][n].l, s, m, l, r));
        if (tree[t][n].r != -1)
            res = min(res, query(t, tree[t][n].r, m + 1, e, l, r));
        return res;
    }
}

void fetch(int t, int n, int s, int e) {
    lazy_update(t, n, s, e);
    if (s == e)
        arr.push_back({s, tree[t][n].val});
    else {
        int m = s + e >> 1;
        if (tree[t][n].l != -1)
            fetch(t, tree[t][n].l, s, m);
        if (tree[t][n].r != -1)
            fetch(t, tree[t][n].r, m + 1, e);
    }
}

void dfs(int node, int par) {
    int X, L, R;
    vector<pr> lupd, rupd, pupd;

    tree[node].push_back(Node()), S[node] = 1;
    update(node, 0, -MD, MD, D[node] - B[node], A[node]);
    update(node, 0, -MD, MD, D[node] + 1, 0);

    for (pr i : adj[node]) {
        if (i[0] == par)
            continue;
        D[i[0]] = D[node] + i[1], dfs(i[0], node);
        update(i[0], 0, -MD, MD, D[node] + 1, query(i[0], 0, -MD, MD, D[node] + 1, D[i[0]]));

        if (S[node] < S[i[0]])
            swap(tree[node], tree[i[0]]);
        arr.clear(), fetch(i[0], 0, -MD, MD), vector<Node>().swap(tree[i[0]]);

        L = R = INF, lupd.clear(), rupd.clear(), pupd.clear();
        for (pr &j : arr) {
            if (j[0] <= D[node] + 1)
                L = R = j[1];
            X = j[1];
            if (j[0] <= D[node]) {
                X += query(node, 0, -MD, MD, -MD, D[node] * 2 - j[0] + 1);
                lupd.push_back({D[node], j[1]}), rupd.push_back({D[node] + 1, j[1]});
            } else {
                X += query(node, 0, -MD, MD, -MD, j[0]);
                lupd.push_back({D[node] * 2 - j[0] + 1, j[1]}), rupd.push_back({j[0], j[1]});
            }
            j[1] = X;
        }

        X = D[node], sort(lupd.rbegin(), lupd.rend());
        for (pr j : lupd) {
            if (j[0] < X)
                update_s(node, 0, -MD, MD, j[0] + 1, X, L), X = j[0];
            L = min(L, j[1]);
        }
        update_s(node, 0, -MD, MD, -MD, X, L);

        X = D[node] + 1, sort(rupd.begin(), rupd.end());
        for (pr j : rupd) {
            if (X < j[0])
                update_s(node, 0, -MD, MD, X, j[0] - 1, R), X = j[0];
            R = min(R, j[1]);
        }
        update_s(node, 0, -MD, MD, X, MD, R);

        for (pr j : arr)
            update(node, 0, -MD, MD, j[0], j[1]);
        S[node] += S[i[0]];
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, U, V, W, ans;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i] >> B[i];

    for (int i = 1; i < N; i++) {
        cin >> U >> V >> W;
        adj[U].push_back({V, W}), adj[V].push_back({U, W});
    }

    dfs(1, 0), ans = query(1, 0, -MD, MD, -MD, 0);
    cout << ans << '\n';

    return 0;
}