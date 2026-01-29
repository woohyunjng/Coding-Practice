#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

const int MAX = 401;
const int INF = 1e9;

int A[MAX], S[MAX][3], P[MAX][3], dp[MAX][MAX][MAX][3];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, Y, Z, ans;
    string _S;

    cin >> N >> _S;
    for (int i = 1; i <= N; i++) {
        if (_S[i - 1] == 'R')
            A[i] = 0;
        else if (_S[i - 1] == 'G')
            A[i] = 1;
        else
            A[i] = 2;

        S[i][A[i]]++;
        for (int j = 0; j < 3; j++)
            S[i][j] += S[i - 1][j];
        P[S[i][A[i]]][A[i]] = i;
    }

    for (int i = 0; i <= N; i++)
        for (int j = 0; j <= N; j++)
            for (int k = 0; k <= N; k++)
                fill(dp[i][j][k], dp[i][j][k] + 3, INF);
    dp[0][0][0][0] = dp[0][0][0][1] = dp[0][0][0][2] = 0;

    for (int i = 1; i <= N; i++)
        for (int j = 0; j <= min(i, S[N][0]); j++)
            for (int k = 0; k <= min(i - j, S[N][1]); k++) {
                X = i - j - k;
                if (X > S[N][2])
                    continue;

                for (int x = 0; x < 3; x++) {
                    if (x == 0 && j == 0)
                        continue;
                    if (x == 1 && k == 0)
                        continue;
                    if (x == 2 && X == 0)
                        continue;
                    if (x == 0)
                        Z = P[j][x];
                    else if (x == 1)
                        Z = P[k][x];
                    else if (x == 2)
                        Z = P[X][x];
                    Y = max(S[Z][0] - j, 0) + max(S[Z][1] - k, 0) + max(S[Z][2] - X, 0);
                    for (int y = 0; y < 3; y++) {
                        if (x == y)
                            continue;
                        if (x == 0)
                            dp[i][j][k][x] = min(dp[i][j][k][x], dp[i - 1][j - 1][k][y]);
                        else if (x == 1)
                            dp[i][j][k][x] = min(dp[i][j][k][x], dp[i - 1][j][k - 1][y]);
                        else if (x == 2)
                            dp[i][j][k][x] = min(dp[i][j][k][x], dp[i - 1][j][k][y]);
                    }
                    dp[i][j][k][x] += Y, dp[i][j][k][x] = min(dp[i][j][k][x], INF);
                }
            }

    ans = min({dp[N][S[N][0]][S[N][1]][0], dp[N][S[N][0]][S[N][1]][1], dp[N][S[N][0]][S[N][1]][2]});
    if (ans == INF)
        ans = -1;
    cout << ans << '\n';
}