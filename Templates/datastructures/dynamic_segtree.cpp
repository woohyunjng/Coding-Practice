struct Node {
    int l, r, val;
    Node() { l = r = -1, val = 0; }
};

vector<Node> tree;

void update(int n, int s, int e, int x, int v) {
    if (s == e) {
        tree[n].val += v;
        return;
    }

    int m = s + e >> 1;
    if (x <= m) {
        if (tree[n].l == -1)
            tree[n].l = tree.size(), tree.push_back(Node());
        update(tree[n].l, s, m, x, v);
    } else {
        if (tree[n].r == -1)
            tree[n].r = tree.size(), tree.push_back(Node());
        update(tree[n].r, m + 1, e, x, v);
    }

    tree[n].val = (tree[n].l == -1 ? 0 : tree[tree[n].l].val) + (tree[n].r == -1 ? 0 : tree[tree[n].r].val);
}

int query(int n, int s, int e, int l, int r) {
    if (n == -1 || r < s || e < l)
        return 0;
    if (l <= s && e <= r)
        return tree[n].val;
    int m = s + e >> 1;
    return query(tree[n].l, s, m, l, r) + query(tree[n].r, m + 1, e, l, r);
}

void update(int x, int v) { update(0, 0, 200000, x, v); }
int query(int l, int r) { return query(0, 0, 200000, l, r); }