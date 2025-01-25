#include <bits/stdc++.h>
#define int long long

#define MAX 600000
using namespace std;

typedef array<int, 4> tp;

tp merge(tp X, tp Y) {
    tp res = {
        X[0] + Y[0],
        max(X[1], X[0] + Y[1]),
        max(Y[2], X[2] + Y[0]),
        max({X[1] + Y[2], X[3] + Y[0], X[0] + Y[3]})};
    return res;
}

int A[MAX];
tp tree[MAX * 4];

void init(int n, int s, int e) {
    if (s == e)
        tree[n] = {
            A[s],
            max(0ll, A[s]),
            max(0ll, A[s]),
            max(0ll, A[s])};
    else {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
        tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
    }
}

tp query(int n, int s, int e, int l, int r) {
    if (r < s || e < l)
        return {0, 0, 0, 0};
    else if (l <= s && e <= r)
        return tree[n];
    else {
        int m = s + e >> 1;
        return merge(
            query(n << 1, s, m, l, r),
            query(n << 1 | 1, m + 1, e, l, r));
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, L, R;
    tp res;
    string S;

    cin >> N >> S;
    for (int i = 1; i <= N; i++)
        A[i] = S[i - 1] == 'T' ? 1 : -1;

    init(1, 1, N);

    cin >> Q;
    while (Q--) {
        cin >> L >> R, res = query(1, 1, N, L, R);
        cout << res[3] << '\n';
    }

    return 0;
}