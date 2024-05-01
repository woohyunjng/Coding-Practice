#include <iostream>
#include <algorithm>
#define int long long
using namespace std;

int N, arr[110000], dp[110000], res = -1000;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    dp[0] = arr[0];
    res = max(res, dp[0]);

    for (int i = 1; i < N; i++)
    {
        dp[i] = arr[i] + max(0ll, dp[i - 1]);
        res = max(res, dp[i]);
    }

    cout << res;
}