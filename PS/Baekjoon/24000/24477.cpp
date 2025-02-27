#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;
typedef array<int, 2> pr;

const int MAX = 300000;
const int MAX_LOG = 20;

int A[MAX], B[MAX], L[MAX][MAX_LOG], R[MAX][MAX_LOG];
pr tree[MAX_LOG][MAX * 4];

vector<int> mn[MAX], mx[MAX];

pr merge(pr X, pr Y) { return {min(X[0], Y[0]), max(X[1], Y[1])}; };

void init(int idx, int n, int s, int e) {
    if (s == e)
        tree[idx][n] = {L[s][idx], R[s][idx]};
    else {
        int m = s + e >> 1;
        init(idx, n << 1, s, m), init(idx, n << 1 | 1, m + 1, e);
        tree[idx][n] = merge(tree[idx][n << 1], tree[idx][n << 1 | 1]);
    }
}

pr query(int idx, int n, int s, int e, int l, int r) {
    if (r < s || e < l)
        return {MAX, 0};
    else if (l <= s && e <= r)
        return tree[idx][n];
    else {
        int m = s + e >> 1;
        return merge(query(idx, n << 1, s, m, l, r), query(idx, n << 1 | 1, m + 1, e, l, r));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, M, Q, S, T, X, Y, ans = 0, st, en, md;
    pr V;

    cin >> N >> K >> M;

    for (int i = 1; i <= M; i++) {
        cin >> A[i] >> B[i];
        if (A[i] <= B[i]) {
            X = min(B[i] - 1, A[i] + K - 1);
            mx[A[i]].push_back(B[i]), mx[X + 1].push_back(-B[i]);
        } else {
            X = max(B[i] + 1, A[i] - K + 1);
            mn[X].push_back(B[i]), mn[A[i] + 1].push_back(-B[i]);
        }
    }

    multiset<int> mx_st, mn_st;

    for (int i = 1; i <= N; i++) {
        for (int j : mx[i]) {
            if (j > 0)
                mx_st.insert(j);
            else
                mx_st.erase(mx_st.find(-j));
        }
        for (int j : mn[i]) {
            if (j > 0)
                mn_st.insert(j);
            else
                mn_st.erase(mn_st.find(-j));
        }

        L[i][0] = mn_st.empty() ? i : *mn_st.begin();
        R[i][0] = mx_st.empty() ? i : *mx_st.rbegin();
    }
    init(0, 1, 1, N);

    for (int i = 1; i < MAX_LOG; i++) {
        for (int j = 1; j <= N; j++) {
            V = query(i - 1, 1, 1, N, L[j][i - 1], R[j][i - 1]);
            L[j][i] = V[0], R[j][i] = V[1];
        }
        init(i, 1, 1, N);
    }

    cin >> Q;
    while (Q--) {
        cin >> S >> T;

        st = 1, en = M, ans = -1;
        while (st <= en) {
            md = st + en >> 1;
            X = S, Y = S;

            for (int i = MAX_LOG - 1; i >= 0; i--) {
                if (!(md & (1ll << i)))
                    continue;
                V = query(i, 1, 1, N, X, Y);
                X = V[0], Y = V[1];
            }

            if (X <= T && T <= Y)
                ans = md, en = md - 1;
            else
                st = md + 1;
        }

        cout << ans << '\n';
    }

    return 0;
}