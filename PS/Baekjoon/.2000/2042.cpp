#include <bits/stdc++.h>
#define MAX 10001
#define int long long

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

class SegTree
{
private:
    void init(int n, int s, int e)
    {
        if (s == e)
            tree[n] = arr[s];
        else
        {
            init(n << 1, s, (s + e) >> 1);
            init(n << 1 | 1, ((s + e) >> 1) + 1, e);
            tree[n] = tree[n << 1] + tree[n << 1 | 1];
        }
    }

    Node query(int n, int s, int e, int l, int r)
    {
        if (l <= s && e <= r)
            return tree[n];
        else if (r < s || e < l)
            return 0;
        else
        {
            Node lv = query(n << 1, s, ((s + e) >> 1), l, r);
            Node rv = query(n << 1 | 1, ((s + e) >> 1) + 1, e, l, r);
            return lv + rv;
        }
    }

    void update(int n, int s, int e, int pos, int val)
    {
        if (pos < s || e < pos)
            return;
        else if (s == e)
        {
            tree[n] = val;
            arr[s] = val;
        }
        else
        {
            update(n << 1, s, (s + e) >> 1, pos, val);
            update(n << 1 | 1, ((s + e) >> 1) + 1, e, pos, val);
            tree[n] = tree[n << 1] + tree[n << 1 | 1];
        }
    }

public:
    int N, arr[MAX];
    Node tree[4 * MAX + 1];

    SegTree(int n) : N(n) {}

    void init() { init(1, 1, N); }
    Node query(int pos) { return query(1, 1, N, pos, pos); }
    Node query(int l, int r) { return query(1, 1, N, l, r); }
    void update(int pos, int val) { update(1, 1, N, pos, val); }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, K, Q, A, B, C;
    cin >> N >> M >> K;

    SegTree tree(N);

    for (int i = 1; i <= N; i++)
        cin >> tree.arr[i];
    tree.init();

    Q = M + K;
    while (Q--)
    {
        cin >> A >> B >> C;
        if (A == 1)
            tree.update(B, C);
        else
            cout << tree.query(B, C).val << '\n';
    }
}
