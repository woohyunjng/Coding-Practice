#include "seats.h"
#include <bits/stdc++.h>

#define MAX 1000010

using namespace std;
typedef array<int, 2> pr;
typedef array<int, 3> tp;

tp tree[MAX * 4];
pr val[MAX], lazy[MAX * 4], A[MAX];
int H, W;
vector<vector<int>> arr;

tp merge(tp X, tp Y) {
    if (X[0] < Y[0])
        return X;
    else if (X[0] > Y[0])
        return Y;
    else if (X[1] < Y[1])
        return X;
    else if (X[1] > Y[1])
        return Y;
    return {X[0], X[1], X[2] + Y[2]};
}

void init(int n, int s, int e) {
    if (s == e)
        tree[n] = {A[s][0], A[s][1], 1};
    else {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
        tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
    }
}

void lazy_propagate(int n, int s, int e) {
    if (lazy[n][0] == 0 && lazy[n][1] == 0)
        return;
    tree[n][0] += lazy[n][0], tree[n][1] += lazy[n][1];
    if (s != e) {
        lazy[n << 1][0] += lazy[n][0], lazy[n << 1][1] += lazy[n][1];
        lazy[n << 1 | 1][0] += lazy[n][0], lazy[n << 1 | 1][1] += lazy[n][1];
    }
    lazy[n][0] = lazy[n][1] = 0;
}

tp query(int n, int s, int e, int l, int r) {
    lazy_propagate(n, s, e);
    if (r < s || e < l)
        return {MAX, MAX, 0};
    else if (l <= s && e <= r)
        return tree[n];
    else {
        int m = s + e >> 1;
        return merge(
            query(n << 1, s, m, l, r),
            query(n << 1 | 1, m + 1, e, l, r));
    }
}

void update(int n, int s, int e, int l, int r, pr x) {
    lazy_propagate(n, s, e);
    if (r < s || e < l)
        return;
    else if (l <= s && e <= r) {
        lazy[n][0] += x[0], lazy[n][1] += x[1];
        lazy_propagate(n, s, e);
    } else {
        int m = s + e >> 1;
        update(n << 1, s, m, l, r, x), update(n << 1 | 1, m + 1, e, l, r, x);
        tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
    }
}

void upd(int x, int y, int v, bool seg = true) {
    vector<int> st;
    int X, Y;

    if (x < H && y < W)
        st.push_back(arr[x][y]);
    if (0 < x && y < W)
        st.push_back(arr[x - 1][y]);
    if (0 < y && x < H)
        st.push_back(arr[x][y - 1]);
    if (0 < x && 0 < y)
        st.push_back(arr[x - 1][y - 1]);
    sort(st.begin(), st.end());

    if (st.size() == 1)
        X = st[0], Y = H * W;
    else
        X = st[0], Y = st[1];

    if (seg)
        update(1, 0, H * W - 1, X, Y - 1, {v, 0});
    else
        A[X][0]++, A[Y][0]--;

    if (st.size() == 1)
        return;

    X = H * W, Y = H * W;

    if (st.size() >= 3)
        X = st[2], Y = st[3];
    if ((val[st[0]][0] - val[st[1]][0]) * (val[st[0]][1] - val[st[1]][1]) != 0)
        X = st[1];

    if (seg && X < Y)
        update(1, 0, H * W - 1, X, Y - 1, {0, v});
    else if (X < Y)
        A[X][1]++, A[Y][1]--;
}

void give_initial_chart(int h, int w, vector<int> R, vector<int> C) {
    H = h, W = w;
    arr.resize(H + 1, vector<int>(W + 1, 0));

    for (int i = 0; i < H * W; i++)
        val[i] = {R[i], C[i]}, arr[R[i]][C[i]] = i;

    for (int i = 0; i <= H; i++)
        for (int j = 0; j <= W; j++)
            upd(i, j, 1, false);

    for (int i = 1; i < H * W; i++)
        A[i][0] += A[i - 1][0], A[i][1] += A[i - 1][1];
    init(1, 0, H * W - 1);
}

int swap_seats(int a, int b) {
    vector<pr> st;
    st.push_back({val[a][0], val[a][1]}), st.push_back({val[a][0] + 1, val[a][1]}), st.push_back({val[a][0], val[a][1] + 1}), st.push_back({val[a][0] + 1, val[a][1] + 1});
    st.push_back({val[b][0], val[b][1]}), st.push_back({val[b][0] + 1, val[b][1]}), st.push_back({val[b][0], val[b][1] + 1}), st.push_back({val[b][0] + 1, val[b][1] + 1});
    sort(st.begin(), st.end()), st.erase(unique(st.begin(), st.end()), st.end());

    for (pr i : st)
        upd(i[0], i[1], -1);
    swap(val[a], val[b]), arr[val[a][0]][val[a][1]] = a, arr[val[b][0]][val[b][1]] = b;
    for (pr i : st)
        upd(i[0], i[1], 1);

    tp res = query(1, 0, H * W - 1, 0, H * W - 1);
    return res[2];
}