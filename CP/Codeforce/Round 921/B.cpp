#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;
typedef array<int, 3> tp;

const int MAX = 300001;

int N, tree[MAX * 4], X[MAX];
set<pr> val;
set<tp> st;

int sum(int K) { return K * (K + 1) / 2; }

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
        tree[n] = v;
    else {
        int m = s + e >> 1;
        update(n << 1, s, m, x, v), update(n << 1 | 1, m + 1, e, x, v);
        tree[n] = tree[n << 1] + tree[n << 1 | 1];
    }
}

void add(int P, int K) {
    set<tp>::iterator it = prev(st.lower_bound({P + 1, -1, -1}));
    tp V = *it;
    st.erase(it), update(1, 1, N, V[1], 0);

    if (V[0] <= P - 1)
        st.insert({V[0], P - 1, V[2]}), update(1, 1, N, P - 1, V[2] * sum(P - V[0]));
    if (P + 1 <= V[1])
        st.insert({P + 1, V[1], K}), update(1, 1, N, V[1], K * sum(V[1] - P));
}

int calc(int K) {
    int ans = query(1, 1, N, 1, K);
    set<tp>::iterator it = st.lower_bound({K + 1, -1, -1});
    tp V;

    if (it == st.begin())
        return ans;
    it = prev(it), V = *it;
    if (V[1] > K)
        ans += V[2] * (sum(V[1] - V[0] + 1) - sum(V[1] - K));
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int M, Q, T, L, R;

    cin >> N >> M >> Q;

    st.insert({1, N});

    for (int i = 1; i <= M; i++)
        cin >> X[i];
    for (int i = 1; i <= M; i++)
        cin >> R, add(X[i], R);

    while (Q--) {
        cin >> T >> L >> R;
        if (T == 1)
            add(L, R);
        else
            cout << calc(R) - calc(L - 1) << '\n';
    }

    return 0;
}