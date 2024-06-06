#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <cstring>
#define MAX 200000

using namespace std;
typedef tuple<int, int, int> tp;
typedef pair<int, int> pr;

int tree[2][MAX * 4];
int arr[2][MAX];

int min(int a, int b)
{
    if (a == 0 && b == 0)
        return 0;
    else if (a == 0)
        return b;
    else if (b == 0)
        return a;
    return a > b ? b : a;
}

void init(int ty, int node, int start, int end)
{
    if (start == end)
        tree[ty][node] = arr[ty][start];
    else
    {
        init(ty, node << 1, start, (start + end) >> 1);
        init(ty, (node << 1) + 1, ((start + end) >> 1) + 1, end);
        tree[ty][node] = min(
            tree[ty][node << 1],
            tree[ty][(node << 1) + 1]);
    }
}

int query(int ty, int node, int start, int end, int left, int right)
{
    if (left <= start && end <= right)
        return tree[ty][node];
    else if (right < start || end < left)
        return 0;
    else
    {
        int left_val = query(ty, node << 1, start, ((start + end) >> 1), left, right);
        int right_val = query(ty, (node << 1) + 1, ((start + end) >> 1) + 1, end, left, right);
        return min(left_val, right_val);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(tree, 0, sizeof(tree));
    memset(arr, 0, sizeof(arr));

    int N, M, s, e, t, a, b;
    cin >> N >> M;

    vector<tp> meat, human;
    vector<int> X;
    long long res[M + 1] = {};

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

    for (int i = 0; i < M; i++)
    {
        int a = lower_bound(X.begin(), X.end(), get<1>(human[i])) - X.begin(),
            b = lower_bound(X.begin(), X.end(), get<2>(human[i])) - X.begin();
        arr[0][a] = min(arr[0][a], i + 1);
        arr[1][b] = min(arr[1][b], i + 1);
    }
    init(0, 1, 0, K - 1);
    init(1, 1, 0, K - 1);

    for (tp i : meat)
    {
        int s = lower_bound(X.begin(), X.end(), get<0>(i)) - X.begin(), e = lower_bound(X.begin(), X.end(), get<1>(i)) - X.begin(), t = get<2>(i);
        int left = query(0, 1, 0, K - 1, s, e - 1), right = query(1, 1, 0, K - 1, s, e - 1);
        if (!left || !right)
            continue;
        if (left == right)
            res[left] += t;
    }

    for (int i = 1; i <= M; i++)
        cout << res[i] << '\n';
}