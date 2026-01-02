#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 4> tp;

const int MAX = 300001;

int L[MAX], R[MAX];
tp tree[2][MAX * 4];

tp merge(tp X, tp Y) {
    if (X[0] == -1)
        return Y;
    else if (Y[0] == -1)
        return X;

    tp res;
    if (X[0] == 0 && Y[0] == 0) {
        if (X[2] <= Y[1])
            res = {1, Y[1], X[2], 0};
        else if (Y[2] <= X[1])
            res = {1, Y[2], X[1], X[1] - Y[2]};
        else
            res = {0, max(X[1], Y[1]), min(X[2], Y[2]), 0};
    } else if (X[0] == 0 && Y[0] == 1)
        res = {1, Y[1], max(X[1], min(X[2], Y[2])), X[1] <= Y[2] ? 0 : X[1] - Y[2]};
    else if (X[0] == 1 && Y[0] == 0)
        res = {1, min(Y[2], max(X[1], Y[1])), X[2], X[1] >= Y[2] ? X[1] - Y[2] : 0};
    else
        res = {1, Y[1], X[2], X[1] >= Y[2] ? X[1] - Y[2] : 0};
    res[3] += X[3] + Y[3];

    return res;
}

void init(int n, int s, int e) {
    if (s == e) {
        tree[0][n] = (tp){0, L[s] - s, R[s] - 1 - s, 0};
        tree[1][n] = (tp){0, L[s] + s, R[s] - 1 + s, 0};
    } else {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
        tree[0][n] = merge(tree[0][n << 1], tree[0][n << 1 | 1]);
        tree[1][n] = merge(tree[1][n << 1 | 1], tree[1][n << 1]);
    }
}

void update(int n, int s, int e, int x) {
    if (x < s || e < x)
        return;
    else if (s == e) {
        tree[0][n] = (tp){0, L[s] - s, R[s] - 1 - s, 0};
        tree[1][n] = (tp){0, L[s] + s, R[s] - 1 + s, 0};
    } else {
        int m = s + e >> 1;
        update(n << 1, s, m, x), update(n << 1 | 1, m + 1, e, x);
        tree[0][n] = merge(tree[0][n << 1], tree[0][n << 1 | 1]);
        tree[1][n] = merge(tree[1][n << 1 | 1], tree[1][n << 1]);
    }
}

tp query(int rv, int n, int s, int e, int l, int r) {
    if (r < s || e < l)
        return (tp){-1, -1, -1, -1};
    else if (l <= s && e <= r)
        return tree[rv][n];
    else {
        int m = s + e >> 1;
        tp lval = query(rv, n << 1, s, m, l, r), rval = query(rv, n << 1 | 1, m + 1, e, l, r);
        if (rv == 0)
            return merge(lval, rval);
        else
            return merge(rval, lval);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, T, P, S, E, A, B, C, D, ans;
    tp K;

    cin >> N >> Q;
    for (int i = 1; i < N; i++)
        cin >> L[i] >> R[i];

    if (N > 1)
        init(1, 1, N - 1);

    while (Q--) {
        cin >> T;
        if (T == 1) {
            cin >> P >> S >> E, L[P] = S, R[P] = E;
            update(1, 1, N - 1, P), update(1, 1, N - 1, P);
        } else {
            cin >> A >> B >> C >> D, ans = 0;
            if (A == C) {
                cout << max(0ll, B - D) << '\n';
                continue;
            } else if (A < C)
                K = query(0, 1, 1, N - 1, A, C - 1), B -= A, D -= C;
            else
                K = query(1, 1, 1, N - 1, C, A - 1), B += A - 1, D += C - 1;

            if (B > K[2])
                ans += B - K[2], B = K[2];
            B = K[0] == 0 ? max(B, K[1]) : K[1];
            ans += max(0ll, B - D) + K[3];
            cout << ans << '\n';
        }
    }

    return 0;
}