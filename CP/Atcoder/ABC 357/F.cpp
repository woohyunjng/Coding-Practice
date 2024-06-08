#include <bits/stdc++.h>
#define int long long
#define MOD 998244353
#define MAX 200100

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> Node;

Node tree[MAX * 4];
Node lazy[MAX * 4] = {};
Node arr[MAX];
int N;

Node M(Node A, Node B) { return {(A[0] + B[0]) % MOD, (A[1] + B[1]) % MOD, (A[2] + B[2]) % MOD}; }

void init(int node, int start, int end)
{
    if (start == end)
        tree[node] = arr[start];
    else
    {
        init(node << 1, start, (start + end) >> 1);
        init(node << 1 | 1, ((start + end) >> 1) + 1, end);
        tree[node] = M(tree[node << 1], tree[node << 1 | 1]);
    }
}

void lazy_update(int node, int start, int end)
{
    tree[node][2] = (tree[node][2] + lazy[node][1] * tree[node][0] % MOD + lazy[node][0] * tree[node][1] % MOD + (lazy[node][0] * lazy[node][1] % MOD) * (end - start + 1) % MOD) % MOD;
    tree[node][0] = (tree[node][0] + lazy[node][0] * (end - start + 1) % MOD) % MOD;
    tree[node][1] = (tree[node][1] + lazy[node][1] * (end - start + 1) % MOD) % MOD;

    if (start != end)
    {
        lazy[node << 1] = M(lazy[node << 1], lazy[node]);
        lazy[node << 1 | 1] = M(lazy[node << 1 | 1], lazy[node]);
    }
    lazy[node] = {0, 0, 0};
}

void update(int node, int start, int end, int left, int right, Node value)
{
    lazy_update(node, start, end);
    if (right < start || end < left)
        return;
    else if (left <= start && end <= right)
    {
        lazy[node] = M(lazy[node], value);
        lazy_update(node, start, end);
    }
    else
    {
        update(node << 1, start, (start + end) >> 1, left, right, value);
        update(node << 1 | 1, ((start + end) >> 1) + 1, end, left, right, value);
        tree[node] = M(tree[node << 1], tree[node << 1 | 1]);
    }
}

Node query(int node, int start, int end, int left, int right)
{
    lazy_update(node, start, end);
    if (left <= start && end <= right)
        return tree[node];
    else if (right < start || end < left)
        return {0, 0, 0};
    else
    {
        Node left_val = query(node << 1, start, ((start + end) >> 1), left, right);
        Node right_val = query(node << 1 | 1, ((start + end) >> 1) + 1, end, left, right);
        return M(left_val, right_val);
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, Q, t, l, r, x;
    cin >> N >> Q;

    for (int i = 1; i <= N; i++)
        cin >> arr[i][0];
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i][1];
        arr[i][2] = arr[i][0] * arr[i][1] % MOD;
    }

    init(1, 1, N);

    while (Q--)
    {
        cin >> t >> l >> r;
        if (t == 1)
        {
            cin >> x;
            update(1, 1, N, l, r, {x, 0, 0});
        }
        else if (t == 2)
        {
            cin >> x;
            update(1, 1, N, l, r, {0, x, 0});
        }
        else if (t == 3)
            cout << query(1, 1, N, l, r)[2] << '\n';
    }

    return 0;
}