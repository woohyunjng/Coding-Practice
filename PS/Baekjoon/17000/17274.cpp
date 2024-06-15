#include <bits/stdc++.h>
#define int long long
#define MAX 1000100

using namespace std;

class MergeSortTree
{
public:
    int N, arr[MAX];
    vector<int> tree[2 * MAX + 1];

    MergeSortTree(int n) : N(n) {}

    void init()
    {
        for (int i = 1; i <= N; i++)
            tree[i + N - 1].push_back(arr[i]);

        for (int i = N - 1; i > 0; --i)
        {
            tree[i].resize(tree[i << 1].size() + tree[i << 1 | 1].size());
            merge(tree[i << 1].begin(), tree[i << 1].end(), tree[i << 1 | 1].begin(), tree[i << 1 | 1].end(), tree[i].begin());
        }
    }

    int query(int l, int r, int k)
    {
        int res = 0;
        k--;
        for (l += N - 1, r += N; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                res += tree[l].end() - upper_bound(tree[l].begin(), tree[l].end(), k), l++;
            if (r & 1)
                --r, res += tree[r].end() - upper_bound(tree[r].begin(), tree[r].end(), k);
        }
        return res;
    }
    int query(int pos, int k) { return query(pos, pos, k); }
};

class SegTree
{
public:
    int N, arr[MAX];
    int tree[2 * MAX + 1];

    SegTree(int n) : N(n) {}

    void init()
    {
        for (int i = 1; i <= N; i++)
            tree[i + N - 1] = arr[i];

        for (int i = N - 1; i > 0; --i)
            tree[i] = max(tree[i << 1], tree[i << 1 | 1]);
    }
    int query(int l, int r)
    {
        int res = 0;
        for (l += N - 1, r += N; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                res = max(res, tree[l++]);
            if (r & 1)
                res = max(res, tree[--r]);
        }
        return res;
    }
};

int A[MAX], B[MAX];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, K, X, Y, cnt, res = 0;
    vector<int> arr;
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        cin >> A[i] >> B[i];
        arr.push_back(A[i]), arr.push_back(A[i] - 1), arr.push_back(B[i]), arr.push_back(B[i] - 1);
    }

    MergeSortTree tree(M);
    for (int i = 1; i <= M; i++)
    {
        cin >> tree.arr[i];
        arr.push_back(tree.arr[i]);
    }
    tree.init();

    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    SegTree max_tree(arr.size());
    for (int i = 1; i <= M; i++)
        max_tree.arr[lower_bound(arr.begin(), arr.end(), tree.arr[i]) - arr.begin() + 1] = i;
    max_tree.init();

    for (int i = 1; i <= N; i++)
    {
        X = max(A[i], B[i]), Y = min(A[i], B[i]);
        K = max_tree.query(
            lower_bound(arr.begin(), arr.end(), Y) - arr.begin() + 1,
            lower_bound(arr.begin(), arr.end(), X - 1) - arr.begin() + 1);
        cnt = tree.query(K + 1, M, X);
        if (K == 0)
        {
            if (cnt % 2)
                res += B[i];
            else
                res += A[i];
        }
        else
        {
            if (A[i] > B[i])
                swap(A[i], B[i]);
            if (cnt % 2)
                res += A[i];
            else
                res += B[i];
        }
    }
    cout << res;

    return 0;
}