#include "overtaking.h"

#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;
typedef array<int, 4> tp;

const int MAX = 1000;
const int INF = 1'000'000'000'000'000'000;

int L, N, X, M, T[MAX], W[MAX], S[MAX],
    dp[MAX][MAX], ans[MAX][MAX],
    K[MAX], V[MAX][MAX],
    tree[MAX][MAX * 4];

vector<int> comp[MAX];
set<pr> st;

int F(int X) {
    set<pr>::iterator iter = prev(st.lower_bound({X + 1, 0}));
    return (*iter)[1] == 0 ? X : (*iter)[1];
}

void update(int t, int n, int s, int e, int x, int v) {
    if (x < s || e < x)
        return;
    else if (s == e)
        tree[t][n] = max(tree[t][n], v);
    else {
        int m = s + e >> 1;
        update(t, n << 1, s, m, x, v), update(t, n << 1 | 1, m + 1, e, x, v);
        tree[t][n] = max(tree[t][n << 1], tree[t][n << 1 | 1]);
    }
}

int query(int t, int n, int s, int e, int l, int r) {
    if (r < s || e < l)
        return 0;
    else if (l <= s && e <= r)
        return tree[t][n];
    else {
        int m = s + e >> 1;
        return max(
            query(t, n << 1, s, m, l, r),
            query(t, n << 1 | 1, m + 1, e, l, r));
    }
}

void init(signed _L, signed _N, vector<int> _T, vector<signed> _W, signed _X, signed _M, vector<signed> _S) {
    L = _L, X = _X, M = _M;
    vector<pr> arr;
    vector<int> lst;

    for (int i = 0; i < _N; i++) {
        if (_W[i] <= X)
            continue;
        arr.push_back({_W[i] - X, _T[i]});
    }

    sort(arr.rbegin(), arr.rend()), N = arr.size();
    for (int i = 0; i < N; i++)
        W[i] = arr[i][0], T[i] = arr[i][1], lst.push_back(i);
    for (int i = 0; i < M; i++)
        S[i] = _S[i];
    arr.clear();

    for (int i = 0; i < N; i++)
        dp[i][0] = T[i];

    for (int i = 0; i + 1 < M; i++) {
        for (int j = 0; j < N; j++)
            comp[i].push_back(dp[j][i]);
        sort(comp[i].begin(), comp[i].end()), comp[i].erase(unique(comp[i].begin(), comp[i].end()), comp[i].end()), K[i] = comp[i].size();
        for (int j = 0; j < N; j++)
            V[j][i] = lower_bound(comp[i].begin(), comp[i].end(), dp[j][i]) - comp[i].begin();

        for (int j = 0; j < N; j++) {
            dp[j][i + 1] = (S[i + 1] - S[i]) * W[j] + dp[j][i];
            dp[j][i + 1] = max(dp[j][i + 1], query(i, 1, 0, K[i] - 1, 0, V[j][i] - 1));
            update(i, 1, 0, K[i] - 1, V[j][i], dp[j][i + 1]);
        }
    }

    set<pr>::iterator iter;
    st.insert({0, 0});

    int P;

    for (int i = M - 2; i >= 0; i--) {
        sort(lst.begin(), lst.end(), [&](int x, int y) { return dp[x][i + 1] < dp[y][i + 1]; });
        for (int j : lst) {
            iter = st.lower_bound({dp[j][i] + 1, 0}), V[j][i + 1] = F(dp[j][i + 1]);

            if (iter != st.begin() && (*prev(iter))[1] >= V[j][i + 1])
                continue;
            while (iter != st.end()) {
                if ((*iter)[1] > V[j][i + 1])
                    break;
                if ((*iter)[1] == 0) {
                    if ((*iter)[0] >= dp[j][i + 1])
                        break;
                    iter = st.erase(iter);
                    if (iter == st.end() || (*iter)[0] > dp[j][i + 1]) {
                        st.insert({dp[j][i + 1] + 1, 0});
                        break;
                    }
                } else
                    iter = st.erase(iter);
            }
            iter = st.insert({dp[j][i] + 1, V[j][i + 1]}).first;
            if (next(iter) == st.end())
                st.insert({dp[j][i + 1] + 1, 0});
        }
    }

    return;
}

int arrival_time(int Y) { return F(Y) + X * S[M - 1]; }