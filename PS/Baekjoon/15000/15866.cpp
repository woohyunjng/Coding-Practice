#include <bits/stdc++.h>
#define int long long

#define MAX 300100
using namespace std;

int C[MAX], _dp[MAX][32];
vector<int> adj[MAX];

int dp(int N, int mask) {
    if ((mask & (1 << C[N])) == 0)
        return 0;
    if (_dp[N][mask] != -1)
        return _dp[N][mask];

    int res = 0;
    for (int i : adj[N])
        res += dp(i, mask ^ (1 << C[N]));
    return _dp[N][mask] = res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, K, X, Y, res = 0;
    cin >> N >> M >> K;

    fill(&_dp[0][0], &_dp[N + 1][32], -1);

    for (int i = 1; i <= N; i++)
        cin >> C[i], _dp[i][1 << (--C[i])] = 1;

    while (M--) {
        cin >> X >> Y;
        adj[X].push_back(Y), adj[Y].push_back(X);
    }

    for (int i = 1; i <= N; i++)
        for (int j = 0; j < 32; j++)
            res += dp(i, j);

    cout << res - N << '\n';

    return 0;
}