#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 600000;

int X[MAX], Y[MAX], tree[MAX * 4], lazy[MAX * 4][2];

void lazy_update(int n, int s, int e) {
    if (lazy[n][0] == 0 && lazy[n][1] == 0)
        return;

    tree[n] = max(tree[n] + lazy[n][0], lazy[n][1]);
    if (s ^ e) {
        lazy[n << 1][0] += lazy[n][0], lazy[n << 1][1] += lazy[n][0];
        lazy[n << 1][1] = max(lazy[n << 1][1], lazy[n][1]);

        lazy[n << 1 | 1][0] += lazy[n][0], lazy[n << 1 | 1][1] += lazy[n][0];
        lazy[n << 1 | 1][1] = max(lazy[n << 1 | 1][1], lazy[n][1]);
    }
    lazy[n][0] = lazy[n][1] = 0;
}

void update(int n, int s, int e, int l, int r, int t, int v) {
    lazy_update(n, s, e);
    if (r < s || e < l)
        return;
    else if (l <= s && e <= r)
        lazy[n][t] = v, lazy_update(n, s, e);
    else {
        int m = s + e >> 1;
        update(n << 1, s, m, l, r, t, v), update(n << 1 | 1, m + 1, e, l, r, t, v);
        tree[n] = max(tree[n << 1], tree[n << 1 | 1]);
    }
}

int query(int n, int s, int e, int l, int r) {
    lazy_update(n, s, e);
    if (r < s || e < l)
        return 0;
    else if (l <= s && e <= r)
        return tree[n];
    else {
        int m = s + e >> 1;
        return max(
            query(n << 1, s, m, l, r),
            query(n << 1 | 1, m + 1, e, l, r));
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, S = 0;
    vector<int> arr, comp;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> X[i] >> Y[i], S += X[i];
        arr.push_back(i), comp.push_back(X[i]);
    }

    sort(arr.begin(), arr.end(), [&](int x, int y) { return Y[x] > Y[y]; });
    sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end());

    for (int i = 1; i <= N; i++) {
        Y[i] = Y[i] - X[i];
        X[i] = lower_bound(comp.begin(), comp.end(), X[i]) - comp.begin() + 1;
    }

    for (int i : arr) {
        update(1, 1, N, 1, X[i] - 1, 0, Y[i]);
        K = query(1, 1, N, X[i] + 1, N) + max(Y[i], 0ll);
        update(1, 1, N, 1, X[i], 1, K);
    }

    cout << S + query(1, 1, N, 1, 1) << '\n';

    return 0;
}