#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 510000;

int A[MAX], B[MAX], tree[MAX * 4], lazy[MAX * 4];

void lazy_update(int n, int s, int e) {
    if (lazy[n] == 0)
        return;
    tree[n] += lazy[n];
    if (s ^ e)
        lazy[n << 1] += lazy[n], lazy[n << 1 | 1] += lazy[n];
    lazy[n] = 0;
}

void init(int n, int s, int e) {
    if (s == e)
        tree[n] = -s;
    else {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
        tree[n] = max(tree[n << 1], tree[n << 1 | 1]);
    }
}

void update(int n, int s, int e, int l, int r, int v) {
    lazy_update(n, s, e);
    if (r < s || e < l)
        return;
    else if (l <= s && e <= r)
        lazy[n] += v, lazy_update(n, s, e);
    else {
        int m = s + e >> 1;
        update(n << 1, s, m, l, r, v), update(n << 1 | 1, m + 1, e, l, r, v);
        tree[n] = max(tree[n << 1], tree[n << 1 | 1]);
    }
}

int query(int n, int s, int e) {
    lazy_update(n, s, e);
    if (s == e)
        return s;
    else {
        int m = s + e >> 1;
        lazy_update(n << 1, s, m), lazy_update(n << 1 | 1, m + 1, e);
        if (tree[n << 1 | 1] >= 0)
            return query(n << 1 | 1, m + 1, e);
        else
            return query(n << 1, s, m);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, T, X, Y;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i] >> B[i];

    init(1, 0, N);
    for (int i = 1; i <= N; i++)
        update(1, 0, N, A[i], B[i], 1);

    cout << query(1, 0, N) << ' ';

    cin >> Q;
    while (Q--) {
        cin >> T >> X >> Y;
        update(1, 0, N, A[T], B[T], -1);
        A[T] = X, B[T] = Y;
        update(1, 0, N, A[T], B[T], 1);

        cout << query(1, 0, N) << ' ';
    }
    cout << '\n';
}