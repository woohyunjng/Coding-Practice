#include <bits/stdc++.h>
using namespace std;

typedef array<int, 2> pr;
typedef array<int, 3> tp;

const int MAX = 2400'001;
const int MAX_LOG = 20;

int A[MAX], nxt[MAX][MAX_LOG], MX[MAX], tree[MAX * 4];
vector<int> pos[MAX], D[MAX], B[MAX];
set<pr> val[MAX];

void update(int n, int s, int e, int x, int v) {
    if (x < s || e < x)
        return;
    else if (s == e)
        tree[n] = max(tree[n], v);
    else {
        int m = s + e >> 1;
        update(n << 1, s, m, x, v), update(n << 1 | 1, m + 1, e, x, v);
        tree[n] = max(tree[n << 1], tree[n << 1 | 1]);
    }
}

int query(int n, int s, int e, int l, int r) {
    if (r < s || e < l)
        return 0;
    else if (l <= s && e <= r)
        return tree[n];
    else {
        int m = s + e >> 1;
        return max(query(n << 1, s, m, l, r), query(n << 1 | 1, m + 1, e, l, r));
    }
}

vector<int> solve(int N, vector<int> &A, int Q, vector<pair<int, int>> &queries) {
    int L, R, V = -1, X, S = 0, ans;
    vector<int> ans_res;

    set<pr> st;
    set<pr>::iterator it;
    set<int> mex_st;

    vector<tp> arr;

    for (int i = 1; i <= N + 1; i++)
        mex_st.insert(i);
    for (int i = 0; i < N; i++) {
        if (mex_st.find(A[i]) != mex_st.end())
            mex_st.erase(A[i]);
        X = *mex_st.begin();
        if (V != X && V != -1)
            st.insert({V, i - 1});
        V = X;

        pos[A[i]].push_back(i), S = max(S, A[i]);
        arr.push_back({i, i, A[i] == 1 ? 2 : 1});
    }
    st.insert({V, N - 1});

    for (int i = 1; i <= S; i++)
        pos[i].push_back(N), reverse(pos[i].begin(), pos[i].end());

    for (int i = 0; i < N; i++) {
        it = st.lower_bound({A[i], -1}), pos[A[i]].pop_back(), X = pos[A[i]].back();
        if (X == i + 1)
            continue;

        if (it != st.begin() && it != st.end())
            arr.push_back({i, (*prev(it))[1] + 1, (*it)[0]});
        if (!st.empty() && (*st.begin())[1] == i) {
            it = st.erase(st.begin());
            if (it != st.end())
                arr.push_back({i, i + 1, (*it)[0]});
        }
        it = st.lower_bound({A[i], -1});
        while (it != st.end() && (*it)[1] < X) {
            R = (*it)[1], it = st.erase(it);
            if (it != st.end())
                arr.push_back({i, R + 1, (*it)[0]});
        }

        it = st.lower_bound({A[i], -1});
        if (it == st.begin() || (*prev(it))[1] < X - 1)
            st.insert({A[i], X - 1});
    }

    sort(arr.begin(), arr.end());
    for (int i = (int)arr.size() - 1; i >= 0; i--) {
        X = arr[i][2], L = arr[i][0], R = arr[i][1];
        val[X].insert({L, i + 1}), it = val[X].lower_bound({R + 1, -1});
        if (it != val[X].end())
            nxt[i + 1][0] = (*it)[1];
        for (int j = 1; j < MAX_LOG; j++)
            nxt[i + 1][j] = nxt[nxt[i + 1][j - 1]][j - 1];
        D[R].push_back(i);
    }

    for (int i = 0; i < Q; i++)
        B[queries[i].second].push_back(i);

    for (int i = 0; i < N; i++) {
        for (int j : D[i])
            update(1, 0, N - 1, arr[j][0], arr[j][2]);
        for (int j : B[i])
            MX[j] = query(1, 0, N - 1, queries[j].first, queries[j].second);
    }

    for (int i = 0; i < Q; i++) {
        L = queries[i].first, R = queries[i].second, ans = 1;
        L = (*val[MX[i]].lower_bound({L, -1}))[1];
        for (int j = MAX_LOG - 1; j >= 0; j--)
            if (nxt[L][j] != 0 && arr[nxt[L][j] - 1][1] <= R)
                ans += (1 << j), L = nxt[L][j];
        ans_res.push_back(ans);
    }

    return ans_res;
}