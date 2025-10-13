#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define int long long

using namespace std;

typedef array<int, 2> pr;

const int MAX = 400001;

int A[MAX], dp[MAX], tree[MAX * 4];

void init(int n, int s, int e) {
    if (s == e)
        tree[n] = MAX;
    else {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
        tree[n] = min(tree[n << 1], tree[n << 1 | 1]);
    }
}

void update(int n, int s, int e, int x, int v) {
    if (x < s || e < x)
        return;
    else if (s == e)
        tree[n] = v;
    else {
        int m = s + e >> 1;
        update(n << 1, s, m, x, v), update(n << 1 | 1, m + 1, e, x, v);
        tree[n] = min(tree[n << 1], tree[n << 1 | 1]);
    }
}

int query(int n, int s, int e, int l, int r) {
    if (r < s || e < l)
        return MAX;
    else if (l <= s && e <= r)
        return tree[n];
    else {
        int m = s + e >> 1;
        return min(query(n << 1, s, m, l, r), query(n << 1 | 1, m + 1, e, l, r));
    }
}

void solve() {
    int N, X, ans;
    vector<pr> st;

    cin >> N, ans = N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    init(1, 0, N), update(1, 0, N, 0, 0);

    st.push_back({0, 0});
    for (int i = 1; i <= N; i++) {
        while (!st.empty() && st.back()[0] > A[i])
            st.pop_back();
        st.push_back({A[i], i});

        dp[i] = MAX;
        for (int j = 1; j <= 20; j++) {
            X = lower_bound(st.begin(), st.end(), (pr){(A[i] + j - 1) / j, 0}) - st.begin();
            dp[i] = min(dp[i], query(1, 0, N, st[X - 1][1], i - 1) + j);
        }

        update(1, 0, N, i, dp[i]);
    }

    cout << dp[N] << '\n';
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