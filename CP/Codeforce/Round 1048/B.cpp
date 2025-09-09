#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 500001;

int A[MAX], L[MAX], R[MAX], QL[MAX], QR[MAX], ans[MAX], tree[MAX * 4];
vector<int> queries[MAX], arr[MAX];

void init(int n, int s, int e) {
    if (s == e)
        tree[n] = 0;
    else {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
        tree[n] = tree[n << 1] + tree[n << 1 | 1];
    }
}

int query(int n, int s, int e, int l, int r) {
    if (r < s || e < l)
        return 0;
    else if (l <= s && e <= r)
        return tree[n];
    else {
        int m = s + e >> 1;
        return query(n << 1, s, m, l, r) + query(n << 1 | 1, m + 1, e, l, r);
    }
}

void update(int n, int s, int e, int x, int v) {
    if (x < s || e < x)
        return;
    else if (s == e)
        tree[n] += v;
    else {
        int m = s + e >> 1;
        update(n << 1, s, m, x, v), update(n << 1 | 1, m + 1, e, x, v);
        tree[n] = tree[n << 1] + tree[n << 1 | 1];
    }
}

void solve() {
    int N, Q;

    cin >> N >> Q, init(1, 1, N);
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    vector<int> st;
    for (int i = 1; i <= N; i++) {
        while (!st.empty() && A[st.back()] <= A[i])
            st.pop_back();
        L[i] = (st.empty() ? 0 : st.back()), st.push_back(i);
    }

    st.clear();
    for (int i = N; i >= 1; i--) {
        while (!st.empty() && A[st.back()] >= A[i])
            st.pop_back();
        R[i] = (st.empty() ? N + 1 : st.back()), st.push_back(i);
    }

    for (int i = 1; i <= N; i++) {
        if (L[i] == 0 || R[i] == N + 1)
            continue;
        arr[R[i]].push_back(i);
    }

    for (int i = 1; i <= Q; i++) {
        cin >> QL[i] >> QR[i], ans[i] = true;
        queries[QR[i]].push_back(i);
    }

    for (int i = 1; i <= N; i++) {
        for (int j : arr[i])
            update(1, 1, N, L[j], 1);
        for (int j : queries[i])
            ans[j] &= query(1, 1, N, QL[j], i) == 0;
    }

    for (int i = 1; i <= Q; i++)
        cout << (ans[i] ? "YES" : "NO") << '\n';

    for (int i = 1; i <= N; i++)
        queries[i].clear(), arr[i].clear();
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