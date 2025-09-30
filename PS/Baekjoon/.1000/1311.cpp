#include <bits/stdc++.h>
using namespace std;

const int MAX = 21;

int dp[MAX][1 << MAX], V[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;

    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> V[i][j];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < (1 << N); j++) {
            if (__builtin_popcount(j) != i + 1)
                continue;
            dp[i + 1][j] = 2e9;
            for (int k = 0; k < N; k++)
                if (j & (1 << k))
                    dp[i + 1][j] = min(dp[i + 1][j], dp[i][j ^ (1 << k)] + V[i][k]);
        }

    cout << dp[N][(1 << N) - 1] << '\n';

    return 0;
}