#include <bits/stdc++.h>

#define MAX 2000000

using namespace std;
typedef array<int, 3> tp;

int N, SX, SY, parent[MAX], tree[MAX * 4], lazy[MAX * 4];
vector<tp> in[MAX], out[MAX];

int find(int X) { return parent[X] == X ? X : parent[X] = find(parent[X]); }
void uni(int X, int Y) {
    X = find(X), Y = find(Y);
    if (X == Y)
        return;
    parent[max(X, Y)] = min(X, Y);
}

void lazy_propagate(int n, int s, int e) {
    if (lazy[n] == 0)
        return;
    tree[n] += lazy[n];
    if (s != e)
        lazy[n << 1] += lazy[n], lazy[n << 1 | 1] += lazy[n];
    lazy[n] = 0;
}

bool query(int n, int s, int e, int l, int r) {
    lazy_propagate(n, s, e);
    if (r < s || e < l)
        return false;
    else if (l <= s && e <= r)
        return tree[n];
    else {
        int m = s + e >> 1;
        return max(query(n << 1, s, m, l, r), query(n << 1 | 1, m + 1, e, l, r));
    }
}

void update(int n, int s, int e, int l, int r, int v) {
    lazy_propagate(n, s, e);
    if (r < s || e < l)
        return;
    else if (l <= s && e <= r)
        lazy[n] = v, lazy_propagate(n, s, e);
    else {
        int m = s + e >> 1;
        update(n << 1, s, m, l, r, v), update(n << 1 | 1, m + 1, e, l, r, v);
        tree[n] = max(tree[n << 1], tree[n << 1 | 1]);
    }
}

void chk(tp X, tp Y) {
    if (query(1, 1, SY, X[0], X[1]) > 0)
        uni(X[2], Y[2]);
}

vector<int> find_union(int N, vector<int> A, vector<int> B, vector<int> C, vector<int> D) {
    vector<int> ans(N), comp;

    for (int i = 0; i < N; i++)
        parent[i] = i;

    for (int i = 0; i < N; i++)
        comp.push_back(A[i]), comp.push_back(C[i]);
    sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end()), SX = comp.size();
    for (int i = 0; i < N; i++) {
        A[i] = lower_bound(comp.begin(), comp.end(), A[i]) - comp.begin() + 1;
        C[i] = lower_bound(comp.begin(), comp.end(), C[i]) - comp.begin() + 1;
    }

    comp.clear();
    for (int i = 0; i < N; i++)
        comp.push_back(B[i]), comp.push_back(D[i]);
    sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end()), SY = comp.size();
    for (int i = 0; i < N; i++) {
        B[i] = lower_bound(comp.begin(), comp.end(), B[i]) - comp.begin() + 1;
        D[i] = lower_bound(comp.begin(), comp.end(), D[i]) - comp.begin() + 1;
    }

    for (int i = 0; i < N; i++) {
        in[A[i]].push_back({B[i], D[i], i});
        out[C[i]].push_back({B[i], D[i], i});
    }

    set<tp> st;
    set<tp>::iterator iter;
    tp K;

    for (int i = 1; i <= SX; i++) {
        for (tp j : in[i]) {
            iter = st.lower_bound({j[0], 0, 0});
            if (iter != st.begin() && (*prev(iter))[1] >= j[0]) {
                iter = prev(iter), K = *iter, st.erase(iter);
                st.insert({K[0], j[0] - 1, K[2]});
                if (K[1] > j[1])
                    st.insert({j[1] + 1, K[1], K[2]});
                chk({j[0], min(K[1], j[1]), K[2]}, j);
            }

            iter = st.lower_bound({j[1] + 1, 0, 0});
            if (iter != st.begin() && (*prev(iter))[0] <= j[1] && (*prev(iter))[1] > j[1]) {
                iter = prev(iter), K = *iter, st.erase(iter);
                st.insert({j[1] + 1, K[1], K[2]});
                chk({K[0], j[1], K[2]}, j);
            }

            while (true) {
                iter = st.lower_bound({j[0], 0, 0});
                if (iter == st.end() || (*iter)[0] > j[1])
                    break;
                K = *iter, st.erase(iter), chk(K, j);
            }

            st.insert({j[0], j[1], j[2]});
            update(1, 1, SY, j[0], j[1], 1);
        }

        for (tp j : out[i])
            update(1, 1, SY, j[0], j[1], -1);
    }

    comp.clear();
    for (int i = 0; i < N; i++)
        comp.push_back(find(i));
    sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end());
    for (int i = 0; i < N; i++)
        ans[i] = lower_bound(comp.begin(), comp.end(), find(i)) - comp.begin();
    return ans;
}