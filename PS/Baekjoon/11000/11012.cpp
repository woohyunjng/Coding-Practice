#include <bits/stdc++.h>
#define int long long

#define MAX 100100
using namespace std;

struct Node {
    int l, r, val;
    Node() { l = r = -1, val = 0; }
    Node(int l, int r, int val) : l(l), r(r), val(val) {}
};

class PersistentSegTree {
  private:
    vector<Node> tree;
    vector<int> root, arr;

    void init(int n, int s, int e) {
        if (s == e) {
            tree[n].val = arr[s];
            return;
        }

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

  public:
    int N;

    PersistentSegTree(int n) : N(n), arr(n + 1, 0) {
        tree.push_back(Node());
        root.push_back(0);
    }

    int new_tree() {
        Node prev = tree[root.back()], node = Node(prev.l, prev.r, prev.val);
        root.push_back(tree.size()), tree.push_back(node);
        return root.size() - 1;
    }

    void init() { init(root.back(), 1, N); }
    void update(int rt, int x, int v) { update(root[rt], 1, N, x, v); }
    int query(int rt, int l, int r) { return query(root[rt], 1, N, l, r); }
};

vector<int> arr[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, M, A, B, C, D, res;

    cin >> T;

    while (T--) {
        cin >> N >> M;
        res = 0;

        PersistentSegTree tree(MAX);
        tree.init();

        for (int i = 1; i <= N; i++) {
            cin >> A >> B;
            arr[A + 1].push_back(B);
        }

        for (int i = 1; i < MAX; i++) {
            tree.new_tree();
            for (int j : arr[i])
                tree.update(i, j, 1);
            arr[i].clear();
        }

        while (M--) {
            cin >> A >> B >> C >> D, A++, B++;
            res += tree.query(B, C, D) - tree.query(A - 1, C, D);
        }

        cout << res << '\n';
    }

    return 0;
}