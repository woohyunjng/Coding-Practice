#include <bits/stdc++.h>
using namespace std;

const int MAX = 1001;

int A[MAX], dp[MAX][MAX], S[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N;

    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 1; i <= N; i++) {
            cin >> A[i], S[i] = S[i - 1] + A[i];
            dp[i][i] = A[i];
        }

        for (int i = 2; i <= N; i++)
            for (int j = 1; j + i - 1 <= N; j++) {
                dp[j][j + i - 1] = max(S[j + i - 2] - S[j - 1] - dp[j][j + i - 2] + A[j + i - 1],
                                       S[j + i - 1] - S[j] - dp[j + 1][j + i - 1] + A[j]);
            }

        cout << dp[1][N] << '\n';
    }

    return 0;
}