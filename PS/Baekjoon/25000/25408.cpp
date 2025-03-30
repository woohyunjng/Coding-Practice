#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 3> tp;

const int MAX = 200002;
const int MAX_Q = 1000001;

int A[MAX], ans[MAX_Q], P[MAX_Q], V[MAX], tree[MAX * 4];
vector<int> queries[MAX];

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

int sm(int n, int s, int e, int l, int r) {
    if (r < s || e < l)
        return 0;
    else if (l <= s && e <= r)
        return tree[n];
    else {
        int m = s + e >> 1;
        return sm(n << 1, s, m, l, r) + sm(n << 1 | 1, m + 1, e, l, r);
    }
}

int query(int n, int s, int e, int x) {
    if (s == e)
        return s;
    else {
        int m = s + e >> 1;
        if (x <= tree[n << 1])
            return query(n << 1, s, m, x);
        else
            return query(n << 1 | 1, m + 1, e, x - tree[n << 1]);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, X, Y;
    vector<int> arr;

    cin >> N >> Q;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    A[N + 1] = V[N + 1] = N + 1, arr.push_back(N + 1);
    for (int i = N; i >= 1; i--) {
        while (!arr.empty() && A[arr.back()] < A[i])
            arr.pop_back();
        V[i] = arr.back(), arr.push_back(i);
    }

    set<tp> st;
    set<tp>::iterator iter;
    tp K;

    for (int i = 1; i <= N; i++) {
        update(1, 1, N, A[i], V[i] - i);
        st.insert({A[i], i, V[i] - 1}), i = V[i] - 1;
    }

    for (int i = 1; i <= Q; i++) {
        cin >> X >> P[i], X = min(X, N);
        queries[X].push_back(i);
        if (X == 0)
            ans[i] = A[P[i]];
    }

    for (int i = 1; i <= N; i++) {
        X = query(1, 1, N, N / 2 + 1), Y = N / 2 - sm(1, 1, N, 1, X - 1);
        if (Y > 0) {
            iter = st.lower_bound({X, 0, 0}), K = *iter, st.erase(iter);
            st.insert({K[0], K[1], K[1] + Y - 1});
            update(1, 1, N, K[0], -(K[2] - K[1] - Y + 1));
            for (int j = K[1] + Y; j <= K[2]; j++) {
                update(1, 1, N, A[j], min(K[2] + 1, V[j]) - j);
                st.insert({A[j], j, min(K[2], V[j] - 1)}), j = V[j] - 1;
            }
        }

        for (int j : queries[i]) {
            X = query(1, 1, N, P[j]), Y = P[j] - sm(1, 1, N, 1, X - 1);
            K = *st.lower_bound({X, 0, 0}), ans[j] = A[K[1] + Y - 1];
        }
    }

    for (int i = 1; i <= Q; i++)
        cout << ans[i] << '\n';

    return 0;
}