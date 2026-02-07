#include <bits/stdc++.h>
using namespace std;

const int MAX = 400001;

struct Node {
    int mn_pf = MAX, mx_pf = 0, sm = 0, lv = -1, lv_l = 0, rv = -1, rv_l = 0, len;
    bool chk_z = false, chk_o = false;

    Node(int x = -2) : mn_pf(x), mx_pf(x), sm(x), lv(x), lv_l(1), rv(x), rv_l(1), len(x == -2 ? -1 : 1) {}
};

int A[MAX], lazy[MAX * 4], N;
Node tree[MAX * 4];

Node merge(Node X, Node Y) {
    if (Y.len == -1)
        return X;
    if (X.len == -1)
        return Y;

    Node res;

    res.sm = X.sm + Y.sm, res.len = X.len + Y.len;
    res.mn_pf = min(X.mn_pf, X.sm + Y.mn_pf), res.mx_pf = max(X.mx_pf, X.sm + Y.mx_pf);
    res.chk_z = res.chk_o = false;

    if (res.mn_pf == X.mn_pf)
        res.chk_z |= X.chk_z;
    if (res.mn_pf == X.sm + Y.mn_pf) {
        res.chk_z |= Y.chk_z;
        if (Y.lv == -1 && -Y.lv_l == Y.mn_pf && !(X.rv == -1 && X.len == X.rv_l))
            res.chk_z |= (Y.lv_l + (X.rv == -1 ? X.rv_l : 0)) % 2 == 0;
    }

    if (res.mx_pf == X.mx_pf)
        res.chk_o |= X.chk_o;
    if (res.mx_pf == X.sm + Y.mx_pf) {
        res.chk_o |= Y.chk_o;
        if (Y.lv == 1 && Y.lv_l == Y.mx_pf && !(X.rv == 1 && X.len == X.rv_l))
            res.chk_o |= (Y.lv_l + (X.rv == 1 ? X.rv_l : 0)) % 2 == 0;
    }

    res.lv = X.lv, res.lv_l = X.lv_l + (X.lv_l == X.len && X.lv == Y.lv ? Y.lv_l : 0);
    res.rv = Y.rv, res.rv_l = Y.rv_l + (Y.rv_l == Y.len && Y.rv == X.rv ? X.rv_l : 0);

    return res;
}

void prnt(int n, int s, int e) {
    cout << "Node :" << n << " [" << s << ", " << e << "]\n";
    cout << "mn_pf: " << tree[n].mn_pf << ", mx_pf: " << tree[n].mx_pf << ", sm: " << tree[n].sm << ", len: " << tree[n].len << '\n';
    cout << "lv: " << tree[n].lv << " (" << tree[n].lv_l << "), rv: " << tree[n].rv << " (" << tree[n].rv_l << "), chk_z: " << tree[n].chk_z << ", chk_o: " << tree[n].chk_o << '\n';
}

void init(int n, int s, int e) {
    if (s == e)
        tree[n] = Node(A[s] ? 1 : -1);
    else {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
        tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
    }
}

void lazy_update(int n, int s, int e) {
    if (lazy[n] == 0)
        return;

    swap(tree[n].mx_pf, tree[n].mn_pf), swap(tree[n].chk_o, tree[n].chk_z);
    tree[n].mx_pf = -tree[n].mx_pf, tree[n].mn_pf = -tree[n].mn_pf;
    tree[n].lv *= -1, tree[n].rv *= -1, tree[n].sm *= -1;

    if (s ^ e)
        lazy[n << 1] ^= lazy[n], lazy[n << 1 | 1] ^= lazy[n];
    lazy[n] = 0;
}

void update(int n, int s, int e, int l, int r) {
    lazy_update(n, s, e);
    if (r < s || e < l)
        return;
    else if (l <= s && e <= r)
        lazy[n] = 1, lazy_update(n, s, e);
    else {
        int m = s + e >> 1;
        update(n << 1, s, m, l, r), update(n << 1 | 1, m + 1, e, l, r);
        tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
    }
}

Node query(int n, int s, int e, int l, int r) {
    lazy_update(n, s, e);
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

void solve() {
    bool ans = true;
    ans &= query(1, 1, N << 1, 1, (N << 1) - 1).mn_pf > 0;
    ans &= !query(1, 1, N << 1, 1, (N << 1) - 1).chk_z;
    cout << (ans ? "YES" : "NO") << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int Q, L, R;

    cin >> N;
    for (int i = 1; i <= (N << 1); i++)
        cin >> A[i];
    init(1, 1, N << 1);
    solve();

    cin >> Q;
    while (Q--) {
        cin >> L >> R, update(1, 1, N << 1, L, R);
        solve();
    }

    return 0;
}