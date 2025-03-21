#include <bits/stdc++.h>
using namespace std;

const int MAX = 20;

int dp[MAX][MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M;

    cin >> N >> M;

    dp[0][0] = 1;

    for (int i = 0; i <= N; i++)
        for (int j = 0; j <= M; j++) {
            if (i == 0 && j == 0)
                continue;
            if (i * M < j * N)
                continue;
            if (i)
                dp[i][j] += dp[i - 1][j];
            if (j)
                dp[i][j] += dp[i][j - 1];
        }

    cout << dp[N][M] << '\n';

    return 0;
}