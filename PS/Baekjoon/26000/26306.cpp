#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;

const int MAX = 200000;

int A[MAX], tree[MAX * 4][2];
pr lazy[MAX * 4][2];

void init(int t, int n, int s, int e) {
    lazy[n][t] = {1, 0};
    if (s == e)
        tree[n][t] = t ? A[s] : s * A[s];
    else {
        int m = s + e >> 1;
        init(t, n << 1, s, m), init(t, n << 1 | 1, m + 1, e);
        tree[n][t] = tree[n << 1][t] + tree[n << 1 | 1][t];
    }
}

pr merge(pr X, pr Y) {
    if (Y[0] == 1)
        return {X[0], X[1] + Y[1]};
    else
        return Y;
}

void lazy_update(int t, int n, int s, int e) {
    if (lazy[n][t] == (pr){1, 0})
        return;

    if (t == 0) {
        if (lazy[n][t][0] == 1)
            tree[n][t] += (s + e) * (e - s + 1) / 2 * lazy[n][t][1];
        else
            tree[n][t] = (s + e) * (e - s + 1) / 2 * lazy[n][t][1];
    } else {
        if (lazy[n][t][0] == 1)
            tree[n][t] += (e - s + 1) * lazy[n][t][1];
        else
            tree[n][t] = (e - s + 1) * lazy[n][t][1];
    }

    if (s ^ e) {
        lazy[n << 1][t] = merge(lazy[n << 1][t], lazy[n][t]);
        lazy[n << 1 | 1][t] = merge(lazy[n << 1 | 1][t], lazy[n][t]);
    }
    lazy[n][t] = {1, 0};
}

void update(int t, int n, int s, int e, int l, int r, pr v) {
    lazy_update(t, n, s, e);
    if (r < s || e < l)
        return;
    else if (l <= s && e <= r) {
        lazy[n][t] = merge(lazy[n][t], v);
        lazy_update(t, n, s, e);
    } else {
        int m = s + e >> 1;
        update(t, n << 1, s, m, l, r, v), update(t, n << 1 | 1, m + 1, e, l, r, v);
        tree[n][t] = tree[n << 1][t] + tree[n << 1 | 1][t];
    }
}

int query(int t, int n, int s, int e, int l, int r) {
    lazy_update(t, n, s, e);
    if (r < s || e < l)
        return 0;
    else if (l <= s && e <= r)
        return tree[n][t];
    else {
        int m = s + e >> 1;
        return query(t, n << 1, s, m, l, r) + query(t, n << 1 | 1, m + 1, e, l, r);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, T, L, R, X, Y;
    bool ans;

    cin >> N >> Q;
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    init(0, 1, 1, N), init(1, 1, 1, N);

    while (Q--) {
        cin >> T >> L >> R;
        if (T == 1) {
            cin >> X;
            update(0, 1, 1, N, L, R, {1, X});
            update(1, 1, 1, N, L, R, {1, X});
        } else if (T == 2) {
            cin >> X;
            update(0, 1, 1, N, L, R, {0, X});
            update(1, 1, 1, N, L, R, {0, X});
        } else {
            X = query(0, 1, 1, N, L, R);
            Y = query(1, 1, 1, N, L, R);
            X -= Y * (L - 1);
            ans = X * Y != 0 && X % Y == 0 && 1 <= X / Y && X / Y <= (R - L + 1);
            ans |= X == 0 && Y == 0;
            cout << (ans ? "Yes" : "No") << '\n';
        }
    }

    return 0;
}