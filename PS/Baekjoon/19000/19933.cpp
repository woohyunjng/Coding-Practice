#include "plants.h"
#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef array<int, 2> pr;
typedef array<int, 3> tp;

const int MAX = 400001;
const int MAX_LOG = 20;

int N, K, lazy[MAX * 4], V[MAX], L[MAX][MAX_LOG][2], R[MAX][MAX_LOG][2];
bool chk[MAX];
pr tree1[MAX * 4];
tp tree2[MAX * 4];

vector<int> adj[MAX], val[MAX];

set<int> st;
set<int>::iterator iter;

pr merge(pr X, pr Y) {
    pr res = {min(X[0], Y[0]), MAX};
    if (res[0] == X[0])
        res[1] = min(res[1], X[1]);
    if (res[0] == Y[0])
        res[1] = min(res[1], Y[1]);
    return res;
}

tp merge(tp X, tp Y) {
    tp res = {max(X[0], Y[0]), MAX, 0};
    if (res[0] == X[0])
        res[1] = min(res[1], X[1]), res[2] = max(res[2], X[2]);
    if (res[0] == Y[0])
        res[1] = min(res[1], Y[1]), res[2] = max(res[2], Y[2]);
    return res;
}

void init1(int n, int s, int e) {
    if (s == e)
        tree1[n][0] = 0, tree1[n][1] = s;
    else {
        int m = s + e >> 1;
        init1(n << 1, s, m), init1(n << 1 | 1, m + 1, e);
        tree1[n] = merge(tree1[n << 1], tree1[n << 1 | 1]);
    }
}

void init2(int n, int s, int e) {
    if (s == e)
        tree2[n][0] = 0, tree2[n][1] = tree2[n][2] = s;
    else {
        int m = s + e >> 1;
        init2(n << 1, s, m), init2(n << 1 | 1, m + 1, e);
        tree2[n] = merge(tree2[n << 1], tree2[n << 1 | 1]);
    }
}

void update2(int n, int s, int e, int x, int v) {
    if (x < s || e < x)
        return;
    else if (s == e)
        tree2[n][0] = v;
    else {
        int m = s + e >> 1;
        update2(n << 1, s, m, x, v), update2(n << 1 | 1, m + 1, e, x, v);
        tree2[n] = merge(tree2[n << 1], tree2[n << 1 | 1]);
    }
}

tp query2(int n, int s, int e, int l, int r) {
    if (r < s || e < l)
        return {0, MAX, 0};
    else if (l <= s && e <= r)
        return tree2[n];
    else {
        int m = s + e >> 1;
        return merge(
            query2(n << 1, s, m, l, r),
            query2(n << 1 | 1, m + 1, e, l, r));
    }
}

void lazy_update(int n, int s, int e) {
    if (lazy[n] == 0)
        return;
    tree1[n][0] += lazy[n];
    if (s ^ e)
        lazy[n << 1] += lazy[n], lazy[n << 1 | 1] += lazy[n];
    lazy[n] = 0;
}

pr query1(int n, int s, int e, int l, int r) {
    lazy_update(n, s, e);
    if (r < s || e < l)
        return {1000000, 0};
    else if (l <= s && e <= r)
        return tree1[n];
    else {
        int m = s + e >> 1;
        return merge(
            query1(n << 1, s, m, l, r),
            query1(n << 1 | 1, m + 1, e, l, r));
    }
}

void add1(int n, int s, int e, int l, int r, int v) {
    lazy_update(n, s, e);
    if (r < s || e < l)
        return;
    else if (l <= s && e <= r)
        lazy[n] += v, lazy_update(n, s, e);
    else {
        int m = s + e >> 1;
        add1(n << 1, s, m, l, r, v), add1(n << 1 | 1, m + 1, e, l, r, v);
        tree1[n] = merge(tree1[n << 1], tree1[n << 1 | 1]);
    }
}

void update1(int n, int s, int e, int x, int v) {
    lazy_update(n, s, e);
    if (x < s || e < x)
        return;
    else if (s == e)
        tree1[n][0] = v;
    else {
        int m = s + e >> 1;
        update1(n << 1, s, m, x, v), update1(n << 1 | 1, m + 1, e, x, v);
        tree1[n] = merge(tree1[n << 1], tree1[n << 1 | 1]);
    }
}

bool check(int X) {
    iter = st.lower_bound(X + N);
    return !chk[X] && (X + N - (*prev(iter)) >= K);
}

void init(signed _K, vector<signed> RV) {
    N = RV.size(), K = _K, init1(1, 0, N - 1);
    vector<int> arr, nxt;

    int X = -1, Y = N, Z;
    pr A;

    for (int i = 0; i < N; i++) {
        update1(1, 0, N - 1, i, RV[i]);
        if (RV[i] == 0)
            st.insert(i), st.insert(i + N);
    }

    for (int i = 0; i < N; i++) {
        if (RV[i] != 0)
            continue;
        if (check(i))
            arr.push_back(i), chk[i] = true;
        update1(1, 0, N - 1, i, MAX * 2);
    }

    while (!arr.empty()) {
        for (int i : arr) {
            add1(1, 0, N - 1, i - (K - 1), i - 1, -1);
            add1(1, 0, N - 1, N + i - (K - 1), N - 1, -1);
            st.erase(i), st.erase(i + N), V[i + 1] = Y, val[V[i + 1]].push_back(i + 1);

            iter = st.lower_bound(i + N);
            if (iter != st.end())
                nxt.push_back((*iter) - N);

            iter = st.lower_bound(i);
            if (iter != st.begin())
                nxt.push_back(*prev(iter));
            if (!st.empty())
                nxt.push_back(*st.begin()), nxt.push_back((*prev(st.end())) - N);

            while (true) {
                A = merge(query1(1, 0, N - 1, i - (K - 1), i - 1),
                          query1(1, 0, N - 1, N + i - (K - 1), N - 1));
                if (A[0] != 0)
                    break;
                nxt.push_back(A[1]), st.insert(A[1]), st.insert(A[1] + N);
                update1(1, 0, N - 1, A[1], MAX * 2);
            }
        }
        Y--;

        arr.clear();
        for (int i : nxt)
            if (check(i))
                arr.push_back(i), chk[i] = true;
        nxt.clear();
    }

    init2(1, 1, N);
    tp B, C;

    for (int i = 1; i <= N; i++) {
        for (int j : val[i]) {
            B = query2(1, 1, N, j + 1, j + K - 1);
            C = query2(1, 1, N, 1, j + (K - 1) - N);
            R[j][0][0] = C[0] >= B[0] ? C[2] : B[2], R[j][0][1] = C[0] >= B[0];

            if (C[0] == B[0] && C[0] == 0)
                R[j][0][0] = 0;

            B = query2(1, 1, N, j - (K - 1), j - 1);
            C = query2(1, 1, N, N + j - (K - 1), N);
            L[j][0][0] = C[0] >= B[0] ? C[1] : B[1], L[j][0][1] = C[0] >= B[0];

            if (C[0] == B[0] && C[0] == 0)
                L[j][0][0] = 0;
        }

        for (int j : val[i])
            update2(1, 1, N, j, i);
    }

    for (int i = 1; i < MAX_LOG; i++)
        for (int j = 1; j <= N; j++) {
            L[j][i][0] = L[L[j][i - 1][0]][i - 1][0];
            L[j][i][1] = L[L[j][i - 1][0]][i - 1][1] + L[j][i - 1][1];
            R[j][i][0] = R[R[j][i - 1][0]][i - 1][0];
            R[j][i][1] = R[R[j][i - 1][0]][i - 1][1] + R[j][i - 1][1];
        }
}

bool comp(int X, int Y) { // X > Y
    int XL = X, XR = X, XFL = 0, XFR = 0;
    for (int j = MAX_LOG - 1; j >= 0; j--) {
        if (V[L[XL][j][0]] >= V[Y])
            XFL += L[XL][j][1], XL = L[XL][j][0];
        if (V[R[XR][j][0]] >= V[Y])
            XFR += R[XR][j][1], XR = R[XR][j][0];
    }

    XL -= N * XFL, XR += N * XFR;

    bool res = false;
    for (int i = -1; i <= 1; i++) {
        res |= (XL <= (Y + N * i)) && ((Y + N * i) <= X);
        res |= (X <= (Y + N * i)) && ((Y + N * i) <= XR);
    }
    return res;
}

signed compare_plants(signed X, signed Y) {
    X++, Y++;
    if (comp(X, Y))
        return 1;
    else if (comp(Y, X))
        return -1;
    return 0;
}
