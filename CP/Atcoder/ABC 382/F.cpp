#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int R[MAX], C[MAX], L[MAX], res[MAX];

class LazyPropagation {
  private:
    void lazy_update(int n, int s, int e) {
        if (lazy[n] != 0) {
            tree[n] = max(tree[n], lazy[n]);
            if (s != e) {
                lazy[n << 1] = max(lazy[n << 1], lazy[n]);
                lazy[n << 1 | 1] = max(lazy[n << 1 | 1], lazy[n]);
            }
            lazy[n] = 0;
        }
    }

    int query(int n, int s, int e, int l, int r) {
        lazy_update(n, s, e);
        if (l <= s && e <= r)
            return tree[n];
        else if (r < s || e < l)
            return 0;
        else {
            int lv = query(n << 1, s, ((s + e) >> 1), l, r);
            int rv = query(n << 1 | 1, ((s + e) >> 1) + 1, e, l, r);
            return max(lv, rv);
        }
    }

    void update(int n, int s, int e, int l, int r, int val) {
        lazy_update(n, s, e);
        if (r < s || e < l)
            return;
        else if (l <= s && e <= r) {
            lazy[n] = max(lazy[n], val);
            lazy_update(n, s, e);
        } else {
            update(n << 1, s, (s + e) >> 1, l, r, val);
            update(n << 1 | 1, ((s + e) >> 1) + 1, e, l, r, val);
            tree[n] = max(tree[n << 1], tree[n << 1 | 1]);
        }
    }

  public:
    int N;
    vector<int> tree, lazy;

    LazyPropagation(int n) : N(n), tree(4 * n + 1, 0), lazy(4 * n + 1, 0) {}

    int query(int l, int r) { return query(1, 1, N, l, r); }
    void update(int l, int r, int val) { update(1, 1, N, l, r, val); }
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int H, W, N;
    cin >> H >> W >> N;

    vector<int> arr;

    for (int i = 1; i <= N; i++) {
        cin >> R[i] >> C[i] >> L[i];
        arr.push_back(i);
    }

    sort(arr.begin(), arr.end(), [&](int a, int b) { return R[a] > R[b]; });

    LazyPropagation tree(N);

    for (int i : arr) {
        res[i] = tree.query(C[i], C[i] + L[i] - 1);
        tree.update(C[i], C[i] + L[i] - 1, res[i] + 1);
    }

    for (int i = 1; i <= N; i++)
        cout << H - res[i] << '\n';

    return 0;
}