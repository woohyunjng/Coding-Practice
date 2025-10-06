int N, A[MAX], fenwick[MAX];

void build() {
    for (int i = 1; i <= N; i++) {
        fenwick[i] += A[i];
        if (i + (i & -i) <= N)
            fenwick[i + (i & -i)] += fenwick[i];
    }
}

void update(int n, int val) {
    for (; n <= N; n += n & -n)
        fenwick[n] += val;
}

int query(int n) {
    int res = 0;
    for (; n > 0; n -= n & -n)
        res += fenwick[n];
    return res;
}

int query(int l, int r) { return query(r) - query(l - 1); }