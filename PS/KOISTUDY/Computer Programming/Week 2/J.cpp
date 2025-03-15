#include <bits/stdc++.h>
using namespace std;

const int MAX = 20;

int dp[MAX][MAX][MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;

    dp[0][0][0][0] = 1;

    cin >> N;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++) {
            if (i % 3 == 0 && j % 3 == 0) {
                for (int x = 1; x <= 2; x++)
                    for (int y = 1; y <= 2; y++)
                        if (i >= x && j >= y)
                            dp[i][j][1][1] += dp[i - x][j - y][0][0];
            } else if (i % 3 == 0) {
                for (int k = 0; k <= 1; k++)
                    for (int x = 1; x <= 2; x++)
                        for (int y = 1; y <= 2; y++)
                            if (i >= x && j >= y)
                                dp[i][j][1][k] += dp[i - x][j - y][0][k];
            } else if (j % 3 == 0) {
                for (int k = 0; k <= 1; k++)
                    for (int x = 1; x <= 2; x++)
                        for (int y = 1; y <= 2; y++)
                            if (i >= x && j >= y)
                                dp[i][j][k][1] += dp[i - x][j - y][k][0];
            } else {
                for (int k = 0; k <= 1; k++)
                    for (int l = 0; l <= 1; l++)
                        for (int x = 1; x <= 2; x++)
                            for (int y = 1; y <= 2; y++)
                                if (i >= x && j >= y)
                                    dp[i][j][k][l] += dp[i - x][j - y][k][l];
            }
        }
    cout << dp[N][N][1][1] << '\n';

    return 0;
}