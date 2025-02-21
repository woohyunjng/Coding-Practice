#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 200000;
const int MOD = 1000000007;

struct Node {
    int val[16] = {0}, sz = 0;
};

Node tree[MAX * 4];
int A[2][MAX];

Node merge(Node X, Node Y) {
    if (X.sz == 0)
        return Y;
    if (Y.sz == 0)
        return X;

    Node res;
    fill(res.val, res.val + 16, 0);
    res.sz = X.sz + Y.sz;

    if (X.sz == 1 && Y.sz == 1) {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++) {
                res.val[(i << 2) | j] += X.val[(i << 2) | i] * Y.val[(j << 2) | j];
                for (int k = 1; k < 4; k++) {
                    if ((i & k) == 0 && (j & k) == 0)
                        res.val[((i | k) << 2) | (j | k)] += X.val[(i << 2) | i] * Y.val[(j << 2) | j];
                }
            }
    } else if (X.sz == 1 && Y.sz > 1) {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++) {
                res.val[(i << 2) | j] = (res.val[(i << 2) | j] + X.val[(i << 2) | i] * Y.val[0b1100 | j]) % MOD;
                for (int k = 1; k < 4; k++) {
                    if ((i & k) == 0)
                        res.val[((i | k) << 2) | j] = (res.val[((i | k) << 2) | j] + X.val[(i << 2) | i] * Y.val[((3 ^ k) << 2) | j]) % MOD;
                }
            }
    } else if (X.sz > 1 && Y.sz == 1) {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++) {
                res.val[(i << 2) | j] = (res.val[(i << 2) | j] + X.val[(i << 2) | 0b0011] * Y.val[(j << 2) | j]) % MOD;
                for (int k = 1; k < 4; k++) {
                    if ((j & k) == 0)
                        res.val[(i << 2) | (j | k)] = (res.val[(i << 2) | (j | k)] + X.val[(i << 2) | (3 ^ k)] * Y.val[(j << 2) | j]) % MOD;
                }
            }
    } else {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++)
                    res.val[(i << 2) | j] += X.val[(i << 2) | k] * Y.val[(k << 2) | j];
                res.val[(i << 2) | j] %= MOD;
            }
    }

    return res;
}

void init(int n, int s, int e) {
    if (s == e) {
        fill(tree[n].val, tree[n].val + 16, 0), tree[n].sz = 1;
        tree[n].val[0b1111] = tree[n].val[0b0000] = 1;
    } else {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
        tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
    }
}

void update(int n, int s, int e, int x) {
    if (x < s || e < x)
        return;
    else if (s == e) {
        fill(tree[n].val, tree[n].val + 16, 0);
        if (A[0][x] == 0 && A[1][x] == 0)
            tree[n].val[0b1111] = tree[n].val[0b0000] = 1;
        else if (A[0][x] == 1 && A[1][x] == 0)
            tree[n].val[0b1010] = 1;
        else if (A[0][x] == 0 && A[1][x] == 1)
            tree[n].val[0b0101] = 1;
        else if (A[0][x] == 1 && A[1][x] == 1)
            tree[n].val[0b1111] = 1;
    } else {
        int m = s + e >> 1;
        update(n << 1, s, m, x), update(n << 1 | 1, m + 1, e, x);
        tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
    }
}

Node query(int n, int s, int e, int l, int r) {
    if (r < s || e < l)
        return Node();
    else if (l <= s && e <= r)
        return tree[n];
    else {
        int m = s + e >> 1;
        return merge(
            query(n << 1, s, m, l, r),
            query(n << 1 | 1, m + 1, e, l, r));
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, T, X, Y;

    cin >> N >> Q;
    init(1, 1, N);

    while (Q--) {
        cin >> T >> X >> Y, X--;
        if (T == 1)
            A[X][Y] = 1;
        else
            A[X][Y] = 0;
        update(1, 1, N, Y);
        cout << query(1, 1, N, 1, N).val[15] << '\n';
    }

    return 0;
}