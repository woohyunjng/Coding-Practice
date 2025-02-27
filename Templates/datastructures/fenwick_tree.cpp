int N, A[MAX], fenwick[MAX];

void build() {
    for (int i = 1; i <= N; i++) {
        fenwick[i] += arr[i];
        if (i + (i & -i) <= N)
            fenwick[i + (i & -i)] += fenwick[i];
    }
}

void update(int n, int val) {
    arr[n] += val;
    while (n <= N)
        fenwick[n] += val, n += n & -n;
}

int query(int n) {
    int res = 0;
    while (n)
        res += fenwick[n], n -= n & -n;
    return res;
}

int query(int l, int r) { return query(r) - query(l - 1); }