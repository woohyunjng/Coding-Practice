#include <bits/stdc++.h>
#define int long long

#define MAX 110
#define MOD 1000001
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int dp[MAX][MAX][MAX];

int get_dp(int N, int M, int K) {
    if (N < 0 || M < 0 || K < 0)
        return 0;
    if (dp[N][M][K] != -1)
        return dp[N][M][K];

    if (K == 0)
        return dp[N][M][K] = 1;
    else if (K == 1)
        return dp[N][M][K] = N * M;
    else if (N * M == 0)
        return dp[N][M][K] = 0;

    int res = 0;

    res = (res + get_dp(N - 1, M, K)) % MOD;
    res = (res + M * get_dp(N - 1, M - 1, K - 1)) % MOD;
    res = (res + M * (N - 1) * get_dp(N - 2, M - 1, K - 2)) % MOD;
    res = (res + M * (M - 1) / 2 * get_dp(N - 1, M - 2, K - 2)) % MOD;

    return dp[N][M][K] = res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, K;
    cin >> N >> M >> K;

    fill(&dp[0][0][0], &dp[MAX][0][0], -1);

    cout << get_dp(N, M, K);

    return 0;
}