#include <iostream>
using namespace std;

long long int tree[1000001 * 4];
long long int lazy[1000001 * 4] = {};
long long int arr[1000001];
int N;

void init(int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = arr[start];
    }
    else
    {
        init(node * 2, start, (int)((start + end) / 2));
        init(node * 2 + 1, (int)((start + end) / 2) + 1, end);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
}

void lazy_update(int node, int start, int end)
{
    tree[node] += lazy[node] * (end - start + 1);
    if (start != end)
    {
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
    }
    lazy[node] = 0;
}

long long int update(int node, int start, int end, int left, int right, long long int value)
{
    lazy_update(node, start, end);
    if (end < left || right < start)
    {
        return tree[node];
    }
    else if (left <= start && end <= right)
    {
        lazy[node] += value;
        lazy_update(node, start, end);
        return tree[node];
    }
    else
    {
        long long int left_sum = update(node * 2, start, (int)((start + end) / 2), left, right, value);
        long long int right_sum = update(node * 2 + 1, (int)((start + end) / 2) + 1, end, left, right, value);
        tree[node] = left_sum + right_sum;
        return tree[node];
    }
}

long long int query(int node, int start, int end, int left, int right)
{
    lazy_update(node, start, end);
    if (left > end || right < start)
    {
        return 0;
    }
    else if (left <= start && end <= right)
    {
        return tree[node];
    }
    else
    {
        long long int left_min = query(node * 2, start, (int)((start + end) / 2), left, right);
        long long int right_min = query(node * 2 + 1, (int)((start + end) / 2) + 1, end, left, right);
        return left_min + right_min;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int M, K, a, b, c;
    long long int d;

    cin >> N >> M >> K;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    init(1, 0, N - 1);

    for (int i = 0; i < M + K; i++)
    {
        cin >> a;
        if (a == 1)
        {
            cin >> b >> c >> d;
            update(1, 0, N - 1, --b, --c, d);
        }
        else
        {
            cin >> b >> c;
            cout << query(1, 0, N - 1, --b, --c) << '\n';
        }
    }
}
