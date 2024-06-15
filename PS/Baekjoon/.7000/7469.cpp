#include <bits/stdc++.h>
#define MAX 1001
#define int long long

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

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
        l += N - 1, r += N;
        int val1 = 0, val2 = 0, st = -1000000001, en = 1000000001, mid;
        while (st <= en)
        {
            mid = (st + en) / 2;
            val1 = 0, val2 = 0;
            for (int L = l, R = r; L < R; L >>= 1, R >>= 1)
            {
                if (L & 1)
                {
                    val2 += lower_bound(tree[L].begin(), tree[L].end(), mid) - tree[L].begin();
                    val1 += upper_bound(tree[L].begin(), tree[L].end(), mid) - tree[L].begin(), L++;
                }
                if (R & 1)
                {
                    --R, val2 += lower_bound(tree[R].begin(), tree[R].end(), mid) - tree[R].begin();
                    val1 += upper_bound(tree[R].begin(), tree[R].end(), mid) - tree[R].begin();
                }
            }
            if (val2 < k && k <= val1)
                break;
            else if (k <= val2)
                en = mid - 1;
            else
                st = mid + 1;
        }
        return mid;
    }
    int query(int pos, int k) { return query(pos, pos, k); }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, A, B, C;

    cin >> N >> M;
    MergeSortTree tree(N);
    for (int i = 1; i <= N; i++)
        cin >> tree.arr[i];
    tree.init();

    while (M--)
    {
        cin >> A >> B >> C;
        cout << tree.query(A, B, C) << '\n';
    }

    return 0;
}