
#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

pair<int, int> tree[100001 * 4];
int arr[100001], N;

void init(int node, int start, int end) {
    if (start == end) {
        tree[node] = make_pair(arr[start], start);
    } else {
        init(node * 2, start, (int)((start + end) / 2));
        init(node * 2 + 1, (int)((start + end) / 2) + 1, end);

        pair<int, int> left = tree[node * 2], right = tree[node * 2 + 1];
        if (left.first <= right.first) {
            tree[node] = left;
        } else {
            tree[node] = right;
        }
    }
}

pair<int, int> query(int node, int start, int end, int left, int right) {
    if (left > end || right < start) {
        return make_pair(1000000001, -1);
    } else if (left <= start && end <= right) {
        return tree[node];
    } else {
        pair<int, int> left_min = query(node * 2, start, (int)((start + end) / 2), left, right);
        pair<int, int> right_min = query(node * 2 + 1, (int)((start + end) / 2) + 1, end, left, right);

        if (left_min.first <= right_min.first) {
            return left_min;
        } else {
            return right_min;
        }
    }
}

int get_max(int left, int right) {
    if (right < left) {
        return 0;
    }

    pair<int, int> min_all = query(1, 0, N - 1, left, right);
    int res = (right - left + 1) * min_all.first;

    res = max(res, get_max(left, min_all.second - 1));
    res = max(res, get_max(min_all.second + 1, right));

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    for (int i = 0 ; i < N ; i ++) {
        cin >> arr[i];
    }

    init(1, 0, N - 1);
    cout << get_max(0, N - 1) << '\n';
}
