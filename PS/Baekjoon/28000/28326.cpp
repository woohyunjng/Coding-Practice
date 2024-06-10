#include <bits/stdc++.h>
#define MAX 20000
#define int long long

using namespace std;
typedef pair<int, int> pr;
typedef tuple<int, int, int> tp;

int min(int A, int B)
{
    if (A == 0 && B == 0)
        return 0;
    else if (A == 0)
        return B;
    else if (B == 0)
        return A;
    return A > B ? B : A;
}

class Node
{
public:
    int val = 0;
    Node() {}
    Node(int v) : val(v) {}
    Node operator+(Node &ref) { return Node(min(val, ref.val)); }
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

    int N, M, s, e, t, a, b;
    cin >> N >> M;

    vector<tp> meat, human;
    vector<int> X;
    int res[M + 1] = {};

    while (N--)
    {
        cin >> s >> e >> t;
        meat.push_back({s, e, t});
        X.push_back(s);
        X.push_back(e);
    }

    for (int i = 1; i <= M; i++)
    {
        cin >> a >> b;
        human.push_back({i, a, b});
        X.push_back(a);
        X.push_back(b);
    }

    sort(X.begin(), X.end());
    X.erase(unique(X.begin(), X.end()), X.end());
    int K = X.size();

    SegTree start(K), end(K);

    for (int i = 0; i < M; i++)
    {
        int a = lower_bound(X.begin(), X.end(), get<1>(human[i])) - X.begin() + 1,
            b = lower_bound(X.begin(), X.end(), get<2>(human[i])) - X.begin() + 1;
        start.arr[a] = min(start.arr[a], i + 1);
        end.arr[b] = min(end.arr[b], i + 1);
    }
    start.init();
    end.init();

    for (tp i : meat)
    {
        int s = lower_bound(X.begin(), X.end(), get<0>(i)) - X.begin() + 1, e = lower_bound(X.begin(), X.end(), get<1>(i)) - X.begin() + 1, t = get<2>(i);
        int left = start.query(s, e - 1).val, right = end.query(s, e - 1).val;
        if (!left || !right)
            continue;
        if (left == right)
            res[left] += t;
    }

    for (int i = 1; i <= M; i++)
        cout << res[i] << '\n';
}