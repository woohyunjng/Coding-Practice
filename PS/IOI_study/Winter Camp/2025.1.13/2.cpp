#include <bits/stdc++.h>
#define int long long

#define MAX 21
#define INF 40000000000

using namespace std;

int N, _dp[MAX][1 << MAX], W[MAX][MAX];

int dp(int K, int mask) {
    if (_dp[K][mask] != -1)
        return _dp[K][mask];

    int res = INF;
    if (mask == (1 << N) - 1)
        return _dp[K][mask] = W[K][0];

    for (int i = 0; i < N; i++) {
        if (mask & (1 << i))
            continue;
        res = min(res, dp(i, mask | (1 << i)) + W[K][i]);
    }

    return _dp[K][mask] = res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> W[i][j], W[i][j] = W[i][j] ? W[i][j] : INF;

    memset(_dp, -1, sizeof(_dp));
    cout << dp(0, 1) << '\n';

    return 0;
}