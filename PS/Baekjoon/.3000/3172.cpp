#include <bits/stdc++.h>
#define int long long
#define MAX 1000000

using namespace std;
typedef pair<string, int> pr;
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

    cin >> N;
    int index[N], res = 0;
    vector<pr> arr(N), reversed_arr(N);
    string k;

    for (int i = 0; i < N; i++)
    {
        cin >> k;
        arr[i] = {k, i};
        reverse(k.begin(), k.end());
        reversed_arr[i] = {k, i};
    }

    sort(arr.begin(), arr.end());
    sort(reversed_arr.begin(), reversed_arr.end());

    for (int i = 0; i < N; i++)
        index[reversed_arr[i].second] = i;

    for (pr i : arr)
    {
        update(index[i.second], 1);
        res += query(index[i.second] + 1, N);
    }
    cout << res;

    return 0;
}