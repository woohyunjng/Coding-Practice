#include <bits/stdc++.h>
#define int long long

#define MAX 1500000
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;

struct Node {
    int sum = 0, mx = 0, smx = 0, mx_cnt = 0;
};

int A[MAX];
Node tree[MAX * 4];

Node merge(Node X, Node Y) {
    Node res = (Node){X.sum + Y.sum, max(X.mx, Y.mx), 0, 0};
    if (X.mx == Y.mx)
        res.mx_cnt = X.mx_cnt + Y.mx_cnt, res.smx = max(X.smx, Y.smx);
    else {
        if (X.mx < Y.mx)
            swap(X, Y);
        res.mx_cnt = X.mx_cnt, res.smx = max(X.smx, Y.mx);
    }
    return res;
}

void lazy_propagate(int n, int s, int e) {
    if (s == e)
        return;
    for (int i : {n << 1, n << 1 | 1}) {
        if (tree[n].mx < tree[i].mx)
            tree[i].sum += (tree[n].mx - tree[i].mx) * tree[i].mx_cnt, tree[i].mx = tree[n].mx;
    }
}

void init(int n, int s, int e) {
    if (s == e)
        tree[n] = {A[s], A[s], -INF, 1};
    else {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
        tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
    }
}

void update(int n, int s, int e, int l, int r, int x) {
    lazy_propagate(n, s, e);
    if (r < s || e < l || tree[n].mx <= x)
        return;
    else if (l <= s && e <= r && tree[n].smx < x) {
        tree[n].sum += (x - tree[n].mx) * tree[n].mx_cnt, tree[n].mx = x;
        lazy_propagate(n, s, e);
        return;
    } else {
        int m = s + e >> 1;
        update(n << 1, s, m, l, r, x), update(n << 1 | 1, m + 1, e, l, r, x);
        tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
    }
}

Node query(int n, int s, int e, int l, int r) {
    lazy_propagate(n, s, e);
    if (r < s || e < l)
        return {0, -INF, -INF, 0};
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

    int N, Q, T, L, R, X;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> A[i];
    init(1, 1, N);

    cin >> Q;
    while (Q--) {
        cin >> T >> L >> R;
        if (T == 1)
            cin >> X, update(1, 1, N, L, R, X);
        else if (T == 2)
            cout << query(1, 1, N, L, R).mx << '\n';
        else
            cout << query(1, 1, N, L, R).sum << '\n';
    }

    return 0;
}