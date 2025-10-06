int tree[MAX][MAX];

void update(int x, int y, int v) {
    for (int i = x; i <= M; i += i & -i)
        for (int j = y; j <= M; j += j & -j)
            tree[i][j] += v;
}

int query(int x, int y) {
    int res = 0;
    for (int i = x; i; i -= i & -i)
        for (int j = y; j; j -= j & -j)
            res += tree[i][j];
    return res;
}