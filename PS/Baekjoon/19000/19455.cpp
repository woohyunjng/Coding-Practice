#include <bits/stdc++.h>
#define int long long

#define MAX 600000
#define INF (1ll << 30) - 1
using namespace std;

struct Node {
    int mn, andv, orv;
};

Node tree[MAX * 4];
int lazy[MAX * 4][2], A[MAX];

Node merge(Node X, Node Y) { return {min(X.mn, Y.mn), X.andv & Y.andv, X.orv | Y.orv}; }

void init(int n, int s, int e) {
    lazy[n][0] = INF, lazy[n][1] = 0;
    if (s == e)
        tree[n] = {A[s], A[s], A[s]};
    else {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
        tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
    }
}

void lazy_propagate(int n, int s, int e) {
    if (lazy[n][0] == INF && !lazy[n][1])
        return;

    tree[n].mn = (tree[n].mn & lazy[n][0]) | lazy[n][1];
    tree[n].andv = (tree[n].andv & lazy[n][0]) | lazy[n][1];
    tree[n].orv = (tree[n].orv & lazy[n][0]) | lazy[n][1];

    if (s != e) {
        lazy[n << 1][0] &= lazy[n][0], lazy[n << 1][1] = (lazy[n << 1][1] & lazy[n][0]) | lazy[n][1];
        lazy[n << 1 | 1][0] &= lazy[n][0], lazy[n << 1 | 1][1] = (lazy[n << 1 | 1][1] & lazy[n][0]) | lazy[n][1];
    }

    lazy[n][0] = INF, lazy[n][1] = 0;
}

void update(int n, int s, int e, int l, int r, int x, int t) {
    lazy_propagate(n, s, e);
    if (r < s || e < l)
        return;
    else if (l <= s && e <= r && (tree[n].orv & x) == (tree[n].andv & x)) {
        lazy[n][t] = x, lazy_propagate(n, s, e);
        return;
    }

    int m = s + e >> 1;
    update(n << 1, s, m, l, r, x, t), update(n << 1 | 1, m + 1, e, l, r, x, t);
    tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
}

Node query(int n, int s, int e, int l, int r) {
    lazy_propagate(n, s, e);
    if (r < s || e < l)
        return {INF, INF, 0};
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

    int N, Q, L, R, X;
    char C;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> A[i];
    init(1, 1, N);

    cin >> Q;
    while (Q--) {
        cin >> C >> L >> R;
        if (C == '&')
            cin >> X, update(1, 1, N, L, R, X, 0);
        else if (C == '|')
            cin >> X, update(1, 1, N, L, R, X, 1);
        else
            cout << query(1, 1, N, L, R).mn << '\n';
    }

    return 0;
}