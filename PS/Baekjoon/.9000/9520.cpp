#include <bits/stdc++.h>
#define int long long

#define MAX 2000
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int arr[MAX][MAX], dp[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, res = INF;
    cin >> N;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> arr[i][j];

    dp[2][1] = dp[2][2] = arr[1][2];

    for (int i = 3; i <= N; i++) {
        for (int j = 1; j < i; j++) {
            dp[i][i] += dp[i - 1][j] + arr[i][j];
            if (j != i - 1)
                dp[i][j] = dp[i - 1][j] + arr[i][i - 1];
            else {
                dp[i][j] = INF;
                for (int k = 1; k < i - 1; k++)
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + arr[i][k]);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        if (dp[N][i])
            res = min(res, dp[N][i]);
    }

    cout << res;

    return 0;
}