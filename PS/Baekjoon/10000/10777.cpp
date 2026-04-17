#include <bits/stdc++.h>
using namespace std;

const int MAX = 3001;
const int MAX_M = 101;

int A[MAX], B[MAX],
    dp[2][MAX_M][MAX_M][2], S[MAX]; // 버리는 것 / 챙긴 것

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X, ans = 0;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    cin >> M;
    for (int i = 1; i <= M; i++)
        cin >> B[i];
    sort(B + 1, B + M + 1);
    for (int i = 1; i <= M; i++)
        S[i] = S[i - 1] + B[i];

    for (int i = 1; i <= N; i++)
        for (int j = 0; j <= M; j++)
            for (int k = 0; j + k <= M; k++) {
                dp[i & 1][j][k][0] = dp[i & 1][j][k][1] = 0;

                if (j > 0)
                    dp[i & 1][j][k][1] = max(dp[i & 1][j][k][1], dp[i & 1 ^ 1][j - 1][k][1]);
                dp[i & 1][j][k][1] = max(dp[i & 1][j][k][1], dp[i & 1 ^ 1][j][k][0]);
                dp[i & 1][j][k][1] += A[i];

                if (k > 0)
                    dp[i & 1][j][k][0] = max(dp[i & 1][j][k][0], dp[i & 1 ^ 1][j][k - 1][0] + B[M - k + 1]);
                dp[i & 1][j][k][0] = max({dp[i & 1][j][k][0], dp[i & 1 ^ 1][j][k][0], dp[i & 1 ^ 1][j][k][1]});
            }

    for (int k = M; k > 0; k--)
        for (int j = 0; j + k <= M; j++)
            dp[N & 1][j][k][0] = max(dp[N & 1][j][k][0], dp[N & 1][j][k - 1][0] + B[M - k + 1]);

    for (int j = 0; j <= M; j++)
        for (int k = 0; j + k <= M; k++) {
            X = (M - j - k) / 2;
            ans = max(ans, max(dp[N & 1][j][k][0], dp[N & 1][j][k][1]) + S[M - k] - S[M - k - X]);
        }

    cout << ans << '\n';

    return 0;
}