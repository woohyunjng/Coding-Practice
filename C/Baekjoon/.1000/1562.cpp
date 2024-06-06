#include <bits/stdc++.h>
#define int long long
#define MOD 1000000000
using namespace std;

int dp[101][1 << 11][10], N;

int dfs(int K, int vst, int last)
{
    if (K == N)
        return dp[K][vst][last] = (int)(vst == (1 << 10) - 1);

    if (dp[K][vst][last])
        return dp[K][vst][last];

    int res = 0;
    if (K >= 1)
    {
        if (last == 9)
            res = dfs(K + 1, vst | (1 << 8), 8);
        else if (last == 0)
            res = dfs(K + 1, vst | (1 << 1), 1);
        else
        {
            res = dfs(K + 1, vst | (1 << (last - 1)), last - 1);
            res = (res + dfs(K + 1, vst | (1 << (last + 1)), last + 1)) % MOD;
        }
    }
    else
    {
        for (int i = 1; i < 10; i++)
            res = (res + dfs(1, vst | (1 << i), i)) % MOD;
    }
    return dp[K][vst][last] = res;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    cout << dfs(0, 0, 0);
}