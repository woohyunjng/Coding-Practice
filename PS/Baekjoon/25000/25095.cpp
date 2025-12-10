#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 101;

int A[MAX][MAX], V[MAX][MAX], S[MAX][MAX], D[MAX], dp[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, M, K, ans;

    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> N >> M, ans = 0;
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= M; j++)
                cin >> A[i][j], ans += A[i][j] * 2;

        N--;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++)
                V[i][j] = min(A[i][j], A[i + 1][j]);
        }
        for (int i = 1; i <= N; i++) {
            fill(D, D + M + 1, MAX), K = MAX * M;
            for (int j = i; j <= N; j++) {
                for (int k = 1; k <= M; k++)
                    K -= D[k], D[k] = min(D[k], V[j][k]), K += D[k];
                S[i][j] = K;
            }
        }

        for (int i = 1; i <= N; i++)
            for (int j = 1; j + i - 1 <= N; j++) {
                dp[j][j + i - 1] = S[j][j + i - 1] * i;
                if (i >= 2)
                    dp[j][j + i - 1] = max({dp[j][j + i - 1], dp[j + 1][j + i - 1] + S[j][j + i - 1], dp[j][j + i - 2] + S[j][j + i - 1]});
                for (int k = j + 1; k < j + i - 1; k++)
                    dp[j][j + i - 1] = max(dp[j][j + i - 1], dp[j][k - 1] + dp[k + 1][j + i - 1] + S[j][j + i - 1]);
            }

        cout << "Case #" << t << ": " << ans - (dp[1][N] << 1) << '\n';
    }

    return 0;
}