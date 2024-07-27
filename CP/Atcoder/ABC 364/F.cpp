#include <bits/stdc++.h>
#define int long long
#define MAX 200100

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

class LazyPropagition {
  private:
    void lazy_update(int n, int s, int e) {
        if (lazy[n] != LLONG_MAX) {
            tree[n] = min(tree[n], lazy[n]);
            if (s != e) {
                lazy[n << 1] = min(lazy[n << 1], lazy[n]);
                lazy[n << 1 | 1] = min(lazy[n << 1 | 1], lazy[n]);
            }
            lazy[n] = LLONG_MAX;
        }
    }

    int query(int n, int s, int e, int l, int r) {
        lazy_update(n, s, e);
        if (l <= s && e <= r)
            return tree[n];
        else if (r < s || e < l)
            return LLONG_MAX;
        else {
            int lv = query(n << 1, s, ((s + e) >> 1), l, r);
            int rv = query(n << 1 | 1, ((s + e) >> 1) + 1, e, l, r);
            return min(lv, rv);
        }
    }

    void update(int n, int s, int e, int l, int r, int val) {
        lazy_update(n, s, e);
        if (r < s || e < l)
            return;
        else if (l <= s && e <= r) {
            lazy[n] = min(lazy[n], val);
            lazy_update(n, s, e);
        } else {
            update(n << 1, s, (s + e) >> 1, l, r, val);
            update(n << 1 | 1, ((s + e) >> 1) + 1, e, l, r, val);
            tree[n] = min(tree[n << 1], tree[n << 1 | 1]);
        }
    }

  public:
    int N;
    vector<int> tree, lazy;

    LazyPropagition(int n) : N(n), tree(4 * n, LLONG_MAX), lazy(4 * n, LLONG_MAX) {}

    int query(int pos) { return query(1, 1, N, pos, pos); }
    int query(int l, int r) { return query(1, 1, N, l, r); }
    void update(int l, int r, int val) { update(1, 1, N, l, r, val); }
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, A, B, C, res = 0, E = 1, X;
    cin >> N >> Q;

    LazyPropagition tree(N);

    vector<tp> arr;
    tp K;

    for (int i = 1; i <= Q; i++) {
        cin >> A >> B >> C;
        arr.push_back({A, B, C});
    }
    sort(arr.begin(), arr.end());

    for (int i = 1; i <= Q; i++) {
        K = arr[i - 1];
        if (K[0] > E) {
            cout << -1;
            return 0;
        }

        res += K[2];
        tree.update(K[0] + 1, K[1], K[2]);

        E = max(E, K[1]);
    }
    if (E < N) {
        cout << -1;
        return 0;
    }

    for (int i = 1; i <= N; i++) {
        X = tree.query(i);
        if (X < LLONG_MAX)
            res += X;
    }

    cout << res;

    return 0;
}