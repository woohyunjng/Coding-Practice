#include <bits/stdc++.h>
#define int long long
#define MAX 1000000

class Node
{
public:
    int val = 0;
    Node() {}
    Node(int v) : val(v) {}
    Node operator+(Node &ref)
    {
        return Node(val + ref.val);
    }
};

// 비재귀

class SegTree
{
public:
    int N, arr[MAX];
    Node tree[2 * MAX + 1];

    SegTree(int n) : N(n) {}

    void init()
    {
        for (int i = 1; i <= N; i++)
            tree[i + N - 1].val = arr[i];

        for (int i = N - 1; i > 0; --i)
            tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }
    Node query(int l, int r)
    {
        Node res;
        for (l += N - 1, r += N; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                res = res + tree[l++];
            if (r & 1)
                res = res + tree[--r];
        }
        return res;
    }
    Node query(int pos) { return query(pos, pos); }
    void update(int pos, int val)
    {
        for (tree[pos += N - 1] = val; pos > 1; pos >>= 1)
            tree[pos >> 1] = tree[pos] + tree[pos ^ 1];
    }
};

// 재귀

class SegTree
{
private:
    void init(int n, int s, int e)
    {
        if (s == e)
            tree[n] = arr[s];
        else
        {
            init(n << 1, s, (s + e) >> 1);
            init(n << 1 | 1, ((s + e) >> 1) + 1, e);
            tree[n] = tree[n << 1] + tree[n << 1 | 1];
        }
    }

    Node query(int n, int s, int e, int l, int r)
    {
        if (l <= s && e <= r)
            return tree[n];
        else if (r < s || e < l)
            return 0;
        else
        {
            Node lv = query(n << 1, s, ((s + e) >> 1), l, r);
            Node rv = query(n << 1 | 1, ((s + e) >> 1) + 1, e, l, r);
            return lv + rv;
        }
    }

    void update(int n, int s, int e, int pos, int val)
    {
        if (pos < s || e < pos)
            return;
        else if (s == e)
        {
            tree[n] = val;
            arr[s] = val;
        }
        else
        {
            update(n << 1, s, (s + e) >> 1, pos, val);
            update(n << 1 | 1, ((s + e) >> 1) + 1, e, pos, val);
            tree[n] = tree[n << 1] + tree[n << 1 | 1];
        }
    }

public:
    int N, arr[MAX];
    Node tree[4 * MAX + 1];

    SegTree(int n) : N(n) {}

    void init() { init(1, 1, N); }
    Node query(int pos) { return query(1, 1, N, pos, pos); }
    Node query(int l, int r) { return query(1, 1, N, l, r); }
    void update(int pos, int val) { update(1, 1, N, pos, val); }
};