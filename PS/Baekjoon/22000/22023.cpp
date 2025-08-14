#include "candies.h"

#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 4> pr;

const int MAX = 200001;
const int INF = 0x3f3f3f3f3f3f3f3f;

int N, lazy[MAX * 4];
vector<int> in[MAX], out[MAX];
pr tree[MAX * 4];

pr merge(pr X, pr Y) {
    pr res = {min(X[0], Y[0]), 0, max(X[2], Y[2]), 0};
    if (res[0] == X[0])
        res[1] = max(res[1], X[1]);
    if (res[0] == Y[0])
        res[1] = max(res[1], Y[1]);
    if (res[2] == X[2])
        res[3] = max(res[3], X[3]);
    if (res[2] == Y[2])
        res[3] = max(res[3], Y[3]);
    return res;
}

void init(int n, int s, int e) {
    if (s == e)
        tree[n][1] = tree[n][3] = s;
    else {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
        tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
    }
}

void lazy_update(int n, int s, int e) {
    if (lazy[n] == 0)
        return;
    tree[n][0] += lazy[n], tree[n][2] += lazy[n];
    if (s ^ e)
        lazy[n << 1] += lazy[n], lazy[n << 1 | 1] += lazy[n];
    lazy[n] = 0;
}

void update(int n, int s, int e, int l, int r, int v) {
    lazy_update(n, s, e);
    if (r < s || e < l)
        return;
    else if (l <= s && e <= r)
        lazy[n] += v, lazy_update(n, s, e);
    else {
        int m = s + e >> 1;
        update(n << 1, s, m, l, r, v), update(n << 1 | 1, m + 1, e, l, r, v);
        tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
    }
}

pr query(int n, int s, int e, int l, int r) {
    lazy_update(n, s, e);
    if (r < s || e < l)
        return {INF, 0, -INF, 0};
    else if (l <= s && e <= r)
        return tree[n];
    else {
        int m = s + e >> 1;
        return merge(
            query(n << 1, s, m, l, r),
            query(n << 1 | 1, m + 1, e, l, r));
    }
}

vector<signed> distribute_candies(vector<signed> C, vector<signed> l,
                                  vector<signed> r, vector<signed> V) {
    vector<signed> ans;
    int Q = l.size(), S, st, en, md, X, Y;
    pr K;

    N = C.size(), init(1, 0, Q - 1);
    for (int i = 0; i < Q; i++)
        in[l[i]].push_back(i), out[r[i] + 1].push_back(i);

    ans.resize(N, 0);
    for (int i = 0; i < N; i++) {
        for (int j : in[i])
            update(1, 0, Q, j + 1, Q, V[j]);
        for (int j : out[i])
            update(1, 0, Q, j + 1, Q, -V[j]);
        S = query(1, 0, Q, Q, Q)[0];

        st = 0, en = Q, X = -1;
        while (st <= en) {
            md = st + en >> 1, K = query(1, 0, Q, md, Q);
            if (K[2] - K[0] >= C[i])
                st = md + 1, X = md;
            else
                en = md - 1;
        }

        if (X == -1)
            ans[i] = S - min(0ll, query(1, 0, Q, 0, Q)[0]);
        else {
            K = query(1, 0, Q, X, Q);
            if (K[3] >= K[1])
                ans[i] = C[i] + S - K[2];
            else
                ans[i] = S - K[0];
        }
    }

    return ans;
}