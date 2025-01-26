#include <bits/stdc++.h>
#define int long long

#define MAX 200000
#define MAX_S 26
using namespace std;

typedef array<int, 3> tp;

int A[MAX];
tp tree[MAX_S + 1][MAX * 4];

tp merge(tp X, tp Y) {
    tp res = {X[0] + Y[0], X[1] + Y[1], 0};
    res[2] = min(X[1] + Y[2], X[2] + Y[0]);
    return res;
}

void init(int t, int n, int s, int e) {
    if (s == e)
        tree[t][n] = {A[s] < t, A[s] >= t, 0};
    else {
        int m = s + e >> 1;
        init(t, n << 1, s, m), init(t, n << 1 | 1, m + 1, e);
        tree[t][n] = merge(tree[t][n << 1], tree[t][n << 1 | 1]);
    }
}

void update(int t, int n, int s, int e, int x, int v) {
    if (x < s || e < x)
        return;
    else if (s == e)
        tree[t][n] = {v < t, v >= t, 0};
    else {
        int m = s + e >> 1;
        update(t, n << 1, s, m, x, v), update(t, n << 1 | 1, m + 1, e, x, v);
        tree[t][n] = merge(tree[t][n << 1], tree[t][n << 1 | 1]);
    }
}

tp query(int t, int n, int s, int e, int l, int r) {
    if (r < s || e < l)
        return {0, 0, 0};
    else if (l <= s && e <= r)
        return tree[t][n];
    else {
        int m = s + e >> 1;
        return merge(
            query(t, n << 1, s, m, l, r),
            query(t, n << 1 | 1, m + 1, e, l, r));
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, X, Y, res;
    string S;
    char C;

    cin >> S, N = S.size();

    for (int i = 1; i <= N; i++)
        A[i] = S[i - 1] - 'a' + 1;

    for (int i = 2; i <= MAX_S; i++)
        init(i, 1, 1, N);

    res = 0;
    for (int i = 2; i <= MAX_S; i++)
        res += query(i, 1, 1, N, 1, N)[2];
    cout << res << '\n';

    cin >> Q;
    while (Q--) {
        cin >> X >> C, Y = C - 'a' + 1, res = 0;
        for (int i = 2; i <= MAX_S; i++)
            update(i, 1, 1, N, X, Y);

        for (int i = 2; i <= MAX_S; i++)
            res += query(i, 1, 1, N, 1, N)[2];
        cout << res << '\n';
    }

    return 0;
}