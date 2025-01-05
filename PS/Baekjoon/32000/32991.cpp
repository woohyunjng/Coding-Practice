#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int subtree_in[MAX], subtree_out[MAX], child_in[MAX], child_out[MAX], cnt = 1, node_num[MAX], X[MAX], parent[MAX], arr[MAX];
pr tree[MAX * 4], lazy[MAX * 4];
vector<int> adj[MAX];

void dfs(int node) {
    subtree_in[node] = child_in[node] = cnt;
    for (int i : adj[node])
        node_num[i] = cnt++, arr[cnt - 1] = i;
    child_out[node] = cnt;
    for (int i : adj[node])
        dfs(i);
    subtree_out[node] = cnt;
}

pr merge(pr A, pr B) { return {A.first * B.first % MOD, (A.second * B.first + B.second) % MOD}; }

void init(int n, int s, int e) {
    lazy[n] = {1, 0};
    if (s == e) {
        tree[n] = {0, X[arr[s]]};
        return;
    }
    init(n << 1, s, (s + e) >> 1), init(n << 1 | 1, ((s + e) >> 1) + 1, e);
    tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
}

void propagate(int n, int s, int e) {
    if (lazy[n] == pr{1, 0})
        return;
    if (s != e) {
        lazy[n << 1] = merge(lazy[n << 1], lazy[n]);
        lazy[n << 1 | 1] = merge(lazy[n << 1 | 1], lazy[n]);
    }
    if (s == e)
        tree[n] = merge(tree[n], lazy[n]);
    lazy[n] = {1, 0};
}

pr query(int n, int s, int e, int idx) {
    propagate(n, s, e);
    if (s > idx || e < idx)
        return {1, 0};
    if (s == e)
        return tree[n];
    pr left = query(n << 1, s, (s + e) >> 1, idx), right = query(n << 1 | 1, ((s + e) >> 1) + 1, e, idx);
    if (left != pr{1, 0})
        return left;
    return right;
}

void update(int n, int s, int e, int l, int r, pr val) {
    propagate(n, s, e);
    if (s > r || e < l)
        return;
    if (l <= s && e <= r) {
        lazy[n] = merge(lazy[n], val);
        propagate(n, s, e);
        return;
    }
    update(n << 1, s, (s + e) >> 1, l, r, val), update(n << 1 | 1, ((s + e) >> 1) + 1, e, l, r, val);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, P, T, V, A, B;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> X[i];
    for (int i = 2; i <= N; i++)
        cin >> parent[i], adj[parent[i]].push_back(i);

    node_num[1] = cnt++, arr[cnt - 1] = 1;
    dfs(1), init(1, 1, N);

    cin >> Q;
    while (Q--) {
        cin >> T >> V;
        if (T == 1) {
            cin >> A >> B;
            update(1, 1, N, child_in[V], child_out[V] - 1, {A, B});
            update(1, 1, N, node_num[V], node_num[V], {A, B});
            if (V != 1)
                update(1, 1, N, node_num[parent[V]], node_num[parent[V]], {A, B});
        } else if (T == 2) {
            cin >> A >> B;
            update(1, 1, N, subtree_in[V], subtree_out[V] - 1, {A, B});
            update(1, 1, N, node_num[V], node_num[V], {A, B});
        } else
            cout << query(1, 1, N, node_num[V]).second << '\n';
    }

    return 0;
}