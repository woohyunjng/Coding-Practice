#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 200001;
const int INF = 0x3f3f3f3f3f3f3f3f;

int A[MAX], tree[MAX * 4], lazy[MAX * 4][2];

void init(int n, int s, int e) {
    if (s == e)
        tree[n] = A[s];
    else {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
        tree[n] = max(tree[n << 1], tree[n << 1 | 1]);
    }
}

void lazy_update(int n, int s, int e) {
    if (lazy[n][0] == 0 && lazy[n][1] == 0)
        return;
    tree[n] += lazy[n][0], tree[n] = max(tree[n], lazy[n][1]);
    if (s ^ e) {
        lazy[n << 1][0] += lazy[n][0], lazy[n << 1 | 1][0] += lazy[n][0];
        lazy[n << 1][1] += lazy[n][0], lazy[n << 1 | 1][1] += lazy[n][0];
        lazy[n << 1][1] = max(lazy[n << 1][1], lazy[n][1]), lazy[n << 1 | 1][1] = max(lazy[n << 1 | 1][1], lazy[n][1]);
    }
    lazy[n][0] = lazy[n][1] = 0;
}

int query(int n, int s, int e, int l, int r) {
    lazy_update(n, s, e);
    if (r < s || e < l)
        return 0;
    else if (l <= s && e <= r)
        return tree[n];
    else {
        int m = s + e >> 1;
        return max(query(n << 1, s, m, l, r), query(n << 1 | 1, m + 1, e, l, r));
    }
}

void update(int n, int s, int e, int l, int r, int x) {
    lazy_update(n, s, e);
    if (r < s || e < l)
        return;
    else if (l <= s && e <= r) {
        if (x == -1)
            lazy[n][0] = 1;
        else
            lazy[n][1] = x;
        lazy_update(n, s, e);
    } else {
        int m = s + e >> 1;
        update(n << 1, s, m, l, r, x), update(n << 1 | 1, m + 1, e, l, r, x);
        tree[n] = max(tree[n << 1], tree[n << 1 | 1]);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, L, R, X;

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    init(1, 1, N);

    while (M--) {
        cin >> L >> R;
        X = query(1, 1, N, L, R);
        update(1, 1, N, L, R, -1), update(1, 1, N, L, R, X);
    }

    for (int i = 1; i <= N; i++)
        cout << query(1, 1, N, i, i) << ' ';
    cout << '\n';

    return 0;
}