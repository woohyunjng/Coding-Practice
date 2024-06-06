#include <bits/stdc++.h>
#define int long long

using namespace std;

int dp[100];

int fib(int N)
{
    if (dp[N])
        return dp[N];
    return dp[N] = fib(N - 1) + fib(N - 2);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    dp[1] = 1, dp[2] = 1;
    cout << fib(N);

    return 0;
}