#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MAX_R 210
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;

int A[MAX], dp[MAX][MAX_R][3];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, R;
    cin >> N >> R;

    for (int i = 1; i <= N; i++)
        cin >> A[i];

    for (int i = 0; i <= N; i++)
        for (int j = 0; j <= R; j++)
            dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = -INF;
    dp[0][0][0] = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= R; j++) {
            dp[i][j][1] = max(dp[i - 1][j][1], j >= 1 ? dp[i - 1][j - 1][0] + A[i] : -INF);
            dp[i][j][2] = max(dp[i - 1][j][2], j >= 1 ? dp[i - 1][j - 1][0] - A[i] : -INF);
            dp[i][j][0] = max({dp[i - 1][j][0], dp[i][j][1] - A[i], dp[i][j][2] + A[i]});
        }
    }

    for (int i = 1; i <= R; i++)
        cout << dp[N][i][0] << '\n';

    return 0;
}