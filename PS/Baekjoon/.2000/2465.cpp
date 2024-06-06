#include <bits/stdc++.h>
#define int long long
#define MAX 1000000

using namespace std;
typedef pair<int, int> pr;
typedef tuple<int, int, int> tp;

int N, tree[4 * MAX + 1], arr[MAX];

int M(int a, int b) { return a + b; }
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

int query(int node, int start, int end, int value)
{
    if (start == end)
        return start;
    else if (value <= tree[node << 1])
        return query(node << 1, start, (start + end) >> 1, value);
    else
        return query(node << 1 | 1, ((start + end) >> 1) + 1, end, value - tree[node << 1]);
}

void update(int node, int start, int end, int index, int value)
{
    if (index < start || end < index)
        return;
    else if (start == end)
        tree[node] += value;
    else
    {
        update(node << 1, start, (start + end) >> 1, index, value);
        update(node << 1 | 1, ((start + end) >> 1) + 1, end, index, value);
        tree[node] = M(tree[node << 1], tree[node << 1 | 1]);
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int M;
    cin >> M;
    vector<int> V(M), S(M), res(M);
    for (int i = 0; i < M; i++)
        cin >> V[i];

    sort(V.begin(), V.end());
    vector<int> X(V);

    V.erase(unique(V.begin(), V.end()), V.end());
    N = V.size();
    for (int i : V)
        arr[lower_bound(V.begin(), V.end(), i) - V.begin()] = upper_bound(X.begin(), X.end(), i) - lower_bound(X.begin(), X.end(), i);
    init(1, 0, N - 1);

    for (int i = 0; i < M; i++)
        cin >> S[i];

    for (int i = M - 1; i >= 0; i--)
    {
        int k = query(1, 0, N - 1, S[i] + 1);
        update(1, 0, N - 1, k, -1);
        res[i] = V[k];
    }

    for (int i = 0; i < M; i++)
        cout << res[i] << '\n';
    return 0;
}