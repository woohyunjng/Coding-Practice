#include <bits/stdc++.h>
using namespace std;

const int MAX = 200002;

struct Node {
    array<array<int, 3>, 3> val;
    int length;

    Node() : val{{{-MAX, -MAX, -MAX}, {-MAX, -MAX, -MAX}, {-MAX, -MAX, -MAX}}}, length(0) {}
    Node(array<array<int, 3>, 3> v, int l) : val(v), length(l) {}
};

int A[MAX], cnt[MAX * 4];
Node tree[MAX * 4];

Node merge(const Node &X, const Node &Y) {
    if (X.length == 0)
        return Y;
    if (Y.length == 0)
        return X;

    Node res = Node();
    res.length = X.length + Y.length;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
                res.val[i][j] = max(res.val[i][j], X.val[i][k] + Y.val[2 - k][j]);

    for (int i = 0; i < 3; i++) {
        res.val[0][i] = max(res.val[0][i], Y.val[X.length & 1][i]);
        res.val[1][i] = max(res.val[1][i], Y.val[X.length & 1 ^ 1][i]);
        res.val[2][i] = max(res.val[2][i], Y.val[X.length & 1][i]);
    }

    for (int i = 0; i < 3; i++) {
        res.val[i][0] = max(res.val[i][0], X.val[i][Y.length & 1]);
        res.val[i][1] = max(res.val[i][1], X.val[i][Y.length & 1 ^ 1]);
        res.val[i][2] = max(res.val[i][2], X.val[i][Y.length & 1]);
    }

    return res;
}

void init(int n, int s, int e) {
    if (s == e)
        tree[n] = Node(), tree[n].length = 1, tree[n].val[0][0] = 1;
    else {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
        tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
    }
}

void update(int n, int s, int e, int l, int r, int v) {
    if (r < s || e < l)
        return;
    else if (l <= s && e <= r)
        cnt[n] += v;
    else {
        int m = s + e >> 1;
        update(n << 1, s, m, l, r, v), update(n << 1 | 1, m + 1, e, l, r, v);
    }

    if (cnt[n] > 0)
        tree[n] = Node({{{-MAX, -MAX, -MAX}, {-MAX, -MAX, -MAX}, {-MAX, -MAX, -MAX}}}, e - s + 1);
    else if (e - s > 0)
        tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
    else
        tree[n] = Node(), tree[n].length = 1, tree[n].val[0][0] = 1;
}

Node query(int n, int s, int e, int l, int r) {
    if (r < s || e < l)
        return Node();
    else if (l <= s && e <= r)
        return tree[n];
    else {
        int m = s + e >> 1;
        return merge(query(n << 1, s, m, l, r), query(n << 1 | 1, m + 1, e, l, r));
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, idx, V;

    cin >> N >> Q;
    for (int i = 0; i <= N; i++)
        cin >> A[i];

    init(1, 1, N);
    for (int i = 1; i <= N; i++)
        update(1, 1, N, i - A[i] + 1, i + A[i], 1);
    cout << (N - max(0, query(1, 1, N, 1, N).val[2][2]) + 1) / 2 << '\n';

    while (Q--) {
        cin >> idx >> V;
        update(1, 1, N, idx - A[idx] + 1, idx + A[idx], -1), A[idx] = V;
        update(1, 1, N, idx - A[idx] + 1, idx + A[idx], 1);
        cout << (N - max(0, query(1, 1, N, 1, N).val[2][2]) + 1) / 2 << '\n';
    }

    return 0;
}