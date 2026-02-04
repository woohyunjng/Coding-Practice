int calc(pr line, int x) { return line[0] * x + line[1]; }

void init(int n, int s, int e) {
    tree[n] = {0, INF};
    if (s ^ e) {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
    }
}

void lazy_update(int n, int s, int e) {
    if (lazy[n] == 0)
        return;
    tree[n][1] += lazy[n];
    if (s ^ e)
        lazy[n << 1] += lazy[n], lazy[n << 1 | 1] += lazy[n];
    lazy[n] = 0;
}

void insert(int n, int s, int e, int l, int r, pr line) { // [l, r]에 av = min(av, line(v))
    lazy_update(n, s, e);
    if (r < s || e < l)
        return;
    else if (l <= s && e <= r) {
        pr low = tree[n], high = line;
        if (calc(low, s) >= calc(high, s))
            swap(low, high);
        if (calc(low, e) <= calc(high, e)) {
            tree[n] = low;
            return;
        }

        if (s ^ e) {
            int m = s + e >> 1;
            if (calc(low, m) <= calc(high, m))
                tree[n] = low, insert(n << 1 | 1, m + 1, e, l, r, high);
            else
                tree[n] = high, insert(n << 1, s, m, l, r, low);
        }
    } else {
        int m = s + e >> 1;
        insert(n << 1, s, m, l, r, line), insert(n << 1 | 1, m + 1, e, l, r, line);
    }
}

void add(int n, int s, int e, int l, int r, int v) { // [l, r]에 v 더하기
    lazy_update(n, s, e);
    if (r < s || e < l)
        return;
    else if (l <= s && e <= r)
        lazy[n] = v, lazy_update(n, s, e);
    else {
        int m = s + e >> 1;
        insert(n << 1, s, m, s, m, tree[n]), insert(n << 1 | 1, m + 1, e, m + 1, e, tree[n]);
        tree[n] = {0, INF};
        add(n << 1, s, m, l, r, v), add(n << 1 | 1, m + 1, e, l, r, v);
    }
}

int query(int n, int s, int e, int x) {
    lazy_update(n, s, e);
    if (s == e)
        return calc(tree[n], x);
    else {
        int m = s + e >> 1, res = calc(tree[n], x);
        if (x <= m)
            res = min(res, query(n << 1, s, m, x));
        else
            res = min(res, query(n << 1 | 1, m + 1, e, x));
        return res;
    }
}