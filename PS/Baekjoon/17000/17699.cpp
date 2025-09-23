#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 500002;

int L[MAX], R[MAX], C[MAX], K[MAX], V[MAX][2], tree[MAX * 4][2];
vector<int> arr[MAX], val[MAX];

void init(int t, int n, int s, int e) {
    if (s == e)
        tree[n][t] = V[s][t];
    else {
        int m = s + e >> 1;
        init(t, n << 1, s, m), init(t, n << 1 | 1, m + 1, e);
        if (t == 0)
            tree[n][t] = min(tree[n << 1][t], tree[n << 1 | 1][t]);
        else
            tree[n][t] = max(tree[n << 1][t], tree[n << 1 | 1][t]);
    }
}

int query(int t, int n, int s, int e, int l, int r) {
    if (r < s || e < l)
        return t == 0 ? MAX + 1 : 0;
    else if (l <= s && e <= r)
        return tree[n][t];
    else {
        int m = s + e >> 1;
        if (t == 0)
            return min(query(t, n << 1, s, m, l, r), query(t, n << 1 | 1, m + 1, e, l, r));
        else
            return max(query(t, n << 1, s, m, l, r), query(t, n << 1 | 1, m + 1, e, l, r));
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, X, Y;
    bool ans;

    set<int> st;
    set<int>::iterator it;

    cin >> N;
    for (int i = 1; i < N; i++)
        cin >> C[i];

    for (int i = 1; i <= N; i++) {
        cin >> X;
        while (X--)
            cin >> Y, arr[i].push_back(Y);
    }

    for (int i = 1; i < N; i++) {
        for (int j : arr[i])
            K[j] = i;
        L[i] = K[C[i]];
    }

    fill(K + 1, K + N + 1, N + 1);
    for (int i = N; i > 1; i--) {
        for (int j : arr[i])
            K[j] = i;
        R[i - 1] = K[C[i - 1]];
    }

    for (int i = 1; i <= N; i++)
        val[R[i]].push_back(i), st.insert(i);
    st.insert(0);

    for (int i = 1; i <= N; i++) {
        for (int j : val[i])
            st.erase(st.find(j));
        val[i].clear();
        it = st.lower_bound(L[i]);
        V[i][0] = it == st.end() || *it >= i ? N : *it, V[i][0]++;
    }
    val[N].clear(), val[N + 1].clear(), st.clear();

    for (int i = 1; i < N; i++)
        val[L[i]].push_back(i), st.insert(i);
    st.insert(N);

    for (int i = N - 1; i >= 1; i--) {
        for (int j : val[i + 1])
            st.erase(st.find(j));
        it = st.lower_bound(R[i]);
        V[i + 1][1] = it == st.begin() || *prev(it) < i + 1 ? 0 : *prev(it);
    }

    init(0, 1, 1, N - 1), init(1, 1, 2, N);

    cin >> Q;
    while (Q--) {
        cin >> X >> Y;
        if (X < Y)
            ans = query(0, 1, 1, N - 1, X, Y - 1) > X;
        else
            ans = query(1, 1, 2, N, Y + 1, X) < X;
        cout << (ans ? "YES" : "NO") << '\n';
    }

    return 0;
}