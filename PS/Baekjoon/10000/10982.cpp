#include <bits/stdc++.h>
#define int long long

#define MAX 1010
#define MAX_VAL 100010
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int arr[MAX][2], dp[2][MAX_VAL];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, sm = 0, res;
    cin >> T;

    while (T--) {
        cin >> N;

        sm = 0;
        for (int i = 1; i <= N; i++) {
            cin >> arr[i][0] >> arr[i][1];
            sm += max(arr[i][0], arr[i][1]);
        }

        dp[0][0] = 0;
        for (int i = 1; i <= sm; i++)
            dp[0][i] = INF;

        for (int i = 1; i <= N; i++) {
            for (int j = 0; j <= sm; j++) {
                dp[i & 1][j] = dp[(i & 1) ^ 1][j] + arr[i][1];
                if (j >= arr[i][0])
                    dp[i & 1][j] = min(dp[i & 1][j], dp[(i & 1) ^ 1][j - arr[i][0]]);
            }
        }

        res = INF;
        for (int i = 0; i <= sm; i++)
            res = min(res, max(i, dp[N & 1][i]));
        cout << res << '\n';
    }

    return 0;
}