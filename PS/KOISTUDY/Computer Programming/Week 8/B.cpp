#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 1000001;

int A[MAX], tree[MAX * 4];

void init(int n, int s, int e) {
    if (s == e)
        tree[n] = A[s];
    else {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
        tree[n] = tree[n << 1] + tree[n << 1 | 1];
    }
}

int query(int n, int s, int e, int l, int r) {
    if (r < s || e < l)
        return 0;
    else if (l <= s && e <= r)
        return tree[n];
    else {
        int m = s + e >> 1;
        return query(n << 1, s, m, l, r) + query(n << 1 | 1, m + 1, e, l, r);
    }
}

void update(int n, int s, int e, int x, int v) {
    if (x < s || e < x)
        return;
    else if (s == e)
        tree[n] = v;
    else {
        int m = s + e >> 1;
        update(n << 1, s, m, x, v), update(n << 1 | 1, m + 1, e, x, v);
        tree[n] = tree[n << 1] + tree[n << 1 | 1];
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, T, L, R;

    cin >> N >> Q;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    init(1, 1, N);

    while (Q--) {
        cin >> T >> L >> R;
        if (T == 1)
            cout << query(1, 1, N, L, R) << '\n';
        else
            update(1, 1, N, L, R);
    }

    return 0;
}