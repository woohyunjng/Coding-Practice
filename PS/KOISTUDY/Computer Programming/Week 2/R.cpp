#include <bits/stdc++.h>
using namespace std;

const int MAX = 30;
const int MAX_W = 2000;

int dp[MAX][MAX_W], W[MAX], V[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M;

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        cin >> W[i] >> V[i];

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (j >= W[i])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - W[i]] + V[i]);
        }

    cout << dp[N][M] << '\n';

    return 0;
}