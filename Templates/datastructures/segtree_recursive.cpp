class SegTree {
  private:
    void init(int n, int s, int e) {
        if (s == e)
            tree[n] = arr[s];
        else {
            init(n << 1, s, (s + e) >> 1);
            init(n << 1 | 1, ((s + e) >> 1) + 1, e);
            tree[n] = tree[n << 1] + tree[n << 1 | 1];
        }
    }

    int query(int n, int s, int e, int l, int r) {
        if (l <= s && e <= r)
            return tree[n];
        else if (r < s || e < l)
            return 0;
        else {
            int lv = query(n << 1, s, ((s + e) >> 1), l, r);
            int rv = query(n << 1 | 1, ((s + e) >> 1) + 1, e, l, r);
            return lv + rv;
        }
    }

    void update(int n, int s, int e, int pos, int val) {
        if (pos < s || e < pos)
            return;
        else if (s == e) {
            tree[n] = val;
            arr[s] = val;
        } else {
            update(n << 1, s, (s + e) >> 1, pos, val);
            update(n << 1 | 1, ((s + e) >> 1) + 1, e, pos, val);
            tree[n] = tree[n << 1] + tree[n << 1 | 1];
        }
    }

  public:
    int N;
    vector<int> arr;
    vector<int> tree;

    SegTree(int n) : N(n), arr(n + 1), tree(n * 4 + 1) {}

    void init() { init(1, 1, N); }
    int query(int pos) { return query(1, 1, N, pos, pos); }
    int query(int l, int r) { return query(1, 1, N, l, r); }
    void update(int pos, int val) { update(1, 1, N, pos, val); }
};