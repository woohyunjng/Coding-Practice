struct Line {
    int A, B;
    int get(int X) { return A * X + B; }

    Line(int A, int B) : A(A), B(B) {}
};

struct Node {
    int s, e, l = -1, r = -1;
    Line line;

    Node(int s, int e, Line line) : s(s), e(e), line(line) {}
};

vector<Node> tree[MAX];

void update(int t, int n, Line v) {
    int s = tree[t][n].s, e = tree[t][n].e, m = s + e >> 1;
    Line low = tree[t][n].line, high = v;

    if (low.get(s) < high.get(s))
        swap(low, high);
    if (low.get(e) >= high.get(e)) {
        tree[t][n].line = low;
        return;
    }

    if (low.get(m) > high.get(m)) {
        tree[t][n].line = low;
        if (tree[t][n].r == -1) {
            tree[t][n].r = tree[t].size();
            tree[t].push_back(Node(m + 1, e, Line(0, 0)));
        }
        update(t, tree[t][n].r, high);
    } else {
        tree[t][n].line = high;
        if (tree[t][n].l == -1) {
            tree[t][n].l = tree[t].size();
            tree[t].push_back(Node(s, m, Line(0, 0)));
        }
        update(t, tree[t][n].l, low);
    }
}

int query(int t, int n, int v) {
    if (n == -1)
        return 0;
    int s = tree[t][n].s, e = tree[t][n].e, m = s + e >> 1;

    if (v <= m)
        return max(tree[t][n].line.get(v), query(t, tree[t][n].l, v));
    return max(tree[t][n].line.get(v), query(t, tree[t][n].r, v));
}