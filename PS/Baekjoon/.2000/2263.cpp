#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef pair<int, int> pr;
typedef tuple<int, int, int> tp;

int arr[100100], in[100100], post[100100];

void get_order(int in_start, int in_end, int post_start, int post_end)
{
    if (in_start > in_end || post_start > post_end)
        return;

    int root = arr[post[post_end]];
    cout << in[root] << ' ';

    int K = root - in_start;
    get_order(in_start, root - 1, post_start, post_start + K - 1);
    get_order(root + 1, in_end, post_start + K, post_end - 1);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> in[i];
        arr[in[i]] = i;
    }

    for (int i = 1; i <= N; i++)
        cin >> post[i];

    get_order(1, N, 1, N);
    return 0;
}