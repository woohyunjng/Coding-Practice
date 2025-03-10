#include <bits/stdc++.h>
using namespace std;

const int MAX = 11;
const int INF = 100000000;

int dp[MAX][1 << MAX], A[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;

    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> A[i][j];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < (1 << N); j++)
            dp[i][j] = INF;

    for (int i = 0; i < N; i++)
        dp[0][1 << i] = A[0][i];

    for (int i = 1; i < N; i++)
        for (int j = 0; j < (1 << N); j++)
            for (int k = 0; k < N; k++) {
                if ((j & (1 << k)) || dp[i - 1][j] == INF)
                    continue;
                dp[i][j ^ (1 << k)] = min(dp[i][j ^ (1 << k)], dp[i - 1][j] + A[i][k]);
            }

    cout << dp[N - 1][(1 << N) - 1] << '\n';

    return 0;
}