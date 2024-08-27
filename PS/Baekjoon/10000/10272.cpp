#include <bits/stdc++.h>
#define int long long

#define MAX 600
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

pr arr[MAX];
double dp[MAX][MAX];

double dis(pr A, pr B) { return sqrt((A.first - B.first) * (A.first - B.first) + (A.second - B.second) * (A.second - B.second)); }

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N;
    double res;
    cin >> T;

    while (T--) {
        cin >> N;
        for (int i = 1; i <= N; i++)
            cin >> arr[i].first >> arr[i].second;
        res = INF;

        for (int i = 2; i <= N; i++) {
            dp[1][i] = dp[1][i - 1] + dis(arr[i - 1], arr[i]);
            dp[i][1] = dp[i - 1][1] + dis(arr[i - 1], arr[i]);
            dp[i][i] = INF;
        }

        for (int i = 2; i <= N; i++) {
            for (int j = 2; j < i; j++) {
                dp[i][j] = dp[j][i] = INF;
                if (i == j + 1) {
                    for (int k = 1; k < j; k++) {
                        dp[i][j] = min(dp[i][j], dp[k][j] + dis(arr[k], arr[i]));
                        dp[j][i] = min(dp[j][i], dp[k][j] + dis(arr[k], arr[i]));
                    }
                } else {
                    dp[i][j] = dp[i - 1][j] + dis(arr[i - 1], arr[i]);
                    dp[j][i] = dp[j][i - 1] + dis(arr[i - 1], arr[i]);
                }
            }
        }

        for (int i = 1; i < N; i++) {
            res = min(res, dp[i][N] + dis(arr[i], arr[N]));
            res = min(res, dp[N][i] + dis(arr[i], arr[N]));
        }

        cout << res << '\n';

        for (int i = 1; i <= N; i++)
            fill(dp[i], dp[i] + N + 1, 0);
    }

    return 0;
}