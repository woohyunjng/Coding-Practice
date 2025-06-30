#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

const int MAX = 250002;
const int INF = 0x3f3f3f3f3f3f3f3f;

struct Node {
    int val = 0, cur = 0;
    Node() = default;
    Node(int val, int cur) : val(val), cur(cur) {}
};

int A[MAX], B[MAX], S[MAX], V[MAX], F[MAX][4], M[MAX][2], lazy[MAX * 4];
bool CH[MAX][2];

vector<int> arr[MAX][2];
vector<pr> queries[MAX];

pr stree[MAX * 4];
Node tree[MAX * 4];

pr merge(pr X, pr Y) { return {min(X[0], Y[0]), max(X[1], Y[1])}; }
Node merge(Node X, Node Y) { return Node(X.val + Y.val, X.cur + Y.cur); }

void sinit(int n, int s, int e) {
    if (s == e)
        stree[n] = {MAX, 0};
    else {
        int m = s + e >> 1;
        sinit(n << 1, s, m), sinit(n << 1 | 1, m + 1, e);
        stree[n] = merge(stree[n << 1], stree[n << 1 | 1]);
    }
}

pr squery(int n, int s, int e, int l, int r) {
    if (r < s || e < l)
        return {MAX, 0};
    else if (l <= s && e <= r)
        return stree[n];
    else {
        int m = s + e >> 1;
        return merge(squery(n << 1, s, m, l, r), squery(n << 1 | 1, m + 1, e, l, r));
    }
}

void supdate(int n, int s, int e, int x, int v) {
    if (x < s || e < x)
        return;
    else if (s == e)
        stree[n][0] = min(stree[n][0], v), stree[n][1] = max(stree[n][1], v);
    else {
        int m = s + e >> 1;
        supdate(n << 1, s, m, x, v), supdate(n << 1 | 1, m + 1, e, x, v);
        stree[n] = merge(stree[n << 1], stree[n << 1 | 1]);
    }
}

void lazy_update(int n, int s, int e) {
    if (lazy[n] == 0)
        return;
    tree[n].val += tree[n].cur * lazy[n];
    if (s ^ e)
        lazy[n << 1] += lazy[n], lazy[n << 1 | 1] += lazy[n];
    lazy[n] = 0;
}

void update(int n, int s, int e, int x, int v) {
    lazy_update(n, s, e);
    if (x < s || e < x)
        return;
    else if (s == e)
        tree[n].cur += v;
    else {
        int m = s + e >> 1;
        update(n << 1, s, m, x, v), update(n << 1 | 1, m + 1, e, x, v);
        tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
    }
}

void r_update(int n, int s, int e, int l, int r) {
    lazy_update(n, s, e);
    if (r < s || e < l)
        return;
    else if (l <= s && e <= r)
        lazy[n]++, lazy_update(n, s, e);
    else {
        int m = s + e >> 1;
        r_update(n << 1, s, m, l, r), r_update(n << 1 | 1, m + 1, e, l, r);
        tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
    }
}

Node query(int n, int s, int e, int l, int r) {
    lazy_update(n, s, e);
    if (r < s || e < l)
        return {0, 0};
    else if (l <= s && e <= r)
        return tree[n];
    else {
        int m = s + e >> 1;
        return merge(query(n << 1, s, m, l, r), query(n << 1 | 1, m + 1, e, l, r));
    }
}

vector<int> maxsum(
    vector<signed> _A, vector<signed> _B,
    vector<signed> L1, vector<signed> R1,
    vector<signed> L2, vector<signed> R2) {

    int N = _A.size(), Q = L1.size(), X, T;
    vector<int> ans(Q), comp;

    comp.push_back(0);
    for (int i = 1; i <= N; i++) {
        A[i] = _A[i - 1], B[i] = _B[i - 1];
        S[i] = S[i - 1] + B[i], comp.push_back(S[i]);
    }

    sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end()), T = comp.size();
    for (int i = 0; i <= N; i++)
        V[i] = lower_bound(comp.begin(), comp.end(), S[i]) - comp.begin() + 1;

    X = 0, M[0][0] = -INF;
    for (int i = 1; i <= N; i++) {
        CH[i][0] = X <= 0, X = A[i] + max(X, 0ll);
        M[i][0] = max(M[i - 1][0], X);
    }

    X = 0, M[N + 1][1] = -INF;
    for (int i = N; i >= 1; i--) {
        CH[i][1] = X <= 0, X = A[i] + max(X, 0ll);
        M[i][1] = max(M[i + 1][1], X);
    }

    sinit(1, 1, T);
    for (int i = N; i >= 1; i--) {
        supdate(1, 1, T, V[i], i);
        F[i][0] = min(N, squery(1, 1, T, 1, V[i - 1] - 1)[0]);
        X = lower_bound(comp.begin(), comp.end(), S[i - 1] + M[i - 1][0]) - comp.begin() + 1;
        F[i][2] = squery(1, 1, T, X, T)[0];
    }

    sinit(1, 1, T);
    for (int i = 1; i <= N; i++) {
        supdate(1, 1, T, V[i - 1], i);
        F[i][1] = max(1ll, squery(1, 1, T, V[i] + 1, T)[1]);
        X = lower_bound(comp.begin(), comp.end(), S[i] - M[i + 1][1] + 1) - comp.begin();
        F[i][3] = squery(1, 1, T, 1, X)[1];

        if (CH[i][1] && F[i][1] <= F[i][3] && F[i][3] > 0)
            arr[F[i][1]][0].push_back(i), arr[F[i][3] + 1][1].push_back(i);
    }

    for (int i = 0; i < Q; i++) {
        L1[i]++, R1[i]++, L2[i]++, R2[i]++;
        queries[L1[i] - 1].push_back({i, -1}), queries[R1[i]].push_back({i, 1});
    }

    for (int i = 1; i <= N; i++) {
        for (int j : arr[i][0])
            update(1, 1, N, j, 1);
        for (int j : arr[i][1])
            update(1, 1, N, j, -1);

        if (CH[i][0] && F[i][2] <= F[i][0])
            r_update(1, 1, N, F[i][2], F[i][0]);
        for (pr j : queries[i])
            ans[j[0]] += query(1, 1, N, L2[j[0]], R2[j[0]]).val * j[1];
    }

    return ans;
}