#include <iostream>
#include <stack>

typedef unsigned long long int ull;
using namespace std;

ull tree[100001 * 8], MOD = 1000000007;
;
pair<ull, ull> lazy[100001 * 8];

ull arr[100001];
int N;

void init(int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = arr[start];
    }
    else
    {
        init(node * 2, start, (int)((start + end) / 2));
        init(node * 2 + 1, (int)((start + end) / 2) + 1, end);
        tree[node] = (tree[node * 2] + tree[node * 2 + 1]) % MOD;
    }
    lazy[node] = make_pair(1, 0);
}

void update_cal(int node, pair<ull, ull> q)
{
    lazy[node] = make_pair(
        lazy[node].first * q.first % MOD,
        (lazy[node].second * q.first + q.second) % MOD);
}

void lazy_update(int node, int start, int end)
{
    tree[node] = (tree[node] * lazy[node].first) % MOD;
    tree[node] = (tree[node] + lazy[node].second * (end - start + 1)) % MOD;

    update_cal(node * 2, lazy[node]);
    update_cal(node * 2 + 1, lazy[node]);

    lazy[node] = make_pair(1, 0);
}

ull update(int node, int start, int end, int left, int right, pair<ull, ull> q)
{
    lazy_update(node, start, end);
    if (end < left || right < start)
    {
        return tree[node];
    }
    else if (left <= start && end <= right)
    {
        lazy[node] = q;
        lazy_update(node, start, end);
        return tree[node];
    }
    else
    {
        ull left_sum = update(node * 2, start, (int)((start + end) / 2), left, right, q);
        ull right_sum = update(node * 2 + 1, (int)((start + end) / 2) + 1, end, left, right, q);
        tree[node] = (left_sum + right_sum) % MOD;
        return tree[node];
    }
}

ull query(int node, int start, int end, int left, int right)
{
    lazy_update(node, start, end);
    if (left > end || right < start)
    {
        return 0;
    }
    else if (left <= start && end <= right)
    {
        return tree[node];
    }
    else
    {
        ull left_sum = query(node * 2, start, (int)((start + end) / 2), left, right);
        ull right_sum = query(node * 2 + 1, (int)((start + end) / 2) + 1, end, left, right);
        return (left_sum + right_sum) % MOD;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int M, K, a, x, y;
    ull v;

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }
    init(1, 1, N);

    cin >> M;

    for (int i = 0; i < M; i++)
    {
        cin >> a;
        if (a == 4)
        {
            cin >> x >> y;
            cout << query(1, 1, N, x, y) % MOD << '\n';
        }
        else
        {
            cin >> x >> y >> v;
            if (a == 1)
            {
                update(1, 1, N, x, y, make_pair(1, v));
            }
            else if (a == 2)
            {
                update(1, 1, N, x, y, make_pair(v, 0));
            }
            else
            {
                update(1, 1, N, x, y, make_pair(0, v));
            }
        }
    }
}
