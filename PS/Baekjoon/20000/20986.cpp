#include <bits/stdc++.h>

using namespace std;

const int MAX = 6000;
const int INF = 0x3f3f3f3f3f3f3f3f;

int dp[MAX], A[MAX], V[MAX], sm[MAX][MAX], val[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i], V[A[i]] = i;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= A[i]; j++)
            sm[j][i]++;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            sm[i][j] += sm[i][j - 1];

    for (int i = N; i >= 1; i--)
        for (int j = i; j >= 1; j--)
            val[j][i] = val[j + 1][i] + sm[j][V[j] - 1] - sm[i + 1][V[j] - 1];

    dp[0] = val[1][N];
    for (int i = 1; i <= N; i++) {
        dp[i] = INF;
        for (int j = 1; j <= i; j++)
            dp[i] = min(dp[i], dp[i - j] + j * (j - 1) / 2 - val[i - j + 1][i] * 2);
    }

    cout << dp[N] << '\n';

    return 0;
}