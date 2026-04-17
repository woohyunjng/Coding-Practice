#include <bits/stdc++.h>

#define MAX 1000100
#define MAX_N 200100

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

long long sm[MAX_N], cnt[MAX];
int A[MAX_N], last[MAX], first[MAX], idx[MAX_N];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, Q, st, en, mid;
    long long K, X, Y, Z;
    cin >> N >> M >> Q;

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        if (first[A[i]] == 0)
            first[A[i]] = i;
        last[A[i]] = i;
    }
    for (int i = 1; i <= M; i++) {
        if (last[i] == 0)
            first[i] = N;
        sm[last[i]]++, idx[last[i]] = i;
    }
    for (int i = 1; i <= N; i++)
        sm[i] += sm[i - 1];

    for (int i = 1; i <= M; i++)
        cnt[i] = sm[first[i]] + cnt[i - 1];
    PersistentSegTree tree(M);
    tree.init();

    for (int i = 1; i <= M; i++)
        if (last[i] == 0)
            tree.update(0, i, 1);

    for (int i = 1; i <= N; i++) {
        tree.new_tree();
        if (idx[i] == 0)
            continue;
        tree.update(i, idx[i], 1);
    }

    while (Q--) {
        cin >> K;

        st = 1, en = M, X = -1, Y = -1;
        while (st <= en) {
            mid = st + en >> 1;
            if (cnt[mid] >= K)
                X = mid, en = mid - 1;
            else
                st = mid + 1;
        }

        if (X == -1) {
            cout << -1 << ' ' << -1 << '\n';
            continue;
        }

        K -= cnt[X - 1];
        if (cnt[X] == M) {
            cout << X << ' ' << K << '\n';
            continue;
        }

        st = 1, en = M;
        while (st <= en) {
            mid = st + en >> 1;
            Z = tree.query(first[X], 1, mid);
            if (Z >= K)
                Y = mid, en = mid - 1;
            else
                st = mid + 1;
        }
        cout << X << ' ' << Y << '\n';
    }

    return 0;
}