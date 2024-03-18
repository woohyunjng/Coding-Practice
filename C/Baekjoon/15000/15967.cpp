#include <iostream>
#define MAX 1000001
typedef long long int lli;
using namespace std;

lli tree[MAX * 4], lazy[MAX * 4], arr[MAX];

void init(int node, int start, int end)
{
    if (start == end)
        tree[node] = arr[start];
    else
    {
        init(node * 2, start, (start + end) >> 1);
        init(node * 2 + 1, ((start + end) >> 1) + 1, end);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
}

void lazy_update(int node, int start, int end)
{
    tree[node] += (end - start + 1) * lazy[node];
    if (start != end)
    {
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
    }
    lazy[node] = 0;
}

void update(int node, int start, int end, int left, int right, int value)
{
    lazy_update(node, start, end);
    if (right < start || end < left)
        return;
    else if (left <= start && end <= right)
    {
        lazy[node] += value;
        lazy_update(node, start, end);
        return;
    }

    update(node * 2, start, (start + end) >> 1, left, right, value);
    update(node * 2 + 1, ((start + end) >> 1) + 1, end, left, right, value);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

lli query(int node, int start, int end, int left, int right)
{
    lazy_update(node, start, end);
    if (right < start || end < left)
        return 0;
    else if (left <= start && end <= right)
        return tree[node];

    lli left_sum = query(node * 2, start, (start + end) >> 1, left, right);
    lli right_sum = query(node * 2 + 1, ((start + end) >> 1) + 1, end, left, right);
    return left_sum + right_sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, Q1, Q2, Q, A, B, C, D;
    cin >> N >> Q1 >> Q2;
    Q = Q1 + Q2;

    for (int i = 0; i < N; i++)
        cin >> arr[i];
    init(1, 0, N - 1);

    while (Q--)
    {
        cin >> A >> B >> C;
        if (A == 1)
            cout << query(1, 0, N - 1, B - 1, C - 1) << '\n';
        else
        {
            cin >> D;
            update(1, 0, N - 1, B - 1, C - 1, D);
        }
    }
}