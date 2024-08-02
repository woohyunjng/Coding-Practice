#include <bits/stdc++.h>
#define int long long
#define MAX 15
#define INF 0x7f7f7f7f7f7f7f7f
#define MOD 9901

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int N, M, dp[MAX][MAX][1 << MAX];

int get_dp(int X, int Y, int mask) {
    if (Y >= M)
        return get_dp(X + 1, Y - M, mask);
    if (X >= N || (X == N - 1 && Y >= M))
        return mask == 0;
    if (dp[X][Y][mask] != -1)
        return dp[X][Y][mask];

    if (mask & 1 << 0)
        return dp[X][Y][mask] = get_dp(X, Y + 1, mask >> 1);

    int res = 0;

    if (Y < M - 1 && !(mask & 1 << 1))
        res = get_dp(X, Y + 2, mask >> 2);
    res = (res + get_dp(X, Y + 1, (mask >> 1) | (1 << (M - 1)))) % MOD;

    return dp[X][Y][mask] = res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;
    fill(&dp[0][0][0], &dp[N][M][1 << M], -1);
    cout << get_dp(0, 0, 0);

    return 0;
}