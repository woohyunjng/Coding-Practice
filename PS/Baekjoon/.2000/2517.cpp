#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 5001
using namespace std;

int tree[MAX * 4] = {};

void update(int node, int start, int end, int index)
{
    if (index < start || end < index)
        return;
    else if (start == end)
    {
        tree[node] = 1;
        return;
    }

    update(node * 2, start, (start + end) >> 1, index);
    update(node * 2 + 1, ((start + end) >> 1) + 1, end, index);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int node, int start, int end, int left, int right)
{
    if (left <= start && end <= right)
        return tree[node];
    else if (end < left || right < start)
        return 0;

    int left_sum = query(node * 2, start, (start + end) >> 1, left, right);
    int right_sum = query(node * 2 + 1, ((start + end) >> 1) + 1, end, left, right);
    return left_sum + right_sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    vector<int> cleared(arr);
    sort(cleared.begin(), cleared.end());
    cleared.erase(unique(cleared.begin(), cleared.end()), cleared.end());

    for (int i = 0; i < N; i++)
    {
        auto it = lower_bound(cleared.begin(), cleared.end(), arr[i]);
        int k = distance(cleared.begin(), it);

        update(1, 0, N - 1, k);
        cout << query(1, 0, N - 1, k, N) << '\n';
    }
}