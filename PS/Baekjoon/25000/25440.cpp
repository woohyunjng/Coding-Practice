#include "towers.h"
#include <bits/stdc++.h>
using namespace std;

typedef array<int, 2> pr;
typedef array<int, 3> tp;

const int MAX = 100001;

struct Node {
    int l, r, mx, mn, sm;

    Node() : l(-1), r(-1), mx(0), mn(MAX), sm(0) {};
    Node(int l, int r, int mx, int mn, int sm) : l(l), r(r), mx(mx), mn(mn), sm(sm) {};
};

vector<Node> tree;
vector<int> root, num;

int N, seg[MAX * 4], T[MAX], H[MAX];
bool chk[MAX];

void tree_init(int n, int s, int e) {
    if (s == e) {
        if (T[s] > 0)
            tree[n].mn = tree[n].mx = s, tree[n].sm = T[s] == 1;
    } else {
        int m = s + e >> 1;
        tree[n].l = tree.size(), tree.push_back(Node());
        tree[n].r = tree.size(), tree.push_back(Node());
        tree_init(tree[n].l, s, m), tree_init(tree[n].r, m + 1, e);

        tree[n].mx = max(tree[tree[n].l].mx, tree[tree[n].r].mx);
        tree[n].mn = min(tree[tree[n].l].mn, tree[tree[n].r].mn);
        tree[n].sm = tree[tree[n].l].sm + tree[tree[n].r].sm;
    }
}

void update(int n, int s, int e, int x) {
    if (s == e)
        tree[n].sm = 0, tree[n].mn = MAX, tree[n].mx = 0;
    else {
        int m = s + e >> 1;
        if (x <= m) {
            tree.push_back(Node(tree[tree[n].l].l, tree[tree[n].l].r, tree[tree[n].l].mx, tree[tree[n].l].mn, tree[tree[n].l].sm));
            tree[n].l = tree.size() - 1, update(tree[n].l, s, m, x);
        } else {
            tree.push_back(Node(tree[tree[n].r].l, tree[tree[n].r].r, tree[tree[n].r].mx, tree[tree[n].r].mn, tree[tree[n].r].sm));
            tree[n].r = tree.size() - 1, update(tree[n].r, m + 1, e, x);
        }
        tree[n].mx = max(tree[tree[n].l].mx, tree[tree[n].r].mx);
        tree[n].mn = min(tree[tree[n].l].mn, tree[tree[n].r].mn);
        tree[n].sm = tree[tree[n].l].sm + tree[tree[n].r].sm;
    }
}

tp query(int n, int s, int e, int l, int r) {
    if (r < s || e < l)
        return {0, MAX, 0};
    else if (l <= s && e <= r)
        return {tree[n].mx, tree[n].mn, tree[n].sm};
    else {
        int m = s + e >> 1;
        tp left = query(tree[n].l, s, m, l, r);
        tp right = query(tree[n].r, m + 1, e, l, r);
        return {max(left[0], right[0]), min(left[1], right[1]), left[2] + right[2]};
    }
}

void seg_init(int n, int s, int e) {
    if (s == e)
        seg[n] = H[s];
    else {
        int m = s + e >> 1;
        seg_init(n << 1, s, m), seg_init(n << 1 | 1, m + 1, e);
        seg[n] = min(seg[n << 1], seg[n << 1 | 1]);
    }
}

int seg_query(int n, int s, int e, int l, int r) {
    if (r < s || e < l)
        return 2e9;
    else if (l <= s && e <= r)
        return seg[n];
    else {
        int m = s + e >> 1;
        return min(seg_query(n << 1, s, m, l, r), seg_query(n << 1 | 1, m + 1, e, l, r));
    }
}

void init(int n, vector<int> h) {
    N = n;

    vector<int> arr;
    for (int i = 0; i < N; i++) {
        H[i] = h[i];
        if (arr.size() >= 2 && ((H[arr[arr.size() - 2]] <= H[arr[arr.size() - 1]] && H[arr[arr.size() - 1]] <= H[i]) || (H[arr[arr.size() - 2]] >= H[arr[arr.size() - 1]] && H[arr[arr.size() - 1]] >= H[i])))
            arr.pop_back();
        arr.push_back(i);
    }

    seg_init(1, 0, N - 1);

    set<int> idx;
    set<tp> st;
    set<int>::iterator it;

    int L, R, D;

    for (int i = 0; i + 1 < arr.size(); i++)
        st.insert((tp){abs(H[arr[i]] - H[arr[i + 1]]), arr[i], arr[i + 1]});
    for (int i = 0; i < arr.size(); i++)
        idx.insert(arr[i]);

    if (arr.size() >= 2) {
        if (H[arr[0]] < H[arr[1]]) {
            for (int i = 0; i < arr.size(); i += 2)
                T[arr[i]] = 1;
            for (int i = 1; i < arr.size(); i += 2)
                T[arr[i]] = 2;
        } else {
            for (int i = 0; i < arr.size(); i += 2)
                T[arr[i]] = 2;
            for (int i = 1; i < arr.size(); i += 2)
                T[arr[i]] = 1;
        }
    }
    tree.push_back(Node()), root.push_back(0), tree_init(root[0], 0, N - 1);

    while (!st.empty()) {
        L = (*st.begin())[1], R = (*st.begin())[2], D = (*st.begin())[0], st.erase(st.begin());
        if (idx.find(L) == idx.end() || idx.find(R) == idx.end())
            continue;

        num.push_back(D), idx.erase(L), idx.erase(R);
        tree.push_back(Node(tree[root.back()].l, tree[root.back()].r, tree[root.back()].mx, tree[root.back()].mn, tree[root.back()].sm)), root.push_back(tree.size() - 1);
        update(root.back(), 0, N - 1, L), update(root.back(), 0, N - 1, R);

        it = idx.lower_bound(L);
        if (it == idx.begin())
            continue;
        it = prev(it), L = *it;
        it = idx.lower_bound(R);
        if (it == idx.end())
            continue;
        R = *it;
        st.insert({abs(H[L] - H[R]), L, R});
    }
}

int max_towers(int L, int R, int D) {
    int res, TL, TR, TD;
    TD = lower_bound(num.begin(), num.end(), D) - num.begin();
    tp val = query(root[TD], 0, N - 1, L, R);

    TL = val[1], TR = val[0];
    if (TL == MAX || TR == 0 || TL > TR)
        return 1;
    res = query(root[TD], 0, N - 1, TL, TR)[2];

    if (T[TL] == 2 && seg_query(1, 0, N - 1, L, TL - 1) <= H[TL] - D)
        res++;
    if (T[TR] == 2 && seg_query(1, 0, N - 1, TR + 1, R) <= H[TR] - D)
        res++;

    res = max(1, res);
    return res;
}