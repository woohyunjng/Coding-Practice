#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

pair<int, int> tree[100001 * 4];
int arr[100001], N;
long long int sum_arr[100001] = {};

void init(int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = make_pair(arr[start], start);
    }
    else
    {
        init(node * 2, start, (int)((start + end) / 2));
        init(node * 2 + 1, (int)((start + end) / 2) + 1, end);

        pair<int, int> left = tree[node * 2], right = tree[node * 2 + 1];
        if (left.first <= right.first)
        {
            tree[node] = left;
        }
        else
        {
            tree[node] = right;
        }
    }
}

pair<int, int> query(int node, int start, int end, int left, int right)
{
    if (left > end || right < start)
    {
        return make_pair(1000000001, -1);
    }
    else if (left <= start && end <= right)
    {
        return tree[node];
    }
    else
    {
        pair<int, int> left_min = query(node * 2, start, (int)((start + end) / 2), left, right);
        pair<int, int> right_min = query(node * 2 + 1, (int)((start + end) / 2) + 1, end, left, right);

        if (left_min.first <= right_min.first)
        {
            return left_min;
        }
        else
        {
            return right_min;
        }
    }
}

pair<pair<int, int>, long long int> get_max(int left, int right)
{
    if (right < left)
    {
        return make_pair(make_pair(1, N), 0);
    }

    pair<int, int> min_all = query(1, 1, N, left, right);
    pair<pair<int, int>, long long int> res = make_pair(make_pair(left, right), (sum_arr[right] - sum_arr[left - 1]) * (long long int)min_all.first);

    pair<pair<int, int>, long long int> left_value = get_max(left, min_all.second - 1), right_value = get_max(min_all.second + 1, right);
    if (res.second < left_value.second)
    {
        res = left_value;
    }
    if (res.second < right_value.second)
    {
        res = right_value;
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
        sum_arr[i] = sum_arr[i - 1] + arr[i];
    }

    init(1, 1, N);
    pair<pair<int, int>, long long int> res = get_max(1, N);
    cout << res.second << '\n';
    cout << res.first.first << ' ' << res.first.second;
}
