#include <bits/stdc++.h>
using namespace std;

const int MAX = 51;

int A[MAX], dp[MAX][2][2];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, ans;
    string S;

    cin >> N >> S;
    for (int i = 1; i <= N; i++) {
        if (S[i - 1] == '?')
            A[i] = 2;
        else
            A[i] = S[i - 1] == 'L' ? 1 : 0;
    }

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 1; k <= N; k++)
                dp[k][i][j] = MAX;

    for (int i = 0; i < 2; i++) {
        dp[1][i][i] = i;
        for (int j = 2; j <= N; j++)
            for (int k = 0; k < 2; k++) {
                if (A[j - 1] == 2 || A[j - 1] == 1)
                    dp[j][i][k] = min(dp[j][i][k], dp[j - 1][i][k ^ 1] + k);
                if (A[j - 1] == 2 || A[j - 1] == 0)
                    dp[j][i][k] = min(dp[j][i][k], dp[j - 1][i][k] + k);
            }
        if (A[N] == 2 || A[N] == 1)
            ans = min(ans, dp[N][i][i ^ 1]);
        if (A[N] == 2 || A[N] == 0)
            ans = min(ans, dp[N][i][i]);
    }

    if (ans == MAX)
        ans = -1;
    cout << ans << '\n';

    return 0;
}
