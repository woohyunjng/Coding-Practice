#include <bits/stdc++.h>
#define MAX 300100
#define int long long

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int sub_sum[MAX];

class MergeSortTree
{
public:
    int N, arr[MAX];
    vector<int> tree[2 * MAX + 1];

    MergeSortTree(int n) : N(n) {}

    void init()
    {
        for (int i = 1; i <= N; i++)
            tree[i + N - 1].push_back(arr[i] * 2);

        for (int i = N - 1; i > 0; --i)
        {
            tree[i].resize(tree[i << 1].size() + tree[i << 1 | 1].size());
            merge(tree[i << 1].begin(), tree[i << 1].end(), tree[i << 1 | 1].begin(), tree[i << 1 | 1].end(), tree[i].begin());
        }
    }

    int query(int l, int r)
    {
        int res = LLONG_MAX, k = (arr[l - 1] + arr[r]), x = ceil((double)(r + 2 * l - 2) / 3), y = (2 * r + l - 1) / 3, A;
        l = x, r = y;
        for (l += N - 1, r += N; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
            {
                A = lower_bound(tree[l].begin(), tree[l].end(), k) - tree[l].begin();
                if (A == tree[l].size())
                    res = min(abs(tree[l].back() - k), res);
                else
                {
                    res = min(abs(tree[l][A] - k), res);
                    if (A > 0)
                        res = min(abs(tree[l][A - 1] - k), res);
                }
                l++;
            }
            if (r & 1)
            {
                --r;
                A = lower_bound(tree[r].begin(), tree[r].end(), k) - tree[r].begin();
                if (A == tree[r].size())
                    res = min(abs(tree[r].back() - k), res);
                else
                {
                    res = min(abs(tree[r][A] - k), res);
                    if (A > 0)
                        res = min(abs(tree[r][A - 1] - k), res);
                }
            }
        }
        return res;
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, Q, A, B;

    cin >> N;
    MergeSortTree tree(N);
    for (int i = 1; i <= N; i++)
    {
        cin >> A;
        sub_sum[i] = sub_sum[i - 1] + A;
        tree.arr[i] = sub_sum[i];
    }
    tree.init();

    cin >> Q;
    while (Q--)
    {
        cin >> A >> B;
        cout << tree.query(A, B) << '\n';
    }

    return 0;
}