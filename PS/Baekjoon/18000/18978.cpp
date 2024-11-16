#include <bits/stdc++.h>
#define int long long

#define MAX 250100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int K;

class FenwickTree {
  public:
    int N;
    vector<int> arr, tree;

    FenwickTree(int n) : N(n), arr(n + 1, 0), tree(n + 1, 0) {}

    void build() {
        for (int i = 1; i <= N; i++) {
            tree[i] += arr[i];
            if (i + (i & -i) <= N)
                tree[i + (i & -i)] += tree[i];
        }
    }

    void update(int n, int val) {
        arr[n] += val;
        while (n <= N) {
            tree[n] += val;
            n += n & -n;
        }
    }

    int query(int n) {
        int res = 0;
        while (n) {
            res += tree[n];
            n -= n & -n;
        }
        return res;
    }

    int query(int l, int r) { return query(r) - query(l - 1); }
} ftree(MAX);

class SegTree {
  private:
    void init(int n, int s, int e) {
        if (s == e)
            tree[n] = arr[s];
        else {
            init(n << 1, s, (s + e) >> 1);
            init(n << 1 | 1, ((s + e) >> 1) + 1, e);
            tree[n] = tree[n << 1] & tree[n << 1 | 1];
        }
    }

    int query(int n, int s, int e, int l, int r) {
        if (l <= s && e <= r)
            return tree[n];
        else if (r < s || e < l)
            return (1ll << 30) - 1;
        else {
            int lv = query(n << 1, s, ((s + e) >> 1), l, r);
            int rv = query(n << 1 | 1, ((s + e) >> 1) + 1, e, l, r);
            return lv & rv;
        }
    }

    void update(int n, int s, int e, int l, int r, int val) {
        if (r < s || e < l || (tree[n] & val) == val)
            return;
        else if (s == e) {
            ftree.update(s, -(tree[n] == K));
            tree[n] |= val;
            ftree.update(s, tree[n] == K);
        } else {
            update(n << 1, s, (s + e) >> 1, l, r, val);
            update(n << 1 | 1, ((s + e) >> 1) + 1, e, l, r, val);
            tree[n] = tree[n << 1] & tree[n << 1 | 1];
        }
    }

  public:
    int N;
    vector<int> arr, tree;

    SegTree(int n) : N(n), arr(n + 1), tree(n * 4 + 1) {}

    void init() { init(1, 1, N); }
    int query(int l, int r) { return query(1, 1, N, l, r); }
    void update(int l, int r, int val) { update(1, 1, N, l, r, val); }
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, T, L, R, X;
    cin >> N >> K;

    SegTree tree(N);

    for (int i = 1; i <= N; i++) {
        cin >> tree.arr[i];
        ftree.arr[i] = tree.arr[i] == K;
    }
    tree.init(), ftree.build();

    cin >> M;
    while (M--) {
        cin >> T >> L >> R;
        if (T == 1) {
            cin >> X;
            tree.update(L, R, X);
        } else
            cout << ftree.query(L, R) << '\n';
    }

    return 0;
}