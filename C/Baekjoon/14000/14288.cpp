#include <iostream>
#include <vector>
#define MAX 100001
using namespace std;

vector<int> child[MAX];
int st[MAX], en[MAX], num = 0;
pair<int, int> tree[MAX * 4] = {};
bool dw = true;

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
        tree[node] = {0, 0};
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
        tree[node * 2].first += tree[node].first;
        tree[node * 2 + 1].first += tree[node].first;
        tree[node].first = 0;
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
        return tree[node].first;
    }
    else
    {
        int left = query(node * 2, start, ((start + end) >> 1), index);
        int right = query(node * 2 + 1, ((start + end) >> 1) + 1, end, index);
        return left + right;
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
        return tree[node].second;
    }

    int left_val = query(node * 2, start, ((start + end) >> 1), left, right);
    int right_val = query(node * 2 + 1, ((start + end) >> 1) + 1, end, left, right);
    return left_val + right_val;
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
        tree[node].first += val;
        return;
    }

    update(node * 2, start, ((start + end) >> 1), left, right, val);
    update(node * 2 + 1, ((start + end) >> 1) + 1, end, left, right, val);
}

void update(int node, int start, int end, int index, int val)
{
    if (index < start || end < index)
    {
        return;
    }
    else if (start == end)
    {
        tree[node].second += val;
        return;
    }

    update(node * 2, start, ((start + end) >> 1), index, val);
    update(node * 2 + 1, ((start + end) >> 1) + 1, end, index, val);
    tree[node].second = tree[node * 2].second + tree[node * 2 + 1].second;
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
        cin >> A;
        if (A == 1)
        {
            cin >> B >> C;
            if (dw)
                update(1, 1, N, st[B], en[B], C);
            else
                update(1, 1, N, st[B], C);
        }
        else if (A == 2)
        {
            cin >> B;
            cout << query(1, 1, N, st[B]) + query(1, 1, N, st[B], en[B]) << '\n';
        }
        else
        {
            dw = !dw;
        }
    }
}