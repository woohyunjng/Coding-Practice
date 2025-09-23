#include <bits/stdc++.h>
using namespace std;

const int MAX = 501;
const int INF = 2e9;

int P[MAX], D[MAX], dp[MAX][MAX][MAX], S[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, V;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> P[i], D[P[i]] = i;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            S[i][j] = S[i][j - 1] + (P[j] <= i);

    for (int i = 0; i <= N; i++)
        for (int j = 1; j <= N; j++)
            for (int k = 0; k <= N; k++)
                dp[i][j][k] = INF;

    for (int i = 1; i <= N; i++)
        for (int j = 1, M = INF; j <= N; j++, M = INF) {
            for (int k = 1; k <= N; k++) {
                if (D[i] > k)
                    dp[i][j][k] = dp[i - 1][j][k];
                else
                    M = min(M, dp[i - 1][j - 1][k] + S[i][k] - S[i][D[i]]), dp[i][j][k] = M;
            }
        }

    for (int i = 1; i <= N; i++)
        cout << dp[N][i][N] << ' ';
    cout << '\n';

    return 0;
}