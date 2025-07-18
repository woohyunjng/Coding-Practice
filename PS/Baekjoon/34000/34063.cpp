#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAX_S = 351;
const int MAX = 81;
const int MOD = 20'150'116;

int S[MAX], dp[MAX][MAX_S], comb[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int X, Y, K, A, B, ans = 0, V;
    string DY;

    cin >> X >> DY;
    Y = (DY[0] - '0') * 1000 + (DY[2] - '0') * 100 + (DY[3] - '0') * 10 + (DY[4] - '0');

    dp[0][0] = 1;
    for (int i = 1; i <= X; i++)
        for (int j = i; j <= i * 4; j++) {
            for (int k = 1; k <= 4 && j - k >= 0; k++)
                dp[i][j] += dp[i - 1][j - k], dp[i][j] %= MOD;
        }

    comb[0][0] = 1;
    for (int i = 1; i <= X; i++)
        for (int j = 0; j <= i; j++) {
            if (j == 0)
                comb[i][j] = 1;
            else
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
        }

    for (int i = 0; i < X; i++)
        for (int j = 0; i + j <= X; j++) {
            A = X - i - j;
            B = (1000 * X - 1 + (Y * X - 1000 * X + j * 1000) * (X - i)) / (1000 * X);

            V = 0;
            for (int k = max(0ll, B); k <= A * 4; k++)
                V += dp[A][k], V %= MOD;

            V *= comb[X][i], V %= MOD;
            V *= comb[X - i][j], V %= MOD;
            ans += V, ans %= MOD;
        }

    cout << ans << '\n';

    return 0;
}