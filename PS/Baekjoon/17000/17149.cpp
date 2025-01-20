#include <bits/stdc++.h>
#define int long long

#define MAX 100100
using namespace std;
typedef array<int, 2> pr;

int N, P[4][MAX], lazy[MAX * 4];
pr tree[MAX * 4];

pr merge(pr A, pr B) {
    if (A[0] > B[0])
        return B;
    return A;
}

void init(int n, int s, int e) {
    if (s == e)
        tree[n] = {0, s};
    else {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
        tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
    }
}

void lazy_propagate(int n, int s, int e) {
    if (!lazy[n])
        return;
    tree[n][0] += lazy[n];
    if (s != e) {
        lazy[n << 1] += lazy[n];
        lazy[n << 1 | 1] += lazy[n];
    }
    lazy[n] = 0;
}

pr query(int n, int s, int e, int l, int r) {
    lazy_propagate(n, s, e);
    if (r < s || e < l)
        return {MAX, 0};
    else if (l <= s && e <= r)
        return tree[n];
    else {
        int m = s + e >> 1;
        return merge(
            query(n << 1, s, m, l, r),
            query(n << 1 | 1, m + 1, e, l, r));
    }
}

void update(int n, int s, int e, int l, int r, int v) {
    lazy_propagate(n, s, e);
    if (r < s || e < l)
        return;
    else if (l <= s && e <= r) {
        lazy[n] += v;
        lazy_propagate(n, s, e);
        return;
    } else {
        int m = s + e >> 1;
        update(n << 1, s, m, l, r, v), update(n << 1 | 1, m + 1, e, l, r, v);
        tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
    }
}

void upd(int X, int V) {
    int K = max(P[2][X], P[3][X]);
    if (K > P[1][X])
        update(1, 1, N, P[1][X], K - 1, V);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int Q, T, X, A, B;
    pr V;

    bool res;
    cin >> N >> Q;

    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= N; j++)
            cin >> X, P[i][X] = j;

    init(1, 1, N);
    for (int i = 1; i <= N; i++)
        upd(i, 1);
    V = query(1, 1, N, 1, N);

    while (Q--) {
        cin >> T;
        if (T == 1) {
            cin >> X;
            A = min({P[1][X], P[2][X], P[3][X]});
            res = V[0] == 0 && A <= V[1];
            cout << (res ? "DA" : "NE") << '\n';
        } else {
            cin >> X >> A >> B;
            upd(A, -1), upd(B, -1);
            swap(P[X][A], P[X][B]);
            upd(A, 1), upd(B, 1);
            V = query(1, 1, N, 1, N);
        }
    }

    return 0;
}