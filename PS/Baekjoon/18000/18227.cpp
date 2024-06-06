#include <iostream>
#include <vector>
#define MAX 200001
using namespace std;

vector<int> arr[MAX];
int st[MAX], en[MAX], depth[MAX] = {}, num = 0;
long long int tree[MAX * 4] = {};
bool checked[MAX] = {};

void dfs(int A)
{
    checked[A] = true;
    st[A] = ++num;

    for (int B : arr[A])
    {
        if (!checked[B])
        {
            depth[B] = depth[A] + 1;
            dfs(B);
        }
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

long long int query(int node, int start, int end, int left, int right)
{
    if (right < start || end < left)
    {
        return 0;
    }
    else if (left <= start && end <= right)
    {
        return tree[node];
    }

    long long int left_val = query(node * 2, start, ((start + end) >> 1), left, right);
    long long int right_val = query(node * 2 + 1, ((start + end) >> 1) + 1, end, left, right);
    return left_val + right_val;
}

void update(int node, int start, int end, int index)
{
    if (index < start || end < index)
    {
        return;
    }
    else if (start == end)
    {
        tree[node]++;
        return;
    }

    update(node * 2, start, ((start + end) >> 1), index);
    update(node * 2 + 1, ((start + end) >> 1) + 1, end, index);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, C, Q, A, B;
    cin >> N >> C;

    for (int i = 0; i < N - 1; i++)
    {
        cin >> A >> B;
        arr[A].push_back(B);
        arr[B].push_back(A);
    }

    depth[C] = 1;
    dfs(C);
    init(1, 1, N);

    cin >> Q;
    while (Q--)
    {
        cin >> A >> B;
        if (A == 1)
        {
            update(1, 1, N, st[B]);
        }
        else
        {
            cout << query(1, 1, N, st[B], en[B]) * depth[B] << '\n';
        }
    }
}