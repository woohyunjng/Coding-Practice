#include <bits/stdc++.h>
#define int long long
#define MAX 1001

using namespace std;
typedef pair<int, int> pr;

class LazyPropagition {
  private:
    pr merge(pr A, pr B) {
        pr res;
        res.first = min(max(A.first, B.first), B.second);
        res.second = min(max(A.second, B.first), B.second);
        return res;
    }

    void lazy_update(int n, int s, int e) {
        if (s != e) {
            tree[n << 1] = merge(tree[n << 1], tree[n]);
            tree[n << 1 | 1] = merge(tree[n << 1 | 1], tree[n]);
            tree[n] = {0, LLONG_MAX};
        }
    }

    pr query(int n, int s, int e, int l, int r) {
        lazy_update(n, s, e);
        if (l <= s && e <= r)
            return tree[n];
        else if (r < s || e < l)
            return {0, LLONG_MAX};
        else {
            pr lv = query(n << 1, s, ((s + e) >> 1), l, r);
            pr rv = query(n << 1 | 1, ((s + e) >> 1) + 1, e, l, r);
            return merge(lv, rv);
        }
    }

    void update(int n, int s, int e, int l, int r, pr val) {
        lazy_update(n, s, e);
        if (r < s || e < l)
            return;
        else if (l <= s && e <= r) {
            tree[n] = merge(tree[n], val);
            lazy_update(n, s, e);
        } else {
            update(n << 1, s, (s + e) >> 1, l, r, val);
            update(n << 1 | 1, ((s + e) >> 1) + 1, e, l, r, val);
        }
    }

  public:
    int N;
    pr tree[4 * MAX + 1], lazy[4 * MAX + 1];

    LazyPropagition(int n) : N(n) {}

    pr query(int pos) { return query(1, 1, N, pos, pos); }
    void update(int l, int r, pr val) { update(1, 1, N, l, r, val); }
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K, A, B, C, D;
    cin >> N >> K;

    LazyPropagition tree(N);

    while (K--) {
        cin >> A >> B >> C >> D;
        B++, C++;
        if (A == 1)
            tree.update(B, C, {D, LLONG_MAX});
        else
            tree.update(B, C, {0, D});
    }

    for (int i = 1; i <= N; i++)
        cout << tree.query(i).second << '\n';

    return 0;
}