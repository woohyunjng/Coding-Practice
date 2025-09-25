#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 200001;
const int INF = 0x3f3f3f3f3f3f3f3f;

int V[MAX], A[MAX], B[MAX], D[MAX], tree[MAX * 4], lazy[MAX * 4];

void lazy_update(int n, int s, int e) {
    if (lazy[n] == 0)
        return;
    tree[n] += lazy[n];
    if (s ^ e)
        lazy[n << 1] += lazy[n], lazy[n << 1 | 1] += lazy[n];
    lazy[n] = 0;
}

void init(int n, int s, int e) {
    tree[n] = lazy[n] = 0;
    if (s ^ e) {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
    }
}

int query(int n, int s, int e, int l, int r) {
    lazy_update(n, s, e);
    if (r < s || e < l)
        return -INF;
    else if (l <= s && e <= r)
        return tree[n];
    else {
        int m = s + e >> 1;
        return max(
            query(n << 1, s, m, l, r),
            query(n << 1 | 1, m + 1, e, l, r));
    }
}

void update(int n, int s, int e, int l, int r, int v) {
    lazy_update(n, s, e);
    if (r < s || e < l)
        return;
    else if (l <= s && e <= r)
        lazy[n] += v, lazy_update(n, s, e);
    else {
        int m = s + e >> 1;
        update(n << 1, s, m, l, r, v), update(n << 1 | 1, m + 1, e, l, r, v);
        tree[n] = max(tree[n << 1], tree[n << 1 | 1]);
    }
}

void solve() {
    int N, X;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> V[i];
    for (int i = 1; i <= N; i++)
        cin >> A[i], D[A[i]] = i;
    for (int i = 1; i <= N; i++)
        cin >> X, B[D[X]] = i;

    init(1, 0, N);
    for (int i = 1; i <= N; i++) {
        X = query(1, 0, N, 0, B[i]);
        update(1, 0, N, B[i], B[i], -query(1, 0, N, B[i], B[i]) + X);
        update(1, 0, N, 0, B[i] - 1, V[A[i]]);
    }

    cout << query(1, 0, N, 0, N) << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;

    while (T--)
        solve();

    return 0;
}