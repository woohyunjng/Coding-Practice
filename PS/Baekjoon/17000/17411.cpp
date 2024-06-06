#include <iostream>
#include <algorithm>
#define MAX_INT 1000001
#define MOD 1000000007

using namespace std;
typedef pair<int, long long int> node;

node tree[MAX_INT * 4] = {(node){0, 0}}, mx;

node add_node(node A, node B)
{
    if (A.first != B.first)
        return A > B ? A : B;
    else
    {
        return (node){A.first, (A.second + B.second) % MOD};
    }
}

node query(int nd, int start, int end, int left, int right)
{
    if (end < left || right < start)
    {
        return (node){0, 0};
    }
    else if (left <= start && end <= right)
    {
        return tree[nd];
    }

    return add_node(
        query(nd * 2, start, (start + end) >> 1, left, right),
        query(nd * 2 + 1, ((start + end) >> 1) + 1, end, left, right));
}

void update(int nd, int start, int end, int index, node value)
{
    if (index < start || end < index)
        return;
    else if (start == end)
    {
        tree[nd] = add_node(tree[nd], value);
        return;
    }

    update(nd * 2, start, (start + end) >> 1, index, value);
    update(nd * 2 + 1, ((start + end) >> 1) + 1, end, index, value);
    tree[nd] = add_node(tree[nd * 2], tree[nd * 2 + 1]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    pair<int, int> arr[N];

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i].first;
        arr[i].second = i;
    }

    sort(arr, arr + N, [](pair<int, int> A, pair<int, int> B) -> bool
         {
        if (A.first != B.first)
            return A.first < B.first;
        else
            return A.second > B.second; });

    for (int i = 0; i < N; i++)
    {
        if (arr[i].second)
            mx = query(1, 0, N - 1, 0, arr[i].second - 1);
        else
            mx = {0, (long long int)0};
        update(1, 0, N - 1, arr[i].second, (node){mx.first + 1, max(mx.second, (long long int)1)});
    }

    cout << tree[1].first << ' ' << tree[1].second;
}