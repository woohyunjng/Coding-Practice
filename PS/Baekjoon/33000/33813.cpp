#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 63;
const int MAX_K = 10001;

int dp[MAX][MAX_K][2];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int K, T, N, ans, X, Y;

    cin >> K >> T;

    dp[0][0][0] = dp[0][1 % K][1] = 1;
    for (int i = 1; i < MAX; i++)
        for (int j = 0; j < K; j++)
            for (int k = 0; k < 2; k++)
                dp[i][j][k] = dp[i - 1][j][k] + dp[i - 1][(j - (1ll << i) % K + K) % K][k ^ 1];

    while (T--) {
        cin >> N, N *= K;
        ans = X = Y = 0;

        for (int i = MAX - 1; i > 0; i--) {
            if (!(N & (1ll << i)))
                continue;
            ans += dp[i - 1][(K - X) % K][Y ^ 1] - dp[i - 1][(K - X) % K][Y];
            X = (X + (1ll << i)) % K, Y ^= 1;
        }
        Y ^= (N & 1), ans += Y == 1 ? 2 : 0;
        if ((N & 1) && K == 1)
            ans += Y == 0 ? 1 : -1;

        cout << ans << '\n';
    }

    return 0;
}