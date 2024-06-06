#include <iostream>
#define int long long
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, Q, A, B, W;
    cin >> N >> Q;

    int arr[N] = {}, dp[N] = {};
    while (Q--)
    {
        cin >> A >> B >> W;
        dp[--A] += W;
        if (B < N)
            dp[B] -= W;
    }

    arr[0] = dp[0];
    for (int i = 1; i <= N; i++)
        arr[i] = arr[i - 1] + dp[i];

    for (int i = 0; i < N; i++)
        cout << arr[i] << ' ';
}