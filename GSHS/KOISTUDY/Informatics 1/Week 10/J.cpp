#include <bits/stdc++.h>
#define MOD 1000000007
#define int long long

using namespace std;

int dp[2000][2000];

int get(int N, int K)
{
    if (N < K)
        return 0;
    if (dp[N][K])
        return dp[N][K];
    if (N == 1 || K == 1 || N == K)
        return 1;
    return dp[N][K] = (K * get(N - 1, K) % MOD + get(N - 1, K - 1) % MOD) % MOD;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K;
    cin >> N >> K;

    cout << get(N, K);

    return 0;
}