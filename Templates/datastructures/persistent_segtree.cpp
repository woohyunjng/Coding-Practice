struct Node {
    int l = -1, r = -1, val = 0;

    Node() : l(-1), r(-1), val(0) {};
    Node(int l, int r, int val) : l(l), r(r), val(val) {};
};

vector<Node> tree;
vector<int> root;

void init(int n, int s, int e) {
    if (s ^ e) {
        int m = s + e >> 1;
        tree[n].l = tree.size(), tree.push_back(Node());
        tree[n].r = tree.size(), tree.push_back(Node());

        init(tree[n].l, s, m), init(tree[n].r, m + 1, e);
    }
}

int query(int n, int s, int e, int l, int r) {
    if (r < s || e < l)
        return 0;
    else if (l <= s && e <= r)
        return tree[n].val;
    else {
        int m = s + e >> 1;
        return query(tree[n].l, s, m, l, r) + query(tree[n].r, m + 1, e, l, r);
    }
}

void update(int n, int s, int e, int x, int v) {
    tree[n].val += v;
    if (s == e)
        return;
    int m = s + e >> 1;
    if (x <= m) {
        tree.push_back(Node(tree[tree[n].l].l, tree[tree[n].l].r, tree[tree[n].l].val));
        tree[n].l = (int)tree.size() - 1;
        update(tree[n].l, s, m, x, v);
    } else {
        tree.push_back(Node(tree[tree[n].r].l, tree[tree[n].r].r, tree[tree[n].r].val));
        tree[n].r = (int)tree.size() - 1;
        update(tree[n].r, m + 1, e, x, v);
    }
}

// tree.push_back(Node()), root.push_back(0), init(root[0], 1, N); 시작할때
// tree.push_back(Node(tree[root.back()].l, tree[root.back()].r, tree[root.back()].val)), root.push_back(tree.size() - 1); 루트 추가하기