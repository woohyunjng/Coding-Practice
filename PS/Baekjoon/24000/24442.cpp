#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;

const int MAX = 200001;

int A[MAX], lazy[MAX * 4], B[MAX], C[MAX];
pr tree[MAX * 4];

pr merge(pr X, pr Y) {
    if (X[0] != Y[0])
        return X[0] > Y[0] ? X : Y;
    else
        return X[1] > Y[1] ? X : Y;
}

void init(int n, int s, int e) {
    if (s == e)
        tree[n] = {-MAX, 0};
    else {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
        tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
    }
}

void lazy_update(int n, int s, int e) {
    if (lazy[n] == 0)
        return;
    tree[n][0] += lazy[n];
    if (s ^ e)
        lazy[n << 1] += lazy[n], lazy[n << 1 | 1] += lazy[n];
    lazy[n] = 0;
}

pr query(int n, int s, int e, int l, int r) {
    lazy_update(n, s, e);
    if (r < s || e < l)
        return {-MAX, 0};
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
    lazy_update(n, s, e);
    if (r < s || e < l)
        return;
    else if (l <= s && e <= r)
        lazy[n] = v, lazy_update(n, s, e);
    else {
        int m = s + e >> 1;
        update(n << 1, s, m, l, r, v), update(n << 1 | 1, m + 1, e, l, r, v);
        tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
    }
}

void update_p(int n, int s, int e, int x, pr v) {
    lazy_update(n, s, e);
    if (x < s || e < x)
        return;
    else if (s == e)
        tree[n] = v;
    else {
        int m = s + e >> 1;
        update_p(n << 1, s, m, x, v), update_p(n << 1 | 1, m + 1, e, x, v);
        tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, st, en, md, ans;
    pr X;

    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> A[i], C[i] = i;
        C[i] = B[A[i]], B[A[i]] = i;
    }

    st = 0, en = N, ans = N;
    while (st <= en) {
        md = st + en >> 1, init(1, 0, N);
        update_p(1, 0, N, 0, {0, 0});

        for (int i = 1; i <= N; i++) {
            update(1, 0, N, C[i], i - 1, 1);
            X = query(1, 0, N, 0, i - 1);
            update_p(1, 0, N, i, {X[0] - md, X[1] + 1});
        }
        X = query(1, 0, N, N, N);

        ans = min(ans, md * K + X[0]);
        if (X[1] <= K)
            en = md - 1;
        else
            st = md + 1;
    }

    cout << ans << '\n';

    return 0;
}