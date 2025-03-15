#include <bits/stdc++.h>
using namespace std;

const int MAX = 20;

int dp[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, ans = 0;

    dp[0][0] = 1;

    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= min(4, i); j++)
            for (int k = 0; k <= j; k++)
                dp[i][j] += dp[i - j][k];
    }

    for (int i = 1; i <= 4; i++)
        ans += dp[N][i];
    cout << ans << '\n';

    return 0;
}