#include <bits/stdc++.h>

#define MAX 50100

using namespace std;

int tree[MAX * 4][52], lazy[MAX * 4][52], temp[52], temp2[52];
bool upd[MAX * 4];

void send_lazy(int fn, int n) {
    for (int i = 0; i < 52; i++)
        temp[i] = lazy[n][i];
    for (int i = 0; i < 52; i++)
        lazy[n][i] = lazy[fn][temp[i]];
    upd[n] = true;
}

void lazy_update(int n, int s, int e) {
    if (!upd[n])
        return;
    for (int i = 0; i < 52; i++)
        temp[i] = tree[n][i];
    for (int i = 0; i < 52; i++)
        tree[n][lazy[n][i]] = temp[i];
    if (s != e)
        send_lazy(n, n << 1), send_lazy(n, n << 1 | 1);
    for (int i = 0; i < 52; i++)
        lazy[n][i] = i;
    upd[n] = false;
}

void merge(int A, int B, int C) {
    for (int i = 0; i < 52; i++)
        tree[C][i] = tree[A][i] + tree[B][i];
}

void init(int n, int s, int e) {
    for (int i = 0; i < 52; i++)
        lazy[n][i] = i;

    if (s == e) {
        for (int i = 0; i < 52; i++)
            tree[n][i] = i % 13 + 1;
        return;
    }

    int m = (s + e) >> 1;
    init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
    merge(n << 1, n << 1 | 1, n);
}

int query(int n, int s, int e, int l, int r, int x) {
    if (r < s || e < l)
        return 0;
    lazy_update(n, s, e);
    if (l <= s && e <= r)
        return tree[n][x];
    int m = (s + e) >> 1;
    return query(n << 1, s, m, l, r, x) + query(n << 1 | 1, m + 1, e, l, r, x);
}

void update(int n, int s, int e, int l, int r, int x, int y) {
    lazy_update(n, s, e);
    if (r < s || e < l)
        return;
    if (l <= s && e <= r) {
        swap(lazy[n][x], lazy[n][y]);
        upd[n] = true;
        lazy_update(n, s, e);
        return;
    }

    int m = (s + e) >> 1;
    update(n << 1, s, m, l, r, x, y), update(n << 1 | 1, m + 1, e, l, r, x, y);
    merge(n << 1, n << 1 | 1, n);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, T, A, B, X, Y;
    cin >> N >> Q;

    init(1, 1, N);

    while (Q--) {
        cin >> T;
        if (T == 0) {
            cin >> A >> B >> X >> Y;
            update(1, 1, N, A + 1, B, X, Y);
        } else {
            cin >> X >> Y;
            cout << query(1, 1, N, X + 1, Y, 51) << '\n';
        }
    }

    return 0;
}