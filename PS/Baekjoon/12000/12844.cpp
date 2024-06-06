#include <bits/stdc++.h>
#define int long long
using namespace std;

int arr[600000], tree[600000 * 4], lazy[600000 * 4];

void lazy_update(int node, int start, int end)
{
    int length = end - start + 1;
    if (length % 2)
        tree[node] ^= lazy[node];
    if (start != end)
    {
        lazy[node << 1] ^= lazy[node];
        lazy[node << 1 | 1] ^= lazy[node];
    }
    lazy[node] = 0;
}

void init(int node, int start, int end)
{
    if (start == end)
        tree[node] = arr[start];
    else
    {
        init(node << 1, start, (start + end) >> 1);
        init(node << 1 | 1, ((start + end) >> 1) + 1, end);
        tree[node] = tree[node << 1] ^ tree[node << 1 | 1];
    }
}

void update(int node, int start, int end, int left, int right, int value)
{
    lazy_update(node, start, end);
    if (right < start || end < left)
        return;
    else if (left <= start && end <= right)
    {
        lazy[node] ^= value;
        lazy_update(node, start, end);
    }
    else
    {
        update(node << 1, start, (start + end) >> 1, left, right, value);
        update(node << 1 | 1, ((start + end) >> 1) + 1, end, left, right, value);
        tree[node] = tree[node << 1] ^ tree[node << 1 | 1];
    }
}

int query(int node, int start, int end, int left, int right)
{
    lazy_update(node, start, end);
    if (right < start || end < left)
        return 0;
    else if (left <= start && end <= right)
        return tree[node];
    else
    {
        int left_value = query(node << 1, start, (start + end) >> 1, left, right);
        int right_value = query(node << 1 | 1, ((start + end) >> 1) + 1, end, left, right);
        return left_value ^ right_value;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, Q, A, i, j, k;
    cin >> N;

    for (i = 0; i < N; i++)
        cin >> arr[i];
    init(1, 0, N - 1);

    cin >> Q;
    while (Q--)
    {
        cin >> A;
        if (A == 1)
        {
            cin >> i >> j >> k;
            update(1, 0, N - 1, i, j, k);
        }
        else
        {
            cin >> i >> j;
            cout << query(1, 0, N - 1, i, j) << '\n';
        }
    }

    return 0;
}