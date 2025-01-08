#include <bits/stdc++.h>
#define int long long

using namespace std;

struct Node {
    int l, r, val;
    Node() { l = r = -1, val = 0; }
    Node(int l, int r, int val) : l(l), r(r), val(val) {}
};

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

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int M, T, L, R, X, st, en, mid, res, cnt, idx = 0;
    vector<int> cur, root;

    Node prev, node, lnode, rnode;
    cur.push_back(0);

    tree.push_back(Node()), root.push_back(0);
    init(root.back(), 0, (1 << 19) - 1);

    cin >> M;

    while (M--) {
        cin >> T;
        if (T == 1) {
            cin >> X;
            prev = tree[root[cur.back()]], node = Node(prev.l, prev.r, prev.val);
            cur.push_back(root.size()), root.push_back(tree.size()), tree.push_back(node);
            update(root[cur.back()], 0, (1 << 19) - 1, X, 1);
        } else if (T == 2) {
            cin >> L >> R >> X;
            res = 0, idx = 18;

            lnode = tree[root[cur[L - 1]]], rnode = tree[root[cur[R]]];

            while (idx >= 0) {
                mid = st + en >> 1;
                if (X & (1 << idx)) {
                    cnt = tree[rnode.l].val - tree[lnode.l].val;
                    if (cnt == 0)
                        res |= 1 << idx, lnode = tree[lnode.r], rnode = tree[rnode.r];
                    else
                        lnode = tree[lnode.l], rnode = tree[rnode.l];
                } else {
                    cnt = tree[rnode.r].val - tree[lnode.r].val;
                    if (cnt > 0)
                        res |= 1 << idx, lnode = tree[lnode.r], rnode = tree[rnode.r];
                    else
                        lnode = tree[lnode.l], rnode = tree[rnode.l];
                }
                idx--;
            }
            cout << st << '\n';
        } else if (T == 3) {
            cin >> X;
            while (X--)
                cur.pop_back();
        } else if (T == 4) {
            cin >> L >> R >> X;
            cout << query(root[cur[R]], 0, (1 << 19) - 1, 1, X) - query(root[cur[L - 1]], 0, (1 << 19) - 1, 1, X) << '\n';
        } else {
            cin >> L >> R >> X;
            st = 0, en = (1 << 19) - 1, res = 0;

            lnode = tree[root[cur[L - 1]]], rnode = tree[root[cur[R]]];

            while (st < en) {
                mid = st + en >> 1, res = tree[rnode.l].val - tree[lnode.l].val;
                if (res < X)
                    X -= res, st = mid + 1, lnode = tree[lnode.r], rnode = tree[rnode.r];
                else
                    en = mid, lnode = tree[lnode.l], rnode = tree[rnode.l];
            }

            cout << st << '\n';
        }
    }

    return 0;
}