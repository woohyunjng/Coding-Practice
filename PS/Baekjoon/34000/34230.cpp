#include <bits/stdc++.h>
using namespace std;

const int MAX = 5001;

int A[MAX], dp[MAX][MAX][2];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, ans = MAX, V;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        for (int j = 0; j < MAX; j++)
            dp[i][j][0] = dp[i][j][1] = MAX;
    }

    for (int i = 1; i <= N; i++) {
        V = 0;
        for (int j = i; j >= 1; j--) {
            V ^= A[j];
            if (V >= 1)
                dp[i][V][0] = min(dp[i][V][0], dp[j - 1][V - 1][1] + i - j);
            if (V < MAX - 1)
                dp[i][V][1] = min(dp[i][V][1], dp[j - 1][V + 1][0] + i - j);
        }

        for (int j = MAX - 2; j >= 0; j--)
            dp[i][j][0] = min(dp[i][j][0], dp[i][j + 1][0]);
        for (int j = 1; j < MAX; j++)
            dp[i][j][1] = min(dp[i][j][1], dp[i][j - 1][1]);
    }

    for (int i = 0; i < MAX; i++)
        ans = min({ans, dp[N][i][0], dp[N][i][1]});

    cout << ans << '\n';

    return 0;
}