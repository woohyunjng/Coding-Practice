#include <bits/stdc++.h>
using namespace std;

const int MAX = 10001;
const int INF = 2e9;

int dp[2][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, T, S, E, X, Y, Z;

    cin >> N >> T >> M >> S >> E;

    for (int i = 0; i < N; i++)
        dp[0][i] = INF;
    dp[0][S] = 0;

    for (int i = 1; i <= T; i++) {
        for (int j = 0; j < N; j++)
            dp[i & 1][j] = dp[(i & 1) ^ 1][j];
        for (int j = 1; j <= M; j++) {
            cin >> X >> Y >> Z;
            dp[i & 1][X] = min(dp[i & 1][X], dp[(i & 1) ^ 1][Y] + Z);
            dp[i & 1][Y] = min(dp[i & 1][Y], dp[(i & 1) ^ 1][X] + Z);
        }
    }

    cout << (dp[T & 1][E] == INF ? -1 : dp[T & 1][E]) << '\n';

    return 0;
}