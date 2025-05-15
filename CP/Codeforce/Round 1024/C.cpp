#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 200001;

int A[MAX], tree[MAX * 4], lazy[MAX * 4];
vector<int> arr[MAX];

void init(int n, int s, int e) {
    tree[n] = lazy[n] = 0;
    if (s == e)
        tree[n] = -s;
    else {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
        tree[n] = max(tree[n << 1], tree[n << 1 | 1]);
    }
}

void lazy_update(int n, int s, int e) {
    if (!lazy[n])
        return;
    tree[n] += lazy[n];
    if (s ^ e)
        lazy[n << 1] += lazy[n], lazy[n << 1 | 1] += lazy[n];
    lazy[n] = 0;
}

int query(int n, int s, int e, int l, int r) {
    lazy_update(n, s, e);
    if (r < s || e < l)
        return MAX;
    else if (l <= s && e <= r)
        return tree[n];
    else {
        int m = s + e >> 1;
        return max(query(n << 1, s, m, l, r), query(n << 1 | 1, m + 1, e, l, r));
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
        tree[n] = max(tree[n << 1], tree[n << 1 | 1]);
    }
}

void solve() {
    int N, ans = 0, V = 0, X, Y;
    vector<int> L, R;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    init(1, 1, N);
    for (int i = 1; i <= N; i++) {
        update(1, 1, N, A[i], N, 1);
        if (query(1, 1, N, 1, N) > 0)
            update(1, 1, N, A[i], N, -1);
        else
            L.push_back(i);
    }

    init(1, 1, N);
    for (int i = N; i >= 1; i--) {
        update(1, 1, N, A[i], N, 1);
        if (query(1, 1, N, 1, N) > 0)
            update(1, 1, N, A[i], N, -1);
        else
            R.push_back(i);
    }

    for (int i = 0; i < max(L.size(), R.size()); i++)
        ans += max(0ll, R[i] - L[i]);

    cout << ans << '\n';
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