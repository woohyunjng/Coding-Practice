#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 2001;
const int INF = 0x3f3f3f3f3f3f3f3f;

int dp[MAX][MAX], A[MAX], B[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, P[4];
    string SA, SB;

    cin >> N;
    cin >> SA >> SB;
    for (int i = 1; i <= N; i++)
        A[i] = SA[i - 1] - '0', B[i] = SB[i - 1] - '0';
    for (int i = 0; i < 4; i++)
        cin >> P[i];

    for (int i = 0; i <= N; i++)
        for (int j = 0; j <= N; j++) {
            if (i == 0 && j == 0)
                continue;

            dp[i][j] = INF;
            if (!A[i] && i)
                dp[i][j] = min(dp[i - 1][j], dp[i][j]);
            if (!B[j] && j)
                dp[i][j] = min(dp[i][j - 1], dp[i][j]);
            if (i == j)
                dp[i][j] = min(dp[i][j], dp[max(0ll, i - 4)][max(0ll, j - 4)] + P[3]);
            dp[i][j] = min(dp[i][j], min(dp[max(0ll, i - 1)][j], dp[i][max(0ll, j - 1)]) + P[0]);
            dp[i][j] = min(dp[i][j], min(dp[max(0ll, i - 3)][j], dp[i][max(0ll, j - 3)]) + P[1]);
            dp[i][j] = min(dp[i][j], min(dp[max(0ll, i - 5)][j], dp[i][max(0ll, j - 5)]) + P[2]);
        }

    cout << dp[N][N] << '\n';

    return 0;
}