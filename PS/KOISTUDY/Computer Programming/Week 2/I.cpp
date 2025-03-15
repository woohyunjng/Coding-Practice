#include <bits/stdc++.h>
using namespace std;

const int MAX = 20;

int dp[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;

    dp[0][0] = 1;

    cin >> N;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++) {
            if (i == j && i != N)
                continue;
            for (int x = 1; x <= 3; x++)
                for (int y = 1; y <= 3; y++)
                    if (i >= x && j >= y)
                        dp[i][j] += dp[i - x][j - y];
        }
    cout << dp[N][N] << '\n';

    return 0;
}