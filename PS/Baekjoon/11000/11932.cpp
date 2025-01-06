#include <bits/stdc++.h>
#define int long long

#define MAX 100100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

struct Node {
    int l, r, val;
    Node() { l = r = -1, val = 0; }
    Node(int l, int r, int val) : l(l), r(r), val(val) {}
};

int N, A[MAX], parent[MAX][20], depth[MAX], rt[MAX];
vector<int> adj[MAX], root;
vector<Node> tree;

void init(int n, int s, int e) {
    if (s == e)
        return;

    int m = s + e >> 1;
    tree[n].l = tree.size(), tree.push_back(Node());
    tree[n].r = tree.size(), tree.push_back(Node());

    init(tree[n].l, s, m), init(tree[n].r, m + 1, e);
    tree[n].val = tree[tree[n].l].val + tree[tree[n].r].val;
}

void update(int n, int s, int e, int x, int v) {
    tree[n].val += v;
    if (s == e)
        return;

    int m = s + e >> 1;
    if (x <= m) {
        tree.push_back(Node(tree[tree[n].l].l, tree[tree[n].l].r, tree[tree[n].l].val));
        tree[n].l = tree.size() - 1;
        update(tree[n].l, s, m, x, v);
    } else {
        tree.push_back(Node(tree[tree[n].r].l, tree[tree[n].r].r, tree[tree[n].r].val));
        tree[n].r = tree.size() - 1;
        update(tree[n].r, m + 1, e, x, v);
    }
}

int query(int n, int s, int e, int l, int r) {
    if (n == -1 || r < s || e < l)
        return 0;
    if (l <= s && e <= r)
        return tree[n].val;
    int m = s + e >> 1;
    return query(tree[n].l, s, m, l, r) + query(tree[n].r, m + 1, e, l, r);
}

void dfs(int node, int par) {
    parent[node][0] = par;
    for (int i = 1; i < 20; i++)
        parent[node][i] = parent[parent[node][i - 1]][i - 1];

    Node prev = tree[root[rt[par]]], nw = Node(prev.l, prev.r, prev.val);
    root.push_back(tree.size()), tree.push_back(nw);
    rt[node] = root.size() - 1, update(root.back(), 1, N, A[node], 1);

    for (int i : adj[node])
        if (i != par)
            depth[i] = depth[node] + 1, dfs(i, node);
}

int lca(int X, int Y) {
    if (depth[X] < depth[Y])
        swap(X, Y);

    int diff = depth[X] - depth[Y];
    for (int i = 0; diff; i++) {
        if (diff & 1)
            X = parent[X][i];
        diff >>= 1;
    }

    for (int i = 19; i >= 0; i--)
        if (parent[X][i] != parent[Y][i])
            X = parent[X][i], Y = parent[Y][i];
    if (X != Y)
        X = parent[X][0];
    return X;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int M, X, Y, Z, W, K, st, en, mid, res, cnt;
    bool flag;
    vector<int> comp;
    tree.push_back(Node()), root.push_back(0);

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        cin >> A[i], comp.push_back(A[i]);
    sort(comp.begin(), comp.end());
    for (int i = 1; i <= N; i++)
        A[i] = lower_bound(comp.begin(), comp.end(), A[i]) - comp.begin() + 1;

    for (int i = 1; i < N; i++) {
        cin >> X >> Y;
        adj[X].push_back(Y), adj[Y].push_back(X);
    }

    init(0, 1, N), dfs(1, 0);

    while (M--) {
        cin >> X >> Y >> K;
        Z = lca(X, Y), flag = false;

        if (Y == Z)
            Y = Z = parent[Z][0];
        else if (X == Z)
            X = Z = parent[Z][0];
        else
            W = parent[Z][0], flag = true;

        X = root[rt[X]],
        Y = root[rt[Y]], Z = root[rt[Z]], W = root[rt[W]];
        st = 1, en = N, res = -1;

        while (st <= en) {
            mid = st + en >> 1;
            if (flag)
                cnt = query(X, 1, N, 1, mid) + query(Y, 1, N, 1, mid) - query(Z, 1, N, 1, mid) - query(W, 1, N, 1, mid);
            else
                cnt = query(X, 1, N, 1, mid) + query(Y, 1, N, 1, mid) - 2 * query(Z, 1, N, 1, mid);
            if (cnt >= K)
                res = mid, en = mid - 1;
            else
                st = mid + 1;
        }

        cout << comp[res - 1] << '\n';
    }

    return 0;
}