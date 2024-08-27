#include <bits/stdc++.h>
#define int long long

#define MAX 21
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int dp[MAX][MAX][2], res[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N;

    N = 20;
    dp[1][1][0] = dp[1][1][1] = 1;
    res[1] = 1;

    for (int i = 2; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            for (int k = 1; k < j; k++)
                dp[i][j][1] += dp[i - 1][k][0];
            for (int k = j; k <= i - 1; k++)
                dp[i][j][0] += dp[i - 1][k][1];

            res[i] += dp[i][j][0] + dp[i][j][1];
        }
    }

    cin >> T;
    while (T--) {
        cin >> N;
        cout << res[N] << '\n';
    }

    return 0;
}