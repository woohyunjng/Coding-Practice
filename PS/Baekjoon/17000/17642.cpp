#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

const int MAX = 200001;

struct Node {
    int LS = 0, RS = 0, Fval = 0, Lval = 0, Rval = 0, val = 0, S = 0, M = 0;
    Node(int V) {
        M = max(0ll, -V), S = V;
        LS = RS = max(0ll, V), Fval = Lval = Rval = val = abs(V);
    };
    Node() {};
};

vector<pr> adj[MAX];
Node tree[MAX * 4];
int C[MAX], in[MAX], out[MAX], cnt;

void dfs(int node, int par) {
    for (pr i : adj[node]) {
        if (i[0] == par)
            continue;
        in[i[1]] = ++cnt, dfs(i[0], node), out[i[1]] = ++cnt;
    }
}

Node merge(Node X, Node Y) {
    Node res;
    res.S = X.S + Y.S, res.M = max(Y.M, X.M - Y.S);
    res.LS = max({X.LS, X.S + Y.LS}), res.RS = max({Y.RS, X.RS + Y.S});
    res.Lval = max({X.Lval, X.Fval + Y.LS, -X.S + Y.Lval}), res.Rval = max({Y.Rval, X.Rval + Y.S, X.M + Y.Fval});
    res.Fval = max({X.Fval + Y.S, -X.S + Y.Fval});
    res.val = max({X.val, Y.val, X.Rval + Y.LS, X.M + Y.Lval});
    return res;
}

void update(int n, int s, int e, int x, int v) {
    if (x < s || e < x)
        return;
    else if (s == e)
        tree[n] = Node(v);
    else {
        int m = s + e >> 1;
        update(n << 1, s, m, x, v), update(n << 1 | 1, m + 1, e, x, v);
        tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
    }
}

Node query(int n, int s, int e, int l, int r) {
    if (r < s || e < l)
        return Node();
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

    int N, Q, W, U, V, Z, last_ans = 0;

    cin >> N >> Q >> W;
    for (int i = 1; i < N; i++) {
        cin >> U >> V >> Z, C[i] = Z;
        adj[U].push_back({V, i}), adj[V].push_back({U, i});
    }

    dfs(1, 0);
    for (int i = 1; i < N; i++)
        update(1, 1, (N - 1) << 1, in[i], C[i]), update(1, 1, (N - 1) << 1, out[i], -C[i]);

    while (Q--) {
        cin >> U >> V;
        U = (U + last_ans) % (N - 1) + 1, V = (V + last_ans) % W, C[U] = V;
        update(1, 1, (N - 1) << 1, in[U], C[U]), update(1, 1, (N - 1) << 1, out[U], -C[U]);
        last_ans = tree[1].val, cout << last_ans << '\n';
    }

    return 0;
}