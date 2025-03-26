#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;
typedef array<int, 3> tp;

const int MAX = 500010;

int A[MAX], V[MAX], ans[MAX];
tp tree[MAX * 4];

vector<pr> arr[MAX];
vector<int> val[MAX];

tp merge(tp X, tp Y) { return {max(X[0], Y[0]), max(X[1], Y[1]), max({X[2], Y[2], X[1] + Y[0]})}; } // (A의 max값, V의 max값, 합의 최대)

void init(int n, int s, int e) {
    if (s == e)
        tree[n] = {A[s], 0, A[s]};
    else {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
        tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
    }
}

void update(int n, int s, int e, int x, int v) {
    if (x < s || e < x)
        return;
    else if (s == e)
        tree[n][1] = max(tree[n][1], v), tree[n][2] = tree[n][0] + tree[n][1];
    else {
        int m = s + e >> 1;
        update(n << 1, s, m, x, v), update(n << 1 | 1, m + 1, e, x, v);
        tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
    }
}

tp query(int n, int s, int e, int l, int r) {
    if (r < s || e < l)
        return {0, 0, 0};
    else if (l <= s && e <= r)
        return tree[n];
    else {
        int m = s + e >> 1;
        return merge(
            query(n << 1, s, m, l, r),
            query(n << 1 | 1, m + 1, e, l, r));
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, L, R;
    vector<int> st;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    init(1, 1, N);

    cin >> Q;
    for (int i = 1; i <= Q; i++)
        cin >> L >> R, arr[L].push_back({R, i});

    for (int i = 1; i <= N; i++) {
        while (!st.empty() && A[st.back()] <= A[i])
            val[st.back()].push_back(i), st.pop_back();
        if (!st.empty())
            val[st.back()].push_back(i);
        st.push_back(i);
    }

    for (int i = N - 2; i >= 1; i--) {
        for (int j : val[i])
            update(1, 1, N, j * 2 - i, A[i] + A[j]);
        for (pr j : arr[i])
            ans[j[1]] = query(1, 1, N, i + 2, j[0])[2];
    }

    for (int i = 1; i <= Q; i++)
        cout << ans[i] << '\n';
}