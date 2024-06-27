#include <bits/stdc++.h>
#define int long long
#define MAX 1000

using namespace std;

int gcd(int a, int b) {
    int k;
    a = abs(a), b = abs(b);
    while (b) {
        k = a % b;
        a = b;
        b = k;
    }
    return a;
}

class SumLazyPropagition {
  private:
    void init(int n, int s, int e) {
        if (s == e)
            tree[n] = arr[s];
        else {
            init(n << 1, s, (s + e) >> 1);
            init(n << 1 | 1, ((s + e) >> 1) + 1, e);
            tree[n] = tree[n << 1] + tree[n << 1 | 1];
        }
    }

    void lazy_update(int n, int s, int e) {
        if (lazy[n] != 0) {
            tree[n] += (e - s + 1) * lazy[n];
            if (s != e) {
                lazy[n << 1] += lazy[n];
                lazy[n << 1 | 1] += lazy[n];
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
            arr[s] += val;
        } else {
            update(n << 1, s, (s + e) >> 1, l, r, val);
            update(n << 1 | 1, ((s + e) >> 1) + 1, e, l, r, val);
            tree[n] = tree[n << 1] + tree[n << 1 | 1];
        }
    }

  public:
    int N, arr[MAX];
    int tree[4 * MAX + 1], lazy[4 * MAX + 1];

    SumLazyPropagition(int n) : N(n) {}

    void init() { init(1, 1, N); }
    int query(int pos) { return query(1, 1, N, pos, pos); }
    int query(int l, int r) { return query(1, 1, N, l, r); }
    void update(int l, int r, int val) { update(1, 1, N, l, r, val); }
};

class GCDSegTree {
  private:
    void init(int n, int s, int e) {
        if (s == e)
            tree[n] = arr[s];
        else {
            init(n << 1, s, (s + e) >> 1);
            init(n << 1 | 1, ((s + e) >> 1) + 1, e);
            tree[n] = gcd(tree[n << 1], tree[n << 1 | 1]);
        }
    }

    int query(int n, int s, int e, int l, int r) {
        if (l <= s && e <= r)
            return tree[n];
        else if (r < s || e < l)
            return 0;
        else {
            int lv = query(n << 1, s, ((s + e) >> 1), l, r);
            int rv = query(n << 1 | 1, ((s + e) >> 1) + 1, e, l, r);
            return gcd(lv, rv);
        }
    }

    void update(int n, int s, int e, int pos, int val) {
        if (pos < s || e < pos)
            return;
        else if (s == e) {
            tree[n] += val;
            arr[s] += val;
        } else {
            update(n << 1, s, (s + e) >> 1, pos, val);
            update(n << 1 | 1, ((s + e) >> 1) + 1, e, pos, val);
            tree[n] = gcd(tree[n << 1], tree[n << 1 | 1]);
        }
    }

  public:
    int N, arr[MAX];
    int tree[4 * MAX + 1];

    GCDSegTree(int n) : N(n) {}

    void init() { init(1, 1, N); }
    int query(int pos) { return query(1, 1, N, pos, pos); }
    int query(int l, int r) { return query(1, 1, N, l, r); }
    void update(int pos, int val) { update(1, 1, N, pos, val); }
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, Q, A, B, C;
    cin >> N;

    SumLazyPropagition sumtree(N);
    for (int i = 1; i <= N; i++)
        cin >> sumtree.arr[i];
    sumtree.init();

    GCDSegTree gcdtree(N - 1);
    for (int i = 1; i <= N - 1; i++)
        gcdtree.arr[i] = sumtree.arr[i + 1] - sumtree.arr[i];
    gcdtree.init();

    cin >> Q;
    while (Q--) {
        cin >> A >> B >> C;
        if (A) {
            gcdtree.update(C, -A);
            gcdtree.update(B - 1, A);
            sumtree.update(B, C, A);
        } else {
            cout << gcd(sumtree.arr[B], gcdtree.query(B, C - 1)) << '\n';
        }
    }

    return 0;
}