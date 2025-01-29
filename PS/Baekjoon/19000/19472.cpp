#include <bits/stdc++.h>
#define int long long

#define MAX 200000
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;

struct Node {
    int sum = 0, mx = 0, mn = 0;
};

int A[MAX], lazy[MAX * 4][2];
Node tree[MAX * 4];

Node merge(Node X, Node Y) { return {X.sum + Y.sum, max(X.mx, Y.mx), min(X.mn, Y.mn)}; }

void lazy_propagate(int n, int s, int e) {
    if (lazy[n][1] != 0) {
        tree[n].sum = (lazy[n][0] + lazy[n][1]) * (e - s + 1), tree[n].mn = tree[n].mx = lazy[n][0] + lazy[n][1];
        if (s != e) {
            lazy[n << 1][0] = lazy[n][0], lazy[n << 1 | 1][0] = lazy[n][0];
            lazy[n << 1][1] = lazy[n][1], lazy[n << 1 | 1][1] = lazy[n][1];
        }
    } else {
        tree[n].sum += lazy[n][0] * (e - s + 1), tree[n].mn += lazy[n][0], tree[n].mx += lazy[n][0];
        if (s != e)
            lazy[n << 1][0] += lazy[n][0], lazy[n << 1 | 1][0] += lazy[n][0];
    }
    lazy[n][0] = lazy[n][1] = 0;
}

void init(int n, int s, int e) {
    if (s == e)
        tree[n] = {A[s], A[s], A[s]};
    else {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
        tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
    }
}

void update(int n, int s, int e, int l, int r, int x) {
    bool flag = false;
    lazy_propagate(n, s, e);
    if (r < s || e < l)
        return;
    else if (l <= s && e <= r) {
        if (x != -1)
            lazy[n][0] += x, flag = true;
        else {
            if (floor(sqrt(tree[n].mn)) == floor(sqrt(tree[n].mx)))
                lazy[n][1] = floor(sqrt(tree[n].mn)), flag = true;
            else if (tree[n].mn + 1 == tree[n].mx)
                lazy[n][0] += floor(sqrt(tree[n].mn)) - tree[n].mn, flag = true;
        }
        lazy_propagate(n, s, e);
        if (flag)
            return;
    }

    int m = s + e >> 1;
    update(n << 1, s, m, l, r, x), update(n << 1 | 1, m + 1, e, l, r, x);
    tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
}

Node query(int n, int s, int e, int l, int r) {
    lazy_propagate(n, s, e);
    if (r < s || e < l)
        return {0, INF, -INF};
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
    cin >> N >> Q;

    for (int i = 1; i <= N; i++)
        cin >> A[i];
    init(1, 1, N);

    while (Q--) {
        cin >> T >> L >> R;
        if (T == 1)
            cin >> X, update(1, 1, N, L, R, X);
        else if (T == 2)
            update(1, 1, N, L, R, -1);
        else
            cout << query(1, 1, N, L, R).sum << '\n';
    }

    return 0;
}