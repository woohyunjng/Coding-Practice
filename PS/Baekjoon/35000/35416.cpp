#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 2002;
const int INF = 0x3f3f3f3f3f3f3f3f;

int A[MAX][MAX], dp[MAX][MAX],
    mx[MAX][2], mn[MAX][2];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int R, K, X, Y;

    cin >> R >> K;
    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= K; j++)
            cin >> A[i][j], A[i][j] = (i & 1) ? -A[i][j] : A[i][j];

    for (int i = R; i >= 2; i--) {
        mn[0][0] = mn[K + 1][1] = INF;
        mx[0][0] = mx[K + 1][1] = -INF;

        for (int j = 1; j <= K; j++) {
            mn[j][0] = min(A[i][j] + dp[i + 1][j], mn[j - 1][0]);
            mx[j][0] = max(A[i][j] + dp[i + 1][j], mx[j - 1][0]);
        }
        for (int j = K; j >= 1; j--) {
            mn[j][1] = min(A[i][j] + dp[i + 1][j], mn[j + 1][1]);
            mx[j][1] = max(A[i][j] + dp[i + 1][j], mx[j + 1][1]);
        }

        for (int j = 1; j <= K; j++) {
            dp[i][j] = dp[i + 1][j];
            if (i & 1)
                dp[i][j] = min({dp[i][j], mn[j - 1][0], mn[j + 1][1]});
            else
                dp[i][j] = max({dp[i][j], mx[j - 1][0], mx[j + 1][1]});
        }
    }

    X = INF;
    for (int i = 1; i <= K; i++)
        X = min(X, A[1][i] + dp[2][i]);

    cout << (X >= 0 ? "ibasic" : "djangg7") << ' ' << abs(X) << '\n';

    return 0;
}