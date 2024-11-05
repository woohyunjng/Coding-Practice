#include <bits/stdc++.h>
#define int long long

#define MAX 310
#define MAX_DIG 20
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int D[MAX], A[2][MAX_DIG], B[2], dp[2][MAX_DIG][MAX_DIG][3], ans[MAX][MAX][2];

int comp(int X, int Y) { return (X < Y) ? 0 : ((X == Y) ? 1 : 2); }

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, L, R, X;
    string S;

    cin >> N;

    assert(N <= 300);

    for (int i = 0; i < 2; i++) {
        cin >> X;
        X -= (i == 0);

        S = to_string(X);
        B[i] = S.size();

        for (int j = 1; j <= B[i]; j++)
            A[i][j] = S[j - 1] - '0';
    }

    for (int i = 1; i <= N; i++)
        cin >> D[i];

    for (int k = 0; k < 2; k++) {
        for (int i = 1; i <= N; i++) {
            fill(&dp[0][0][0][0], &dp[2][0][0][0], 0);
            for (int j = i; j <= N; j++) {
                for (int x = 1; x <= B[k]; x++) {
                    dp[j & 1][x][x][0] = dp[(j & 1) ^ 1][x][x][0], dp[j & 1][x][x][1] = dp[(j & 1) ^ 1][x][x][1], dp[j & 1][x][x][2] = dp[(j & 1) ^ 1][x][x][2];
                    dp[j & 1][x][x][comp(D[j], A[k][x])] = dp[j & 1][x][x][comp(D[j], A[k][x])] + 2;
                }

                for (int x = 1; x <= B[k]; x++)
                    for (int y = x + 1; y <= B[k]; y++) {
                        dp[j & 1][x][y][0] = dp[(j & 1) ^ 1][x][y][0], dp[j & 1][x][y][1] = dp[(j & 1) ^ 1][x][y][1], dp[j & 1][x][y][2] = dp[(j & 1) ^ 1][x][y][2];
                        if (D[j] > A[k][x])
                            dp[j & 1][x][y][2] = (dp[j & 1][x][y][2] + dp[(j & 1) ^ 1][x + 1][y][0] + dp[(j & 1) ^ 1][x + 1][y][1] + dp[(j & 1) ^ 1][x + 1][y][2]) % MOD;
                        else if (D[j] == A[k][x])
                            dp[j & 1][x][y][2] = (dp[j & 1][x][y][2] + dp[(j & 1) ^ 1][x + 1][y][2]) % MOD, dp[j & 1][x][y][1] = (dp[j & 1][x][y][1] + dp[(j & 1) ^ 1][x + 1][y][1]) % MOD, dp[j & 1][x][y][0] = (dp[j & 1][x][y][0] + dp[(j & 1) ^ 1][x + 1][y][0]) % MOD;
                        else
                            dp[j & 1][x][y][0] = (dp[j & 1][x][y][0] + dp[(j & 1) ^ 1][x + 1][y][0] + dp[(j & 1) ^ 1][x + 1][y][1] + dp[(j & 1) ^ 1][x + 1][y][2]) % MOD;

                        dp[j & 1][x][y][2] = (dp[j & 1][x][y][2] + dp[(j & 1) ^ 1][x][y - 1][2]) % MOD;
                        dp[j & 1][x][y][0] = (dp[j & 1][x][y][0] + dp[(j & 1) ^ 1][x][y - 1][0]) % MOD;
                        dp[j & 1][x][y][comp(D[j], A[k][y])] = (dp[j & 1][x][y][comp(D[j], A[k][y])] + dp[(j & 1) ^ 1][x][y - 1][1]) % MOD;
                    }

                for (int x = 1; x <= B[k]; x++) {
                    ans[i][j][k] = (ans[i][j][k] + dp[j & 1][x][B[k]][0] + dp[j & 1][x][B[k]][1]) % MOD;
                    if (x > 1)
                        ans[i][j][k] = (ans[i][j][k] + dp[j & 1][x][B[k]][2]) % MOD;
                }
            }
        }
    }

    cin >> Q;
    while (Q--) {
        cin >> L >> R;
        cout << (ans[L][R][1] - ans[L][R][0] + MOD) % MOD << endl;
    }

    return 0;
}