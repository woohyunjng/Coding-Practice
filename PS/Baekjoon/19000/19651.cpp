#include <bits/stdc++.h>
#define int long long
#define MAX 100010
#define MIN_VAL -100001

using namespace std;

class Node {
  public:
    int left_max = 0, left_val = MIN_VAL, right_max = 0, right_val = MIN_VAL, mx = 0, size = 0;
    Node() {}
    Node(int v) : left_val(v), right_val(v) { left_max = right_max = mx = size = 1; }
    Node operator+(Node &ref) {
        if (!size)
            return ref;
        else if (!ref.size)
            return *this;

        Node res;
        res.size = size + ref.size;

        res.left_max = left_max;
        res.left_val = left_val;
        if (left_max == size && ref.left_val == left_val)
            res.left_max += ref.left_max;

        res.right_max = ref.right_max;
        res.right_val = ref.right_val;
        if (ref.right_max == ref.size && ref.right_val == right_val)
            res.right_max += right_max;

        res.mx = max(mx, ref.mx);
        if (right_val == ref.left_val)
            res.mx = max(res.mx, right_max + ref.left_max);

        return res;
    }
};

class LazyPropagition {
  private:
    void init(int n, int s, int e) {
        if (s == e)
            tree[n] = Node(arr[s]);
        else {
            init(n << 1, s, (s + e) >> 1);
            init(n << 1 | 1, ((s + e) >> 1) + 1, e);
            tree[n] = tree[n << 1] + tree[n << 1 | 1];
        }
    }

    void lazy_update(int n, int s, int e) {
        if (lazy[n] != 0) {
            tree[n].left_val += lazy[n];
            tree[n].right_val += lazy[n];
            if (s != e) {
                lazy[n << 1] += lazy[n];
                lazy[n << 1 | 1] += lazy[n];
            }
            lazy[n] = 0;
        }
    }

    Node query(int n, int s, int e, int l, int r) {
        lazy_update(n, s, e);
        if (l <= s && e <= r)
            return tree[n];
        else if (r < s || e < l)
            return Node();
        else {
            Node lv = query(n << 1, s, ((s + e) >> 1), l, r);
            Node rv = query(n << 1 | 1, ((s + e) >> 1) + 1, e, l, r);
            return lv + rv;
        }
    }

    void update(int n, int s, int e, int l, int r, int val) {
        lazy_update(n, s, e);
        if (r < s || e < l)
            return;
        else if (l <= s && e <= r) {
            lazy[n] += val;
            lazy_update(n, s, e);
        } else {
            update(n << 1, s, (s + e) >> 1, l, r, val);
            update(n << 1 | 1, ((s + e) >> 1) + 1, e, l, r, val);
            tree[n] = tree[n << 1] + tree[n << 1 | 1];
        }
    }

  public:
    int N, arr[MAX], lazy[4 * MAX + 1];
    Node tree[4 * MAX + 1];

    LazyPropagition(int n) : N(n) {}

    void init() { init(1, 1, N); }
    Node query(int pos) { return query(1, 1, N, pos, pos); }
    Node query(int l, int r) { return query(1, 1, N, l, r); }
    void update(int l, int r, int val) { update(1, 1, N, l, r, val); }
};

int lst[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, A, B, C, D, E;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> lst[i];

    LazyPropagition tree(N - 1);
    for (int i = 1; i < N; i++)
        tree.arr[i] = lst[i + 1] - lst[i];
    tree.init();

    cin >> M;
    while (M--) {
        cin >> A >> B >> C;
        if (A == 1) {
            cin >> D >> E;
            tree.update(B - 1, B - 1, D);
            tree.update(B, C - 1, E);
            tree.update(C, C, -(D + E * (C - B)));
        } else
            cout << tree.query(B, C - 1).mx + 1 << '\n';
    }

    return 0;
}