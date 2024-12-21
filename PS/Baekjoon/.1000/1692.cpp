#include <bits/stdc++.h>
#define int long long

#define MAX 17
using namespace std;

int A[52][MAX], chk[52], dp[52][1 << MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int R, res = 801, X, Y;
    string S;

    cin >> R;
    for (int i = 1; i <= R; i++) {
        cin >> S;
        for (int j = 0; j < 16; j++)
            A[i][j] = S[j] - '0';
    }

    fill(&dp[0][0], &dp[50][1 << 16], 800);
    for (int i = 0; i < (1 << 16); i++)
        dp[1][i] = (int)__builtin_popcount(i);

    for (int i = 1; i <= R; i++) {
        for (int j = (1 << 16) - 1; j >= 0; j--) {
            X = 0;
            for (int k = 0; k < 16; k++) {
                Y = A[i][k] ^ ((j & (1 << k)) != 0);
                if (Y && !X)
                    X = 1, dp[i][j]++;
                else if (!Y)
                    X = 0;
            }

            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
            for (int k = 0; k < 16; k++)
                if (j & (1 << k))
                    dp[i + 1][j ^ (1 << k)] = min(dp[i + 1][j ^ (1 << k)], dp[i + 1][j]);
        }

        for (int j = 0; j < (1 << 16); j++) {
            for (int k = 0; k < 16; k++)
                if (!(j & (1 << k)))
                    dp[i + 1][j | (1 << k)] = min(dp[i + 1][j | (1 << k)], dp[i + 1][j] + 1);
        }
    }

    for (int i = 0; i < (1 << 16); i++)
        res = min(res, dp[R][i]);

    cout << res << '\n';

    return 0;
}
