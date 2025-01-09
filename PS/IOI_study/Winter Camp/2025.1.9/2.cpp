#include <bits/stdc++.h>
#define int long long

#define MAX 51
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;

int A[MAX][MAX], sm[MAX][MAX], dp[MAX][MAX][MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            cin >> A[i][j];

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            sm[i][j] = A[i][j] + sm[i - 1][j] + sm[i][j - 1] - sm[i - 1][j - 1];

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++) {
            if (i == 1 && j == 1)
                continue;
            for (int k = 1; k + i - 1 <= N; k++)
                for (int l = 1; l + j - 1 <= M; l++) {
                    dp[k][l][k + i - 1][l + j - 1] = INF;
                    for (int x = k; x < k + i - 1; x++)
                        dp[k][l][k + i - 1][l + j - 1] = min(dp[k][l][k + i - 1][l + j - 1], dp[k][l][x][l + j - 1] + dp[x + 1][l][k + i - 1][l + j - 1]);
                    for (int x = l; x < l + j - 1; x++)
                        dp[k][l][k + i - 1][l + j - 1] = min(dp[k][l][k + i - 1][l + j - 1], dp[k][l][k + i - 1][x] + dp[k][x + 1][k + i - 1][l + j - 1]);
                    dp[k][l][k + i - 1][l + j - 1] += sm[k + i - 1][l + j - 1] - sm[k - 1][l + j - 1] - sm[k + i - 1][l - 1] + sm[k - 1][l - 1];
                }
        }

    cout << dp[1][1][N][M] << '\n';

    return 0;
}