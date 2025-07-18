#include <bits/stdc++.h>
using namespace std;

const int MAX = 200001;
const int INF = 1'000'000'000;

struct Node {
    int lazy_H_max = -INF, lazy_H_min = INF, H_max = -INF, H_min = INF, mx = -1;
};

int L[MAX], ans[MAX], H[MAX], A[MAX], B[MAX];
vector<int> queries[MAX], arr[MAX];

Node tree[MAX * 4];

Node merge(Node a, Node b) {
    Node res;
    res.H_max = max(a.H_max, b.H_max), res.H_min = min(a.H_min, b.H_min);
    res.mx = max(a.mx, b.mx);
    return res;
}

void lazy_update(int n, int s, int e) {
    if (tree[n].lazy_H_max == -INF)
        return;
    tree[n].mx = max({tree[n].mx, tree[n].H_max - tree[n].lazy_H_min, tree[n].lazy_H_max - tree[n].H_min});
    if (s ^ e) {
        tree[n << 1].lazy_H_max = max(tree[n << 1].lazy_H_max, tree[n].lazy_H_max);
        tree[n << 1].lazy_H_min = min(tree[n << 1].lazy_H_min, tree[n].lazy_H_min);
        tree[n << 1 | 1].lazy_H_max = max(tree[n << 1 | 1].lazy_H_max, tree[n].lazy_H_max);
        tree[n << 1 | 1].lazy_H_min = min(tree[n << 1 | 1].lazy_H_min, tree[n].lazy_H_min);
    }
    tree[n].lazy_H_max = -INF, tree[n].lazy_H_min = INF;
}

void init(int n, int s, int e) {
    if (s == e)
        tree[n] = Node();
    else {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
        tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
    }
}

int query(int n, int s, int e, int l, int r) {
    lazy_update(n, s, e);
    if (r < s || e < l)
        return -1;
    else if (l <= s && e <= r)
        return tree[n].mx;
    else {
        int m = s + e >> 1;
        return max(query(n << 1, s, m, l, r), query(n << 1 | 1, m + 1, e, l, r));
    }
}

void update_x(int n, int s, int e, int x, int v) {
    lazy_update(n, s, e);
    if (x < s || e < x)
        return;
    else if (s == e) {
        if (v == 1)
            tree[n].H_max = H[x], tree[n].H_min = H[x];
        else
            tree[n].H_max = -INF, tree[n].H_min = INF;
    } else {
        int m = s + e >> 1;
        update_x(n << 1, s, m, x, v), update_x(n << 1 | 1, m + 1, e, x, v);
        tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
    }
}

void update(int n, int s, int e, int l, int r, int v) {
    lazy_update(n, s, e);
    if (r < s || e < l)
        return;
    else if (l <= s && e <= r) {
        tree[n].lazy_H_max = tree[n].lazy_H_min = v;
        lazy_update(n, s, e);
    } else {
        int m = s + e >> 1;
        update(n << 1, s, m, l, r, v), update(n << 1 | 1, m + 1, e, l, r, v);
        tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, X;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> H[i] >> A[i] >> B[i];
        if (i + A[i] <= N)
            arr[i + A[i]].push_back(i);
        if (i + B[i] + 1 <= N)
            arr[i + B[i] + 1].push_back(-i);
    }

    cin >> Q;
    for (int i = 1; i <= Q; i++) {
        cin >> L[i] >> X;
        queries[X].push_back(i);
    }

    for (int i = 1; i <= N; i++) {
        for (int j : arr[i])
            update_x(1, 1, N, abs(j), j > 0 ? 1 : -1);
        update(1, 1, N, i - B[i], i - A[i], H[i]);
        for (int j : queries[i])
            ans[j] = query(1, 1, N, L[j], i);
    }

    for (int i = 1; i <= Q; i++)
        cout << ans[i] << '\n';

    return 0;
}