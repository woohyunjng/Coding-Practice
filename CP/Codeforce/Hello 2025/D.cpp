#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define INF 0x7f7f7f7f7f7f7f7f

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

tp merge(tp A, tp B) {
    return {
        max({A[0], B[0], B[2] - A[1]}),
        min(A[1], B[1]),
        max(A[2], B[2])};
}

class SegTree {
  private:
    tp query(int n, int s, int e, int l, int r) {
        if (l <= s && e <= r)
            return tree[n];
        else if (r < s || e < l)
            return {0, 0, 0};
        else {
            tp lv = query(n << 1, s, (s + e) >> 1, l, r);
            tp rv = query(n << 1 | 1, ((s + e) >> 1) + 1, e, l, r);
            return merge(lv, rv);
        }
    }

    void update(int n, int s, int e, int pos, int val) {
        if (pos < s || e < pos)
            return;
        else if (s == e)
            tree[n] = {0, val, val};
        else {
            update(n << 1, s, (s + e) >> 1, pos, val);
            update(n << 1 | 1, ((s + e) >> 1) + 1, e, pos, val);
            tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
        }
    }

  public:
    int N;
    vector<tp> tree;

    SegTree(int n) : N(n), tree(n * 4 + 1, {0, 0, 0}) {}

    tp query(int l, int r) { return query(1, 1, N, l, r); }
    void update(int pos, int val) { update(1, 1, N, pos, val); }
};

int A[MAX];

void solve() {
    int N, Q, P, X, ans = -INF;
    cin >> N >> Q;

    SegTree treeA(N), treeB(N);

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        treeA.update(i, -A[i] - i), treeB.update(i, A[i] - i);
    }
    ans = max(treeA.query(1, N)[0], treeB.query(1, N)[0]);
    cout << ans << '\n';

    while (Q--) {
        cin >> P >> X;
        A[P] = X;
        treeA.update(P, -A[P] - P), treeB.update(P, A[P] - P);
        ans = max(treeA.query(1, N)[0], treeB.query(1, N)[0]);
        cout << ans << '\n';
    }
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