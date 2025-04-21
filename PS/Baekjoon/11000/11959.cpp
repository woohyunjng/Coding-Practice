#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 500001;

int N, Q, A[MAX], ans[MAX], L[MAX], R[MAX], X[MAX], Y[MAX], tree[3][MAX * 4], lazy[MAX * 4];
vector<int> queries[MAX], er[MAX];

void init(int n, int s, int e) {
    tree[0][n] = lazy[n] = 0;
    tree[2][n] = s - 1;
    if (s ^ e) {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
    }
}

void lazy_update(int n, int s, int e) {
    if (!lazy[n])
        return;
    tree[0][n] = max(tree[0][n], lazy[n] - tree[2][n]);
    if (s ^ e)
        lazy[n << 1] = max(lazy[n << 1], lazy[n]), lazy[n << 1 | 1] = max(lazy[n << 1 | 1], lazy[n]);
    lazy[n] = 0;
}

void update(int n, int s, int e, int l, int r, int v) {
    lazy_update(n, s, e);
    if (s > r || e < l)
        return;
    if (s >= l && e <= r)
        lazy[n] = v, lazy_update(n, s, e);
    else {
        int m = s + e >> 1;
        update(n << 1, s, m, l, r, v), update(n << 1 | 1, m + 1, e, l, r, v);
        tree[0][n] = max(tree[0][n << 1], tree[0][n << 1 | 1]);
    }
}

void update_p(int n, int s, int e, int x) {
    if (x < s || e < x)
        return;
    else if (s == e)
        tree[2][n] = MAX;
    else {
        int m = s + e >> 1;
        update_p(n << 1, s, m, x), update_p(n << 1 | 1, m + 1, e, x);
        tree[2][n] = min(tree[2][n << 1], tree[2][n << 1 | 1]);
    }
}

int query(int n, int s, int e, int l, int r) {
    lazy_update(n, s, e);
    if (r < s || e < l)
        return 0;
    else if (l <= s && e <= r)
        return tree[0][n];
    else {
        int m = s + e >> 1;
        return max(query(n << 1, s, m, l, r), query(n << 1 | 1, m + 1, e, l, r));
    }
}

void init_v(int n, int s, int e) {
    tree[1][n] = 0;
    if (s ^ e) {
        int m = s + e >> 1;
        init_v(n << 1, s, m), init_v(n << 1 | 1, m + 1, e);
    }
}

void update_v(int n, int s, int e, int x, int v) {
    if (x < s || e < x)
        return;
    else if (s == e)
        tree[1][n] = max(tree[1][n], v);
    else {
        int m = s + e >> 1;
        update_v(n << 1, s, m, x, v), update_v(n << 1 | 1, m + 1, e, x, v);
        tree[1][n] = max(tree[1][n << 1], tree[1][n << 1 | 1]);
    }
}

int query_v(int n, int s, int e, int l, int r) {
    if (r < s || e < l)
        return 0;
    else if (l <= s && e <= r)
        return tree[1][n];
    else {
        int m = s + e >> 1;
        return max(query_v(n << 1, s, m, l, r), query_v(n << 1 | 1, m + 1, e, l, r));
    }
}

void solve() {
    for (int i = 1; i <= N; i++)
        queries[i].clear(), er[i].clear();
    for (int i = 1; i <= Q; i++)
        queries[R[i]].push_back(i);

    vector<int> st;
    for (int i = 1; i <= N; i++) {
        while (!st.empty() && A[st.back()] > A[i])
            X[st.back()] = i - 1, st.pop_back();
        st.push_back(i);
    }
    while (!st.empty())
        X[st.back()] = N, st.pop_back();

    for (int i = 1; i <= N; i++)
        if (X[i] < N)
            er[X[i] + 1].push_back(i);

    for (int i = N; i >= 1; i--) {
        while (!st.empty() && A[st.back()] < A[i])
            Y[st.back()] = i + 1, st.pop_back();
        st.push_back(i);
    }
    while (!st.empty())
        Y[st.back()] = 1, st.pop_back();

    init(1, 1, N), init_v(1, 1, N);

    for (int i = 1; i <= N; i++) {
        for (int j : er[i]) {
            update_v(1, 1, N, j, query(1, 1, N, j, j));
            update_p(1, 1, N, j);
        }

        update(1, 1, N, Y[i], i, i);
        for (int j : queries[i]) {
            ans[j] = max(ans[j], query(1, 1, N, L[j], R[j]));
            ans[j] = max(ans[j], query_v(1, 1, N, L[j], R[j]));
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    cin >> Q;
    for (int i = 1; i <= Q; i++)
        cin >> L[i] >> R[i], queries[L[i]].push_back(i);

    solve();
    reverse(A + 1, A + N + 1);
    for (int i = 1; i <= Q; i++) {
        L[i] = N - L[i] + 1, R[i] = N - R[i] + 1;
        swap(L[i], R[i]);
    }
    solve();

    for (int i = 1; i <= Q; i++)
        cout << ans[i] << '\n';

    return 0;
}