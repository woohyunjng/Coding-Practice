#include <bits/stdc++.h>
#define MOD 1000000007
#define int unsigned long long

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

unordered_map<int, int> dp;

bool exists(int N) { return dp.find(N) != dp.end(); }

int get_fibo(int N)
{
    if (!N || exists(N))
        return dp[N];
    else if (exists(N - 1) && exists(N - 2))
    {
        dp[N] = (dp[N - 1] + dp[N - 2]) % MOD;
        return dp[N];
    }
    else if (N % 2 == 0)
    {
        dp[N / 2 + 1] = get_fibo(N / 2 + 1);
        dp[N / 2 - 1] = get_fibo(N / 2 - 1);
        dp[N] = (dp[N / 2 + 1] * dp[N / 2 + 1] % MOD - dp[N / 2 - 1] * dp[N / 2 - 1] % MOD + MOD * 2) % MOD;
        return dp[N];
    }
    else
    {
        dp[N / 2 + 1] = get_fibo(N / 2 + 1);
        dp[N / 2] = get_fibo(N / 2);
        dp[N] = (dp[N / 2 + 1] * dp[N / 2 + 1] % MOD + dp[N / 2] * dp[N / 2] % MOD) % MOD;
        return dp[N];
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    dp[0] = 0, dp[1] = 1, dp[2] = 1;

    cin >> N;
    cout << get_fibo(N + 1);

    return 0;
}