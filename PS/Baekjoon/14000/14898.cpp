#include <bits/stdc++.h>

#define MAX 1000100
using namespace std;

struct Node {
    int l, r, val;
    Node() { l = r = -1, val = 0; }
    Node(int l, int r, int val) : l(l), r(r), val(val) {}
};

vector<Node> tree;
vector<int> root;

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

int A[MAX];
map<int, int> mp;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, L, R, X = 0;
    Node node;
    cin >> N;

    tree.reserve(N * 50), root.reserve(N + 1);

    tree.push_back(Node()), root.push_back(0);
    init(0, 1, N);

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        node = Node(tree[root[i - 1]].l, tree[root[i - 1]].r, tree[root[i - 1]].val);
        root.push_back(tree.size()), tree.push_back(node);

        if (mp.find(A[i]) != mp.end())
            update(root[i], 1, N, mp[A[i]], -1);
        mp[A[i]] = i;
        update(root[i], 1, N, i, 1);
    }

    cin >> Q;
    while (Q--) {
        cin >> L >> R, L += X;
        X = query(root[R], 1, N, L, R);
        cout << X << '\n';
    }

    return 0;
}