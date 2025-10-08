#include <bits/stdc++.h>
using namespace std;

typedef array<array<int, 2>, 2> Val;
struct Node {
    Val T = Val{{{0, 0}, {0, 0}}}, F = Val{{{0, 0}, {0, 0}}};

    Node() {}
};

const int MAX = 500001;

int A[MAX], in[MAX], out[MAX], C[MAX], cnt,
    lazy[MAX * 4];
vector<int> adj[MAX];

Node tree[MAX * 4];

Node merge(Node X, Node Y) {
    Node res = Node();

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++) {
                if (X.T[i][k] && Y.T[k ^ 1][j])
                    res.T[i][j] = max(res.T[i][j], X.T[i][k] + Y.T[k ^ 1][j]);
                if (X.F[i][k] && Y.F[k ^ 1][j])
                    res.F[i][j] = max(res.F[i][j], X.F[i][k] + Y.F[k ^ 1][j]);
            }

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) {
            res.T[i][j] = max({res.T[i][j], X.T[i][j], Y.T[i][j]});
            res.F[i][j] = max({res.F[i][j], X.F[i][j], Y.F[i][j]});
        }

    return res;
}

void dfs(int node, int par) {
    in[node] = ++cnt;
    for (int i : adj[node]) {
        if (i == par)
            continue;
        dfs(i, node);
    }
    out[node] = ++cnt;
}

void init(int n, int s, int e) {
    lazy[n] = 0;
    if (s == e) {
        tree[n] = Node();
        if (C[s] == 0)
            tree[n].F[0][0] = 1;
        else if (C[s] == 1)
            tree[n].F[1][1] = 1;
        else if (C[s] == 2)
            tree[n].T[0][0] = 1;
        else if (C[s] == 3)
            tree[n].T[1][1] = 1;
    } else {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
        tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
    }
}

void lazy_update(int n, int s, int e) {
    if (lazy[n] == 0)
        return;
    swap(tree[n].T, tree[n].F);
    if (s ^ e)
        lazy[n << 1] ^= 1, lazy[n << 1 | 1] ^= 1;
    lazy[n] = 0;
}

void flip(int n, int s, int e, int l, int r) {
    lazy_update(n, s, e);
    if (r < s || e < l)
        return;
    else if (l <= s && e <= r)
        lazy[n] ^= 1, lazy_update(n, s, e);
    else {
        int m = s + e >> 1;
        flip(n << 1, s, m, l, r), flip(n << 1 | 1, m + 1, e, l, r);
        tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
    }
}

void solve() {
    int N, Q, X, U, V;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    for (int i = 1; i < N; i++) {
        cin >> U >> V;
        adj[U].push_back(V), adj[V].push_back(U);
    }
    cnt = 0, dfs(1, 0);

    fill(C + 1, C + (N << 1) + 1, 0);
    for (int i = 1; i <= N; i++)
        C[in[i]] = 0 + (A[i] << 1), C[out[i]] = 1 + (A[i] << 1);

    init(1, 1, N << 1);
    cout << tree[1].T[0][1] / 2 << '\n';

    cin >> Q;
    while (Q--) {
        cin >> X, flip(1, 1, N << 1, in[X], out[X]);
        cout << tree[1].T[0][1] / 2 << '\n';
    }

    for (int i = 1; i <= N; i++)
        adj[i].clear();
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;

    while (T--)
        solve();

    return 0;
}