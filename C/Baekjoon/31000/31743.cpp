#include <bits/stdc++.h>
#define MAX 1000
#define int long long

using namespace std;
typedef pair<int, int> pr;
typedef tuple<int, int, int> tp;

int N, tree[2 * MAX + 1];

void update(int pos, int val)
{
    for (tree[pos += N] = val; pos > 1; pos >>= 1)
        tree[pos >> 1] = tree[pos] + tree[pos ^ 1];
}

int query(int l, int r)
{
    int res = 0;
    for (l += N, r += N; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
            res += tree[l++];
        if (r & 1)
            res += tree[--r];
    }
    return res;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int P, M, A, B, C;
    cin >> P;

    vector<int> Y;
    vector<tp> arr;

    while (P--)
    {
        cin >> A >> B >> C;
        arr.push_back({A, C, 0});
        arr.push_back({B + 1, C, -1});
        Y.push_back(C);
    }

    cin >> M;
    int res[M + 1];

    for (int i = 1; i <= M; i++)
    {
        cin >> A >> B;
        arr.push_back({A, B, i});
        Y.push_back(B);
    }

    sort(arr.begin(), arr.end());
    sort(Y.begin(), Y.end());
    N = Y.size();

    for (tp i : arr)
    {
        if (get<2>(i) == 0)
            update(lower_bound(Y.begin(), Y.end(), get<1>(i)) - Y.begin(), get<1>(i));
        else if (get<2>(i) == -1)
            update(lower_bound(Y.begin(), Y.end(), get<1>(i)) - Y.begin(), 0);
        else
            res[get<2>(i)] = query(0, lower_bound(Y.begin(), Y.end(), get<1>(i)) - Y.begin()) + get<1>(i);
    }

    for (int i = 1; i <= M; i++)
        cout << res[i] << '\n';

    return 0;
}