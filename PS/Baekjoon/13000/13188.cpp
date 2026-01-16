#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 2001;
const int MOD = 1'000'000'007;

int dp[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, S, E;

    cin >> N >> S >> E;
    if (S > E)
        swap(S, E);

    dp[0][0] = 1;
    for (int i = 1; i < S; i++)
        for (int j = 1; j <= i; j++)
            dp[i][j] = (dp[i - 1][j - 1] * j + dp[i - 1][j + 1] * j) % MOD;
    for (int i = 1; i <= S; i++)
        dp[S][i] = (dp[S - 1][i - 1] + dp[S - 1][i]) % MOD;
    for (int i = S + 1; i < E; i++)
        for (int j = 1; j <= i; j++)
            dp[i][j] = (dp[i - 1][j - 1] * (j - 1) + dp[i - 1][j + 1] * j) % MOD;
    for (int i = 1; i <= E; i++)
        dp[E][i] = (dp[E - 1][i - 1] + dp[E - 1][i]) % MOD;
    for (int i = E + 1; i <= N; i++)
        for (int j = 1; j <= i; j++)
            dp[i][j] = (dp[i - 1][j - 1] * (j - 2) + dp[i - 1][j + 1] * j) % MOD;

    cout << dp[N][1] << '\n';

    return 0;
}