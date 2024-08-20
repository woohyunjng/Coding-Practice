#include <bits/stdc++.h>
#define int long long

#define MAX 2010
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int arr[MAX], dp[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, res = INF;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    for (int i = 2; i <= N; i++) {
        dp[i][0] = dp[i - 1][0] + abs(arr[i] - arr[i - 1]);
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j < i; j++) {
            dp[i][j] = INF;
            if (i == j + 1) {
                for (int k = 0; k < j; k++) {
                    if (k)
                        dp[i][j] = min(dp[i][j], dp[j][k] + abs(arr[i] - arr[k]));
                    else
                        dp[i][j] = min(dp[i][j], dp[j][k]);
                }
            } else
                dp[i][j] = dp[i - 1][j] + abs(arr[i] - arr[i - 1]);
        }
    }

    for (int i = 0; i < N; i++)
        res = min(res, dp[N][i]);

    cout << res;

    return 0;
}