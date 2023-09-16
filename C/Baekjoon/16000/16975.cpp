#include <iostream>
using namespace std;

int N, A[100001];
long long int tree[400004];

void init(int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = (long long int)A[start];
    }
    else
    {
        init(node * 2, start, (int)((start + end) / 2));
        init(node * 2 + 1, (int)((start + end) / 2 + 1), end);
    }
}

void lazy_update(int node, int start, int end)
{
    if (start != end)
    {
        tree[node * 2] += tree[node];
        tree[node * 2 + 1] += tree[node];
        tree[node] = 0;
    }
}

long long int get(int node, int start, int end, int i)
{
    lazy_update(node, start, end);
    if (start == end && start == i)
    {
        return tree[node];
    }
    else if (start <= i && i <= end)
    {
        long long int left = get(node * 2, start, (start + end) / 2, i);
        long long int right = get(node * 2 + 1, (start + end) / 2 + 1, end, i);
        return left + right;
    }
    else
    {
        return 0;
    }
}

void update(int node, int start, int end, int left, int right, int value)
{
    lazy_update(node, start, end);
    if (right < start || end < left)
    {
        return;
    }
    else if (left <= start && end <= right)
    {
        tree[node] += value;
    }
    else
    {
        update(node * 2, start, (start + end) / 2, left, right, value);
        update(node * 2 + 1, (start + end) / 2 + 1, end, left, right, value);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int M, a, i, j, k;
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
    }
    init(1, 1, N);

    cin >> M;
    while (M--)
    {
        cin >> a >> i;
        if (a == 1)
        {
            cin >> j >> k;
            update(1, 1, N, i, j, k);
        }
        else
        {
            cout << get(1, 1, N, i) << '\n';
        }
    }
}
