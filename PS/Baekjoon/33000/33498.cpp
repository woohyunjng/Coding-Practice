#include <bits/stdc++.h>
using namespace std;

const int MAX = 751;
const int INF = INT_MAX;

int A[MAX][MAX], B[MAX][MAX], S[MAX][MAX], dp[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, ans = INF;

    cin >> N;
    for (int i = 1; i < N; i++)
        for (int j = 0; j < i; j++) {
            cin >> A[j][i];
            if (A[j][i] < 0)
                B[j][i] = -A[j][i], A[j][i] = 0;
        }

    for (int i = 0; i < N; i++)
        for (int j = N - 1; j >= i; j--)
            S[i][j] = S[i][j + 1] + B[i][j + 1];

    for (int i = N - 1; i >= 0; i--) {
        for (int j = i + 1; j < N; j++) {
            dp[i][j] = INF;
            for (int k = i; k < j; k++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + A[i][k + 1]);
        }
        for (int j = i; j < N; j++)
            dp[i][j] += S[i][j];
    }

    cout << dp[0][N - 1] << '\n';

    return 0;
}