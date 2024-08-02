#include <bits/stdc++.h>
#define int long long
#define MAX 510

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int dp[MAX][MAX], sm[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, K, X;
    cin >> T;

    while (T--) {
        cin >> K;

        sm[0] = 0;
        for (int i = 1; i <= K; i++) {
            cin >> X;
            sm[i] = sm[i - 1] + X;
        }

        for (int i = 1; i <= K; i++) {
            for (int j = 1; j <= K - i + 1; j++) {
                if (i == 1)
                    dp[j][j + i - 1] = 0;
                else {
                    dp[j][j + i - 1] = LLONG_MAX;
                    for (int k = j; k < j + i - 1; k++)
                        dp[j][j + i - 1] = min(dp[j][j + i - 1], dp[j][k] + dp[k + 1][j + i - 1] + sm[j + i - 1] - sm[j - 1]);
                }
            }
        }

        cout << dp[1][K] << '\n';
    }

    return 0;
}