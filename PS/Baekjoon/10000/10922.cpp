#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
#define int long long

using namespace std;

typedef array<int, 2> pr;

const int MAX = 500001;
const int MOD = 1000000007;

int A[MAX], B[MAX], tree[MAX * 4], mx_tree[MAX * 4], N;
set<pr> st;

void init(int n, int s, int e) {
    if (s == e)
        tree[n] = A[s];
    else {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
        tree[n] = tree[n << 1] * tree[n << 1 | 1] % MOD;
    }
}

void update(int n, int s, int e, int x) {
    if (x < s || e < x)
        return;
    else if (s == e)
        tree[n] = A[s];
    else {
        int m = s + e >> 1;
        update(n << 1, s, m, x), update(n << 1 | 1, m + 1, e, x);
        tree[n] = tree[n << 1] * tree[n << 1 | 1] % MOD;
    }
}

int query(int n, int s, int e, int l, int r) {
    if (r < s || e < l)
        return 1;
    else if (l <= s && e <= r)
        return tree[n];
    else {
        int m = s + e >> 1;
        return query(n << 1, s, m, l, r) * query(n << 1 | 1, m + 1, e, l, r) % MOD;
    }
}

int mx(int x, int y) { return B[x] > B[y] ? x : y; }

void minit(int n, int s, int e) {
    if (s == e)
        mx_tree[n] = s;
    else {
        int m = s + e >> 1;
        minit(n << 1, s, m), minit(n << 1 | 1, m + 1, e);
        mx_tree[n] = mx(mx_tree[n << 1], mx_tree[n << 1 | 1]);
    }
}

void mupdate(int n, int s, int e, int x) {
    if (x < s || e < x)
        return;
    else if (s ^ e) {
        int m = s + e >> 1;
        mupdate(n << 1, s, m, x), mupdate(n << 1 | 1, m + 1, e, x);
        mx_tree[n] = mx(mx_tree[n << 1], mx_tree[n << 1 | 1]);
    }
}

int mquery(int n, int s, int e, int l, int r) {
    if (r < s || e < l)
        return 0;
    else if (l <= s && e <= r)
        return mx_tree[n];
    else {
        int m = s + e >> 1;
        return mx(
            mquery(n << 1, s, m, l, r),
            mquery(n << 1 | 1, m + 1, e, l, r));
    }
}

void query() {
    int ans = N, M = A[N] * B[N], X, Y;
    pr K;

    for (int i = N - 1; i >= 1 && M < MOD;) {
        X = i;
        if (A[i] == 1) {
            K = *prev(st.lower_bound({i + 1, N + 1})), X = K[0];
            Y = mquery(1, 1, N, X, i);
        } else
            Y = i;

        if (B[Y] >= M)
            ans = Y, M = B[Y];
        M = M * A[i], i = X - 1;
    }
    cout << query(1, 1, N, 1, ans) * B[ans] % MOD << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int Q, T, X, Y;
    pr K;
    set<pr>::iterator iter;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        if (A[i] == 1) {
            if (!st.empty() && (*st.rbegin())[1] == i - 1) {
                K = *st.rbegin(), st.erase(prev(st.end()));
                st.insert({K[0], i});
            } else
                st.insert({i, i});
        }
    }
    for (int i = 1; i <= N; i++)
        cin >> B[i];

    init(1, 1, N), minit(1, 1, N);
    query();

    cin >> Q;
    while (Q--) {
        cin >> T >> X >> Y, X++;
        if (T == 1) {
            if (A[X] == 1) {
                iter = prev(st.lower_bound({X, N + 1})), K = *iter, st.erase(iter);
                if (K[0] < X)
                    st.insert({K[0], X - 1});
                if (K[1] > X)
                    st.insert({X + 1, K[1]});
            }
            A[X] = Y, update(1, 1, N, X);
            if (A[X] == 1) {
                iter = st.lower_bound({X, N + 1}), K = pr{X, X};
                if (iter != st.end() && (*iter)[0] == X + 1)
                    K[1] = (*iter)[1], st.erase(iter);
                iter = st.lower_bound({X, N + 1});
                if (iter != st.begin() && (*prev(iter))[1] == X - 1)
                    K[0] = (*prev(iter))[0], st.erase(prev(iter));
                st.insert(K);
            }
        } else
            B[X] = Y, mupdate(1, 1, N, X);
        query();
    }

    return 0;
}