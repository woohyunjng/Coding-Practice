#include <bits/stdc++.h>
using namespace std;

const int MAX = 501;

string A[MAX], P1[MAX], P2[MAX];
int dp[MAX][MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, P, Q;
    string C;

    cin >> N >> P >> Q;
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    for (int i = 1; i <= P; i++)
        cin >> P1[i];
    for (int i = 1; i <= Q; i++)
        cin >> P2[i];

    for (int i = 1; i <= N; i++)
        for (int j = 0; j <= P; j++)
            for (int k = 0; k <= Q; k++) {
                dp[i][j][k] = dp[i - 1][j][k];
                if (j > 0)
                    dp[i][j][k] = max({dp[i][j][k], dp[i][j - 1][k], dp[i - 1][j - 1][k] + (A[i] == P1[j])});
                if (k > 0)
                    dp[i][j][k] = max({dp[i][j][k], dp[i][j][k - 1], dp[i - 1][j][k - 1] + (A[i] == P2[k])});
            }

    cout << dp[N][P][Q] << '\n';

    return 0;
}