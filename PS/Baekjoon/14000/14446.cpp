#include <bits/stdc++.h>
#define int long long
#define MAX 101000

using namespace std;

// 비재귀

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

int color[MAX], st[MAX], en[MAX], num = 0;
bool checked[MAX];
vector<int> arr[MAX];

void dfs(int A)
{
    st[A] = ++num;
    for (int i : arr[A])
        dfs(i);
    en[A] = num;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, A;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> color[i];

    for (int i = 2; i <= N; i++)
    {
        cin >> A;
        arr[A].push_back(i);
    }

    dfs(1);

    MergeSortTree tree(N);
    for (int i = 1; i <= N; i++)
        tree.arr[st[i]] = color[i];
    tree.init();

    for (int i = 1; i <= N; i++)
        cout << tree.query(st[i], en[i], color[i]) << '\n';

    return 0;
}