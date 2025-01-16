#include <bits/stdc++.h>
#define int long long

#define MAX 1100
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;

int val(char X, char Y) { return X == Y ? 2 : -1; }

int dp[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, A, B;
    string X, Y, resX, resY;

    cin >> N >> M >> X >> Y;
    fill(dp[0], dp[0] + MAX * MAX, -INF);
    dp[0][0] = 0;

    for (int i = 1; i <= N; i++)
        dp[i][0] = dp[i - 1][0] - 2;
    for (int i = 1; i <= M; i++)
        dp[0][i] = dp[0][i - 1] - 2;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            dp[i][j] = max({
                dp[i][j - 1] - 2,
                dp[i - 1][j] - 2,
                dp[i - 1][j - 1] + val(X[i - 1], Y[j - 1]),
            });

    A = N, B = M;
    while (A > 0 || B > 0) {
        if (B == 0)
            resX += X[A - 1], resY += '_', A--;
        else if (A == 0)
            resX += '_', resY += Y[B - 1], B--;
        else if (dp[A][B] == dp[A - 1][B - 1] + val(X[A - 1], Y[B - 1]))
            resX += X[A - 1], resY += Y[B - 1], A--, B--;
        else if (dp[A][B] == dp[A][B - 1] - 2)
            resX += '_', resY += Y[B - 1], B--;
        else
            resX += X[A - 1], resY += '_', A--;
    }

    reverse(resX.begin(), resX.end());
    reverse(resY.begin(), resY.end());

    assert(resX.size() == resY.size() && resX.size() <= N + M);

    cout << dp[N][M] << '\n';
    cout << resX << '\n';
    cout << resY << '\n';

    return 0;
}