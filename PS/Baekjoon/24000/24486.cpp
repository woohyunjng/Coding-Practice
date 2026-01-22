#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 5001;
const int MOD = 1'000'000'007;

int A[MAX], B[MAX], K[MAX][2], dp[MAX][MAX], P[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, C[2];

    cin >> T;
    while (T--) {
        cin >> N, C[0] = C[1] = 0;
        for (int i = 1; i <= N; i++)
            cin >> A[i], K[++C[A[i] & 1]][A[i] & 1] = i, P[i] = C[A[i] & 1];

        for (int i = 1; i <= N; i++) {
            B[i] = 0;
            for (int j = i - 1; j >= 1; j--)
                if (abs(A[j] - A[i]) > 1 && (A[j] & 1) != (A[i] & 1)) {
                    B[i] = P[j];
                    break;
                }
        }

        dp[0][0] = 1;
        for (int i = 0; i <= C[0]; i++)
            for (int j = i == 0; j <= C[1]; j++) {
                dp[i][j] = 0;
                if (i > 0 && B[K[i][0]] <= j)
                    dp[i][j] += dp[i - 1][j];
                if (j > 0 && B[K[j][1]] <= i)
                    dp[i][j] += dp[i][j - 1];
                dp[i][j] %= MOD;
            }

        cout << dp[C[0]][C[1]] << '\n';
    }

    return 0;
}