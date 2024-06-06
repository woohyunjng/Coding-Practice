#include <iostream>
#include <vector>
#define MAX 100001
using namespace std;

vector<int> child[MAX];
int arr[MAX] = {}, st[MAX], en[MAX], num = 0;
int tree[MAX * 4] = {};

void dfs(int A)
{
    st[A] = ++num;
    for (int B : child[A])
    {
        dfs(B);
    }
    en[A] = num;
}

void init(int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = arr[start];
    }
    else
    {
        init(node * 2, start, (start + end) >> 1);
        init(node * 2 + 1, ((start + end) >> 1) + 1, end);
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

int query(int node, int start, int end, int index)
{
    lazy_update(node, start, end);
    if (index < start || end < index)
    {
        return 0;
    }
    else if (start == end)
    {
        return tree[node];
    }
    else
    {
        int left = query(node * 2, start, ((start + end) >> 1), index);
        int right = query(node * 2 + 1, ((start + end) >> 1) + 1, end, index);
        return left + right;
    }
}

void update(int node, int start, int end, int left, int right, int val)
{
    lazy_update(node, start, end);
    if (right < start || end < left)
    {
        return;
    }
    else if (left <= start && end <= right)
    {
        tree[node] += val;
        return;
    }

    update(node * 2, start, ((start + end) >> 1), left, right, val);
    update(node * 2 + 1, ((start + end) >> 1) + 1, end, left, right, val);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, A, B, C;
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        cin >> A;
        if (i != 1)
            child[A].push_back(i);
    }
    dfs(1);

    init(1, 1, N);

    while (M--)
    {
        cin >> A >> B;
        if (A == 1)
        {
            cin >> C;
            update(1, 1, N, st[B], en[B], C);
        }
        else
        {
            cout << query(1, 1, N, st[B]) << '\n';
        }
    }
}