#include <bits/stdc++.h>
#define int long long

#define MAX 200100
using namespace std;

int A[MAX], V[MAX], tree[MAX * 4];

int comp(int X, int Y) {
    if (V[X] < V[Y])
        return Y;
    else if (V[X] > V[Y])
        return X;
    else
        return max(X, Y);
}

void init(int n, int s, int e) {
    if (s == e)
        tree[n] = s;
    else {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
        tree[n] = comp(tree[n << 1], tree[n << 1 | 1]);
    }
}

int query(int n, int s, int e, int l, int r) {
    if (r < s || e < l)
        return 0;
    if (l <= s && e <= r)
        return tree[n];
    int m = s + e >> 1;
    return comp(query(n << 1, s, m, l, r), query(n << 1 | 1, m + 1, e, l, r));
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, L, R, X, st, en, mid, res;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> A[i];

    V[0] = -1;
    for (int i = 1; i <= N; i++)
        V[i] = lower_bound(A + 1, A + N + 1, A[i] * 2) - A - i;
    init(1, 1, N);

    cin >> Q;
    while (Q--) {
        cin >> L >> R, res = 0;
        st = 1, en = (R - L + 1) / 2;

        while (st <= en) {
            mid = st + en >> 1;
            X = query(1, 1, N, L, L + mid - 1);

            if (V[X] + X <= R - mid + 1 + (X - L))
                res = mid, st = mid + 1;
            else
                en = mid - 1;
        }

        cout << res << '\n';
    }

    return 0;
}