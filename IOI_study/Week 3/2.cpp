#include <bits/stdc++.h>
#define int long long

using namespace std;

int arr[100100], sum_arr[100100];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, Q, l, r;

    cin >> N >> Q;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
        sum_arr[i] = sum_arr[i - 1] + arr[i];
    }

    while (Q--)
    {
        cin >> l >> r;
        cout << sum_arr[r] - sum_arr[l - 1] << '\n';
    }

    return 0;
}