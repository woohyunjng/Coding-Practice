#include <bits/stdc++.h>
using namespace std;

typedef array<int, 3> tp;

const int MAX = 500001;

int N, Q, fenwick[2][MAX];
vector<int> queries[MAX];
map<int, int> V;

void update(int t, int n, int v) {
    for (n++; n <= N; n += n & (-n))
        fenwick[t][n] += v;
}
int query(int t, int x) {
    int res = 0;
    for (x++; x > 0; x -= x & (-x))
        res += fenwick[t][x];
    return res;
}
int query(int t, int l, int r) { return query(t, r) - query(t, l - 1); }

vector<int> array_operation(vector<int> A, vector<int> B, vector<int> L, vector<int> R) {
    N = A.size(), Q = L.size();
    for (int i = 0; i < Q; i++)
        queries[R[i]].push_back(i);

    set<tp> st;
    set<tp>::iterator iter;
    tp K;

    vector<int> ans(Q, 0);

    for (int i = 0; i < N; i++) {
        if (V.find(B[i]) != V.end())
            update(0, V[B[i]], -1);
        V[B[i]] = i, update(0, V[B[i]], 1);

        iter = st.lower_bound({A[i], 0, 0});
        if (iter != st.begin() && (*prev(iter))[1] >= A[i]) {
            K = *prev(iter), st.erase(prev(iter)), st.insert({K[0], A[i] - 1, K[2]});
            if (K[1] > B[i])
                st.insert({B[i] + 1, K[1], K[2]}), update(1, K[2], -(B[i] - A[i] + 1));
            else
                update(1, K[2], -(K[1] - A[i] + 1));
        }
        iter = st.lower_bound({B[i] + 1, 0, 0});
        if (iter != st.begin() && (*prev(iter))[0] <= B[i] && (*prev(iter))[1] > B[i]) {
            K = *prev(iter), st.erase(prev(iter)), st.insert({B[i] + 1, K[1], K[2]});
            update(1, K[2], -(B[i] - K[0] + 1));
        }
        while (true) {
            iter = st.lower_bound({A[i], 0, 0});
            if (iter == st.end() || (*iter)[0] > B[i])
                break;
            K = *iter, st.erase(iter), update(1, K[2], -(K[1] - K[0] + 1));
        }
        st.insert({A[i], B[i], i}), update(1, i, B[i] - A[i] + 1);

        for (int j : queries[i])
            ans[j] = query(0, L[j], R[j]) == query(1, L[j], R[j]);
    }

    return ans;
}