int tree[MAX * 4], lazy[MAX * 4];

void init(int n, int s, int e) {
    if (s == e)
        tree[n] = arr[s];
    else {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
        tree[n] = tree[n << 1] + tree[n << 1 | 1];
    }
}

void lazy_update(int n, int s, int e) {
    if (lazy[n] == 0)
        continue;
    tree[n] += lazy[n] * (e - s + 1);
    if (s ^ e)
        lazy[n << 1] += lazy[n], lazy[n << 1 | 1] += lazy[n];
    lazy[n] = 0;
}

int query(int n, int s, int e, int l, int r) {
    lazy_update(n, s, e);
    if (l <= s && e <= r)
        return tree[n];
    else if (r < s || e < l)
        return 0;
    else {
        int m = s + e >> 1;
        return query(n << 1, s, m, l, r) + query(n << 1 | 1, m + 1, e, l, r);
    }
}

void update(int n, int s, int e, int l, int r, int v) {
    lazy_update(n, s, e);
    if (r < s || e < l)
        return;
    else if (l <= s && e <= r)
        lazy[n] += v, lazy_update(n, s, e);
    else {
        int m = s + e >> 1;
        update(n << 1, s, m, l, r, v), update(n << 1 | 1, m + 1, e, l, r, v);
        tree[n] = tree[n << 1] + tree[n << 1 | 1];
    }
}