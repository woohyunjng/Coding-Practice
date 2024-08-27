#include <bits/stdc++.h>
#define int long long

#define MAX 110
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int dp[MAX][MAX][MAX * 3][2], arr[MAX][MAX][2];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, M, N, L, G;
    bool check;
    cin >> T;

    while (T--) {
        cin >> M >> N >> L >> G;
        for (int i = 0; i <= M; i++)
            for (int j = 0; j <= N; j++)
                for (int k = 0; k <= 2 * (M + N); k++)
                    dp[i][j][k][0] = dp[i][j][k][1] = INF;

        for (int i = 1; i <= M; i++) {
            for (int j = 1; j <= N - 1; j++)
                cin >> arr[i][j][1];
        }
        for (int i = 1; i <= M - 1; i++) {
            for (int j = 1; j <= N; j++)
                cin >> arr[i][j][0];
        }

        dp[1][1][0][0] = dp[1][1][0][1] = 0;
        for (int i = 1; i <= M; i++) {
            for (int j = 1; j <= N; j++) {
                if (i == 1 && j == 1)
                    continue;
                for (int k = 0; k <= 2 * (i + j); k++) {
                    if (!k) {
                        dp[i][j][k][0] = dp[i - 1][j][k][0] + arr[i - 1][j][0];
                        dp[i][j][k][1] = dp[i][j - 1][k][1] + arr[i][j - 1][1];
                    } else {
                        dp[i][j][k][0] = min(dp[i - 1][j][k][0], dp[i - 1][j][k - 1][1]) + arr[i - 1][j][0];
                        dp[i][j][k][1] = min(dp[i][j - 1][k][1], dp[i][j - 1][k - 1][0]) + arr[i][j - 1][1];
                    }
                }
            }
        }

        check = false;
        for (int i = 0; i <= 2 * (M + N); i++) {
            if (dp[M][N][i][0] <= G || dp[M][N][i][1] <= G) {
                cout << i + L * (N + M - 2) << '\n';
                check = true;
                break;
            }
        }

        if (!check)
            cout << -1 << '\n';
    }
    return 0;
}