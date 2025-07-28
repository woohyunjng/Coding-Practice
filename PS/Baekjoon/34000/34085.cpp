#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 500001;
const int MAX_LOG = 11;
const int INF = 0x3f3f3f3f3f3f3f3f;

struct Node {
    int sm = 0, mn = INF, mx = -INF;
    Node() {}
    Node(int sm, int mn, int mx) : sm(sm), mn(mn), mx(mx) {}
};

Node merge(Node X, Node Y) {
    Node res;
    res.sm = X.sm + Y.sm;
    res.mn = min(X.mn, Y.mn), res.mx = max(X.mx, Y.mx);
    return res;
}

Node tree[MAX_LOG][MAX * 4];
int lazy[MAX_LOG][MAX * 4], A[MAX];

void lazy_update(int t, int n, int s, int e) {
    if (lazy[t][n] == 0)
        return;
    if (lazy[t][n] == -1)
        tree[t][n] = Node();
    else
        tree[t][n] = Node{lazy[t][n] * (e - s + 1), lazy[t][n], lazy[t][n]};
    if (s ^ e)
        lazy[t][n << 1] = lazy[t][n], lazy[t][n << 1 | 1] = lazy[t][n];
    lazy[t][n] = 0;
}

void update(int t, int n, int s, int e, int l, int r, int v) {
    lazy_update(t, n, s, e);
    if (r < s || e < l)
        return;
    else if (l <= s && e <= r)
        lazy[t][n] = v, lazy_update(t, n, s, e);
    else {
        int m = s + e >> 1;
        update(t, n << 1, s, m, l, r, v), update(t, n << 1 | 1, m + 1, e, l, r, v);
        tree[t][n] = merge(tree[t][n << 1], tree[t][n << 1 | 1]);
    }
}

Node query(int t, int n, int s, int e, int l, int r) {
    lazy_update(t, n, s, e);
    if (r < s || e < l)
        return Node();
    else if (l <= s && e <= r)
        return tree[t][n];
    else {
        int m = s + e >> 1;
        return merge(query(t, n << 1, s, m, l, r), query(t, n << 1 | 1, m + 1, e, l, r));
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, Q, T, L, R, Z, C, last_ans = 0;
    Node K;

    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        cin >> A[i], X = 0;
        while (1ll << (X + 1) <= A[i])
            X++;
        update(X, 1, 1, N, i, i, A[i]);
    }

    while (Q--) {
        cin >> T >> L >> R >> C >> Z;
        L = (L ^ (last_ans * Z)) % N + 1, R = (R ^ (last_ans * Z)) % N + 1, C = (C ^ (last_ans * Z)) % 1024 + 1;
        if (L > R)
            swap(L, R);
        if (T == 0) {
            for (int i = 0; i < MAX_LOG; i++)
                update(i, 1, 1, N, L, R, -1);
            X = 0;
            while (1ll << (X + 1) <= C)
                X++;
            update(X, 1, 1, N, L, R, C);
        } else {
            X = last_ans = Z = 0;
            while ((1ll << X) < C)
                X++;
            last_ans |= query(X, 1, 1, N, L, R).mn < 2 * C;
            if (X > 0) {
                last_ans |= query(X - 1, 1, 1, N, L, R).mx >= C;
                for (int i = 0; i <= X - 1; i++)
                    Z += query(i, 1, 1, N, L, R).sm;
                last_ans |= Z >= C;
            }

            cout << last_ans << '\n';
        }
    }

    return 0;
}