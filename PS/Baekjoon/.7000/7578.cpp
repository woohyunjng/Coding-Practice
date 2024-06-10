#include <bits/stdc++.h>
#define int long long
#define MAX 5001

using namespace std;
typedef pair<int, int> pr;
typedef tuple<int, int, int> tp;

class Node
{
public:
    int val = 0;
    Node() {}
    Node(int v) : val(v) {}
    Node operator+(Node &ref)
    {
        return Node(val + ref.val);
    }
};

// 비재귀

class SegTree
{
public:
    int N, arr[MAX];
    Node tree[2 * MAX + 1];

    SegTree(int n) : N(n) {}

    void init()
    {
        for (int i = 1; i <= N; i++)
            tree[i + N - 1].val = arr[i];

        for (int i = N - 1; i > 0; --i)
            tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }
    Node query(int l, int r)
    {
        Node res;
        for (l += N - 1, r += N; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                res = res + tree[l++];
            if (r & 1)
                res = res + tree[--r];
        }
        return res;
    }
    Node query(int pos) { return query(pos, pos); }
    void update(int pos, int val)
    {
        for (tree[pos += N - 1] = val; pos > 1; pos >>= 1)
            tree[pos >> 1] = tree[pos] + tree[pos ^ 1];
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, A, res = 0;
    cin >> N;

    map<int, int> mp;
    vector<int> arr(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> arr[i];
    for (int i = 1; i <= N; i++)
    {
        cin >> A;
        mp[A] = i;
    }

    SegTree tree(N);
    for (int i = 1; i <= N; i++)
    {
        tree.update(mp[arr[i]], 1);
        res += tree.query(mp[arr[i]] + 1, N).val;
    }
    cout << res;

    return 0;
}