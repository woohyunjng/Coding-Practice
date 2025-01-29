#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define INF (1ll << 30) - 1
using namespace std;

struct Node {
    int mx, andv, orv;
};

Node tree[MAX * 4];
int lazy[MAX * 4], A[MAX];

void init(int n, int s, int e) {
    if (s == e)
        tree[n] = {A[s], A[s], A[s]};
    else {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
        tree[n] = {
            max(tree[n << 1].mx, tree[n << 1 | 1].mx),
            tree[n << 1].andv & tree[n << 1 | 1].andv,
            tree[n << 1].orv | tree[n << 1 | 1].orv};
    }
}

void lazy_propagate(int n, int s, int e) {
    if (!lazy[n])
        return;
    tree[n].mx += lazy[n], tree[n].andv += lazy[n], tree[n].orv += lazy[n];
    if (s != e)
        lazy[n << 1] += lazy[n], lazy[n << 1 | 1] += lazy[n];
    lazy[n] = 0;
}

void update(int n, int s, int e, int l, int r, int x, int t) {
    bool flag = false;
    lazy_propagate(n, s, e);
    if (r < s || e < l)
        return;
    else if (l <= s && e <= r) {
        if (t == 0 && (tree[n].orv & (~x)) == (tree[n].andv & (~x)))
            lazy[n] = (tree[n].orv & x) - tree[n].orv, flag = true;
        else if (t == 1 && (tree[n].orv & x) == (tree[n].andv & x))
            lazy[n] = (tree[n].orv | x) - tree[n].orv, flag = true;
        lazy_propagate(n, s, e);
        if (flag)
            return;
    }

    int m = s + e >> 1;
    update(n << 1, s, m, l, r, x, t), update(n << 1 | 1, m + 1, e, l, r, x, t);
    tree[n] = {
        max(tree[n << 1].mx, tree[n << 1 | 1].mx),
        tree[n << 1].andv & tree[n << 1 | 1].andv,
        tree[n << 1].orv | tree[n << 1 | 1].orv};
}

int query(int n, int s, int e, int l, int r) {
    lazy_propagate(n, s, e);
    if (r < s || e < l)
        return 0;
    else if (l <= s && e <= r)
        return tree[n].mx;
    else {
        int m = s + e >> 1;
        return max(
            query(n << 1, s, m, l, r),
            query(n << 1 | 1, m + 1, e, l, r));
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, L, R, X, T;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> A[i];
    init(1, 1, N);

    cin >> Q;
    while (Q--) {
        cin >> T >> L >> R;
        if (T == 1)
            cin >> X, update(1, 1, N, L, R, X, 0);
        else if (T == 2)
            cin >> X, update(1, 1, N, L, R, X, 1);
        else
            cout << query(1, 1, N, L, R) << '\n';
    }

    return 0;
}