#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAX = 202;
const int MOD = 998244353;

int A[MAX], dp1[MAX][MAX][2][2], dp2[MAX][MAX][MAX][2];

void solve() {
    int N, X, Y, P, Q, ans = 0;
    string S;

    cin >> N >> S;
    for (int i = 1; i <= N; i++)
        A[i] = S[i - 1] == '(' ? 1 : -1;

    dp1[0][0][0][0] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= i; j++) {
            for (int k = 0; k < 2; k++)
                dp1[i][j][k][0] = dp1[i - 1][j][k][0], dp1[i][j][k][1] = dp1[i - 1][j][k][1];
            if (j - A[i] >= 0) {
                for (int k = 0; k < 2; k++) {
                    X = A[i] == -1 ? 1 : k;
                    dp1[i][j][X][0] = (dp1[i][j][X][0] + dp1[i - 1][j - A[i]][k][0]) % MOD;
                    dp1[i][j][X][1] = (dp1[i][j][X][1] + dp1[i - 1][j - A[i]][k][0] + dp1[i - 1][j - A[i]][k][1]) % MOD;
                }
            }
        }
    }

    for (int i = 1; i <= N; i++)
        A[i] = -A[i];

    dp2[N + 1][0][0][0] = 1; // idx, val, -1 cnt
    for (int i = N; i >= 1; i--)
        for (int j = 0; j <= N + 1 - i; j++)
            for (int k = 0; k <= N + 1 - i; k++) {
                dp2[i][j][k][0] = dp2[i + 1][j][k][0], dp2[i][j][k][1] = dp2[i + 1][j][k][1];
                if (A[i] == -1 && k > 0) {
                    X = dp2[i + 1][j + 1][k - 1][0], Y = (X + dp2[i + 1][j + 1][k - 1][1]) % MOD;
                    if (k == 2) {
                        P = dp1[i - 1][j][1][0], Q = dp1[i - 1][j][1][1];
                        ans += (X * Q % MOD + Y * P % MOD) % MOD, ans %= MOD;
                        ans = (ans - 2 * P * X % MOD + MOD * 2) % MOD;
                    }

                    dp2[i][j][k][0] = (dp2[i][j][k][0] + X) % MOD;
                    dp2[i][j][k][1] = (dp2[i][j][k][1] + Y) % MOD;
                } else if (A[i] == 1 && j > 0) {
                    dp2[i][j][k][0] = (dp2[i][j][k][0] + dp2[i + 1][j - 1][k][0]) % MOD;
                    dp2[i][j][k][1] = (dp2[i][j][k][1] + dp2[i + 1][j - 1][k][0] + dp2[i + 1][j - 1][k][1]) % MOD;
                }
            }

    cout << ans << '\n';

    for (int i = 0; i <= N + 1; i++)
        for (int j = 0; j <= N; j++) {
            for (int k = 0; k < 2; k++)
                dp1[i][j][k][0] = dp1[i][j][k][1] = 0;
            for (int k = 0; k <= N; k++)
                dp2[i][j][k][0] = dp2[i][j][k][1] = 0;
        }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;

    while (T--)
        solve();

    return 0;
}