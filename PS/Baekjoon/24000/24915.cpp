#include <iostream>
#include <tuple>
#include <algorithm>
#define MAX 400000
#define MIN_VAL -1000000000
#define MAX_VAL 1000000000

using namespace std;
typedef tuple<int, int, int, int, int> tup;

int arr[MAX];
tup tree[MAX * 4];

tup getMax(tup left, tup right)
{
    return {
        max(get<0>(left), get<0>(right)),
        min(get<1>(left), get<1>(right)),
        max(get<2>(left), max(get<2>(right), get<0>(right) - get<1>(left))),
        max(get<3>(left), max(get<3>(right), get<0>(left) - get<1>(right))),
        max(get<4>(left), max(get<4>(right), max(get<2>(left) - get<1>(right), get<3>(right) - get<1>(left))))};
}

void init(int node, int start, int end)
{
    if (start == end)
        tree[node] = {arr[start], arr[start], MIN_VAL, MIN_VAL, MIN_VAL};
    else
    {
        init(node << 1, start, (start + end) >> 1);
        init((node << 1) + 1, ((start + end) >> 1) + 1, end);
        tree[node] = getMax(tree[node << 1], tree[(node << 1) + 1]);
    }
}

tup query(int node, int start, int end, int left, int right)
{
    if (end < left || right < start)
        return {MIN_VAL, MAX_VAL, MIN_VAL, MIN_VAL, MIN_VAL};
    else if (left <= start && end <= right)
        return tree[node];
    else
    {
        tup leftTree = query(node << 1, start, (start + end) >> 1, left, right);
        tup rightTree = query((node << 1) + 1, ((start + end) >> 1) + 1, end, left, right);
        return getMax(leftTree, rightTree);
    }
}

void update(int node, int start, int end, int index, int value)
{
    if (index < start || end < index)
        return;
    else if (start == end)
        tree[node] = {value, value, MIN_VAL, MIN_VAL, MIN_VAL};
    else
    {
        update(node << 1, start, (start + end) >> 1, index, value);
        update((node << 1) + 1, ((start + end) >> 1) + 1, end, index, value);
        tree[node] = getMax(tree[node << 1], tree[(node << 1) + 1]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, Q, A, B, C;
    cin >> N >> Q;

    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    init(1, 1, N);

    while (Q--)
    {
        cin >> A >> B >> C;
        if (A == 1)
            update(1, 1, N, B, C);
        else
        {
            tup val = query(1, 1, N, B, C);
            cout << get<4>(val) << '\n';
        }
    }
}