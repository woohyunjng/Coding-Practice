#include <iostream>
#include <algorithm>
#include <tuple>
#define MAX 100001
#define MIN_I -1000000000
#define MAX_I 1000000000

using namespace std;
typedef tuple<int, int, int> tp;

int arr[MAX];
tp tree[MAX * 4];

tp get(tp A, tp B)
{
    int mn = min(get<0>(A), get<0>(B)), mx = max(get<1>(A), get<1>(B));
    return {mn, mx, max(get<1>(B) - get<0>(A), max(get<2>(A), get<2>(B)))};
}

void init(int node, int start, int end)
{
    if (start == end)
        tree[node] = {arr[start], arr[start], 0};
    else
    {
        init(node << 1, start, (start + end) >> 1);
        init((node << 1) + 1, ((start + end) >> 1) + 1, end);
        tree[node] = get(tree[node << 1], tree[(node << 1) + 1]);
    }
}

tp query(int node, int start, int end, int left, int right)
{
    if (right < start || end < left)
        return {MAX_I, MIN_I, 0};
    else if (left <= start && end <= right)
        return tree[node];
    else
    {
        tp left_val = query(node << 1, start, (start + end) >> 1, left, right);
        tp right_val = query((node << 1) + 1, ((start + end) >> 1) + 1, end, left, right);
        return get(left_val, right_val);
    }
}

void update(int node, int start, int end, int index, int val)
{
    if (index < start || end < index)
        return;
    else if (start == end)
        tree[node] = {val, val, 0};
    else
    {
        update(node << 1, start, (start + end) >> 1, index, val);
        update((node << 1) + 1, ((start + end) >> 1) + 1, end, index, val);
        tree[node] = get(tree[node << 1], tree[(node << 1) + 1]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, Q, A, B, C;
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    init(1, 0, N - 1);

    cin >> Q;
    while (Q--)
    {
        cin >> A >> B >> C;
        if (A == 1)
            update(1, 0, N - 1, B - 1, C);
        else
            cout << get<2>(query(1, 0, N - 1, B - 1, C - 1)) << '\n';
    }
}