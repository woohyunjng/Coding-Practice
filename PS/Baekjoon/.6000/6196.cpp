#include <bits/stdc++.h>
#define int long long

#define MAX 12
#define MOD 100000000
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int A[MAX][MAX], _dp[MAX][MAX][1 << MAX], N, M;

int dp(int X, int Y, int mask) {
    if (X == N)
        return 1;
    if (Y == M)
        return dp(X + 1, 0, mask);
    if (_dp[X][Y][mask] != -1)
        return _dp[X][Y][mask];

    int res = dp(X, Y + 1, mask >> 1);
    if (A[X][Y] && !(mask & 1) && (!Y || !(mask & (1 << M - 1))))
        res = (res + dp(X, Y + 1, (mask >> 1) | (1 << M - 1))) % MOD;
    return _dp[X][Y][mask] = res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> A[i][j];

    fill(&_dp[0][0][0], &_dp[MAX][0][0], -1);

    cout << dp(0, 0, 0) << '\n';

    return 0;
}