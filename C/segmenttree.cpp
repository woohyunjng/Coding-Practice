#include <bits/stdc++.h>
#define int long long
#define MAX 1000000

int M(int a, int b) { return a + b; }

// 비재귀
int N, tree[2 * MAX + 1];

void init()
{
    for (int i = N - 1; i > 0; --i)
        tree[i] = M(tree[i << 1], tree[i << 1 | 1]);
}

void update(int pos, int val)
{
    for (tree[pos += N] = val; pos > 1; pos >>= 1)
        tree[pos >> 1] = M(tree[pos], tree[pos ^ 1]);
}

int query(int l, int r)
{
    int res = 0;
    for (l += N, r += N; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
            res = M(res, tree[l++]);
        if (r & 1)
            res = M(res, tree[--r]);
    }
    return res;
}

// 재귀
int N, tree[4 * MAX + 1], arr[MAX];

void init(int node, int start, int end)
{
    if (start == end)
        tree[node] = arr[start];
    else
    {
        init(node << 1, start, (start + end) >> 1);
        init(node << 1 | 1, ((start + end) >> 1) + 1, end);
        tree[node] = M(tree[node << 1], tree[node << 1 | 1]);
    }
}

int query(int node, int start, int end, int left, int right)
{
    if (left <= start && end <= right)
        return tree[node];
    else if (right < start || end < left)
        return 0;
    else
    {
        int left_val = query(node << 1, start, ((start + end) >> 1), left, right);
        int right_val = query(node << 1 | 1, ((start + end) >> 1) + 1, end, left, right);
        return M(left_val, right_val);
    }
}

void update(int node, int start, int end, int index, int value)
{
    if (index < start || end < index)
        return;
    else if (start == end)
    {
        tree[node] = value;
        arr[start] = value;
    }
    else
    {
        update(node << 1, start, (start + end) >> 1, index, value);
        update(node << 1 | 1, ((start + end) >> 1) + 1, end, index, value);
        tree[node] = M(tree[node << 1], tree[node << 1 | 1]);
    }
}