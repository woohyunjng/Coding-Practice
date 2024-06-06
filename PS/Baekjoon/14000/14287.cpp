#include <iostream>
#include <vector>
#define MAX 100001
using namespace std;

vector<int> child[MAX];
int st[MAX], en[MAX], num = 0;
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
        tree[node] = 0;
    }
    else
    {
        init(node * 2, start, (start + end) >> 1);
        init(node * 2 + 1, ((start + end) >> 1) + 1, end);
    }
}

int query(int node, int start, int end, int left, int right)
{
    if (right < start || end < left)
    {
        return 0;
    }
    else if (left <= start && end <= right)
    {
        return tree[node];
    }

    int left_val = query(node * 2, start, ((start + end) >> 1), left, right);
    int right_val = query(node * 2 + 1, ((start + end) >> 1) + 1, end, left, right);
    return left_val + right_val;
}

void update(int node, int start, int end, int index, int val)
{
    if (index < start || end < index)
    {
        return;
    }
    else if (start == end)
    {
        tree[node] += val;
        return;
    }

    update(node * 2, start, ((start + end) >> 1), index, val);
    update(node * 2 + 1, ((start + end) >> 1) + 1, end, index, val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
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
            update(1, 1, N, st[B], C);
        }
        else
        {
            cout << query(1, 1, N, st[B], en[B]) << '\n';
        }
    }
}