#include <bits/stdc++.h>
#define int long long
#define N 1000001

using namespace std;

int tree[4 * N + 10000][2];

int query(int node, int start, int end, int left, int right)
{
    if (left <= start && end <= right)
        return tree[node][0];
    else if (right < start || end < left)
        return 0;
    else
    {
        int left_val = query(node << 1, start, ((start + end) >> 1), left, right);
        int right_val = query(node << 1 | 1, ((start + end) >> 1) + 1, end, left, right);
        return left_val + right_val;
    }
}

int bsearch(int node, int start, int end)
{
    if (start == end)
        return start;
    if (!tree[node << 1][1])
        return bsearch(node << 1 | 1, ((start + end) >> 1) + 1, end);
    else
        return bsearch(node << 1, start, ((start + end) >> 1));
}

void update(int type, int node, int start, int end, int index, int value)
{
    if (index < start || end < index)
        return;
    else if (start == end)
        tree[node][type] = type ? value : (tree[node][type] + value);
    else
    {
        update(type, node << 1, start, (start + end) >> 1, index, value);
        update(type, node << 1 | 1, ((start + end) >> 1) + 1, end, index, value);
        tree[node][type] = tree[node << 1][type] + tree[node << 1 | 1][type];
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int Q, A, B, last = 0;
    cin >> Q;
    for (int i = 1; i <= N; i++)
        update(1, 1, 0, N, i, 1);

    while (Q--)
    {
        cin >> A >> B;
        if (A == 1)
        {
            update(0, 1, 0, N, B, 1);
            update(1, 1, 0, N, B, 0);
        }
        else
        {
            update(0, 1, 0, N, B, -1);
            if (!query(1, 0, N, B, B))
                update(1, 1, 0, N, B, 1);
        }

        last = bsearch(1, 0, N);
        cout << query(1, 0, N, 0, last) << '\n';
    }

    return 0;
}