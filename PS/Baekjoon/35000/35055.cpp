#include <bits/stdc++.h>
using namespace std;

typedef array<int, 3> tp;

const int MAX = 400001;

int N, A[MAX], L[MAX], R[MAX], K[MAX], ans[MAX],
    tree[MAX * 4];
vector<int> arr[MAX], queries[MAX];

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
        tree[n] = v == -1 ? MAX : min(tree[n], v);
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

void dnc(int l, int r) {
    if (l > r)
        return;

    vector<tp> val;

    int m = l + r >> 1;
    for (int i = l; i <= m; i++)
        for (int j : arr[i])
            val.push_back({A[i] + A[j], j, i - j}); // L, V, v
    for (int i = m; i <= r; i++)
        for (int j : queries[i])
            val.push_back({K[j], L[j], -j});

    sort(val.begin(), val.end(), [&](tp x, tp y) {
        if (x[0] == y[0])
            return x[1] == y[1] ? x[2] > y[2] : x[1] > y[1];
        return x[0] > y[0];
    });

    for (tp i : val) {
        if (i[2] >= 0)
            update(1, 1, N, i[1], i[2]);
        else
            ans[-i[2]] = min(ans[-i[2]], query(1, 1, N, i[1], N));
    }

    for (tp i : val) {
        if (i[2] >= 0)
            update(1, 1, N, i[1], -1);
    }

    if (l != r)
        dnc(l, m), dnc(m + 1, r);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int Q;
    vector<int> st;

    cin >> N >> Q, init(1, 1, N);
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    for (int i = 1; i <= N; i++) {
        while (!st.empty() && A[st.back()] < A[i])
            st.pop_back();
        if (!st.empty())
            arr[i].push_back(st.back());
        st.push_back(i);
    }

    st.clear();
    for (int i = N; i >= 1; i--) {
        while (!st.empty() && A[st.back()] <= A[i])
            st.pop_back();
        if (!st.empty())
            arr[st.back()].push_back(i);
        st.push_back(i);
    }

    for (int i = 1; i <= Q; i++) {
        cin >> L[i] >> R[i] >> K[i];
        queries[R[i]].push_back(i), ans[i] = MAX;
    }

    dnc(1, N);

    for (int i = 1; i <= Q; i++)
        cout << (ans[i] == MAX ? -1 : ans[i]) << '\n';

    return 0;
}