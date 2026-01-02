#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 300001;

struct Node {
    int val = -1, l = -1, r = -1, pos = -1;
    Node() {}
    Node(int val, int l, int r, int pos = -1) : val(val), l(l), r(r), pos(pos) {}
};

int L, A[MAX], B[MAX];
Node tree[MAX * 4];

Node merge(Node X, Node Y) {
    if (Y.val == -1)
        return X;
    if (X.val == -1)
        return Y;

    Node res = Node(X.val + Y.val, X.l, X.r, Y.pos);
    if ((X.pos == -1 ? X.r : X.pos) <= Y.l) {
        res.pos = Y.pos == -1 ? Y.l : Y.pos;
        res.val += Y.l - (X.pos == -1 ? X.r : X.pos), res.l = X.r;
    } else if ((X.pos == -1 ? X.l : X.pos) >= Y.r) {
        res.pos = Y.pos == -1 ? Y.r : Y.pos;
        res.val += (X.pos == -1 ? X.l : X.pos) - Y.r, res.r = X.l;
    } else if (X.pos == -1)
        res.l = max(X.l, Y.l), res.r = min(X.r, Y.r);
    else if (Y.pos == -1)
        res.pos = X.pos;
    return res;
}

void init(int n, int s, int e) {
    if (s == e)
        tree[n] = Node(0, A[s], L - B[s], -1);
    else {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
        tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
    }
}

Node query(int n, int s, int e, int l, int r) {
    if (r < s || e < l)
        return Node(-1, -1, -1, -1);
    else if (l <= s && e <= r) {
        return tree[n];
    } else {
        int m = s + e >> 1;
        Node val = merge(
            query(n << 1, s, m, l, r),
            query(n << 1 | 1, m + 1, e, l, r));
        return val;
    }
}

void update(int n, int s, int e, int x) {
    if (x < s || e < x)
        return;
    else if (s == e)
        tree[n] = Node(0, A[s], L - B[s], -1);
    else {
        int m = s + e >> 1;
        update(n << 1, s, m, x), update(n << 1 | 1, m + 1, e, x);
        tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, T, XS, YS, XT, YT, ans, CI, CA, CB;
    Node res;

    cin >> N >> L >> Q;
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    for (int i = 1; i <= N; i++)
        cin >> B[i];

    init(1, 1, N);

    while (Q--) {
        cin >> T;
        if (T == 1) {
            cin >> XS >> YS >> XT >> YT;
            if (XS > XT)
                swap(XS, XT), swap(YS, YT);
            if (XS == XT) {
                cout << abs(YS - YT) << '\n';
                continue;
            }

            res = query(1, 1, N, XS + 1, XT), ans = abs(XT - XS) + res.val;
            if (YS <= res.l)
                ans += res.l - YS, YS = res.l;
            else if (res.r <= YS)
                ans += YS - res.r, YS = res.r;
            if (res.pos != -1)
                YS = res.pos;
            ans += abs(YS - YT), cout << ans << '\n';
        } else {
            cin >> CI >> CA >> CB, A[CI] = CA, B[CI] = CB;
            update(1, 1, N, CI);
        }
    }
}