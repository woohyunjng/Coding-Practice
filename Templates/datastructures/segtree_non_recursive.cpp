class SegTree {
  public:
    int N;
    vector<int> arr, tree;

    SegTree(int n) : N(n), arr(n + 1, 0), tree(n * 2 + 1, 0) {}

    void init() {
        for (int i = 1; i <= N; i++)
            tree[i + N - 1] = arr[i];

        for (int i = N - 1; i > 0; --i)
            tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }

    int query(int l, int r) {
        int res = 0;
        for (l += N - 1, r += N; l < r; l >>= 1, r >>= 1) {
            if (l & 1)
                res += tree[l++];
            if (r & 1)
                res += tree[--r];
        }
        return res;
    }

    int query(int pos) { return query(pos, pos); }
    void update(int pos, int val) {
        for (tree[pos += N - 1] += val; pos > 1; pos >>= 1)
            tree[pos >> 1] = tree[pos] + tree[pos ^ 1];
    }
};