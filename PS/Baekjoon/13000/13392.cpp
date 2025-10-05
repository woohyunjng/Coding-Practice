#include <bits/stdc++.h>
using namespace std;

const int MAX = 10001;
const int INF = 2e9;

int A[MAX], B[MAX], dp[MAX][10];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K;
    string _A, _B;

    cin >> N >> _A >> _B;
    for (int i = 1; i <= N; i++)
        A[i] = _A[i - 1] - '0', B[i] = _B[i - 1] - '0';

    for (int i = 0; i <= N; i++)
        for (int j = 0; j < 10; j++)
            dp[i][j] = INF;

    dp[0][0] = 0;
    for (int i = 1; i <= N; i++)
        for (int j = 0; j < 10; j++) {
            if (dp[i - 1][j] == INF)
                continue;
            K = (B[i] + 10 - (A[i] + j) % 10) % 10;
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + ((A[i] + j) % 10 + 10 - B[i]) % 10);
            dp[i][(j + K) % 10] = min(dp[i][(j + K) % 10], dp[i - 1][j] + K);
        }

    for (int j = 1; j < 10; j++)
        dp[N][0] = min(dp[N][0], dp[N][j]);
    cout << dp[N][0] << '\n';

    return 0;
}