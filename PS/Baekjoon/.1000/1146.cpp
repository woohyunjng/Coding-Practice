#include <bits/stdc++.h>
#define int long long

#define MAX 110
#define MOD 1000000
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int dp[MAX][MAX][2];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, res = 0;
    cin >> N;

    dp[1][1][0] = dp[1][1][1] = 1;

    for (int i = 2; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            for (int k = 1; k < j; k++)
                dp[i][j][0] = (dp[i][j][0] + dp[i - 1][k][1]) % MOD;
            for (int k = j; k < i; k++)
                dp[i][j][1] = (dp[i][j][1] + dp[i - 1][k][0]) % MOD;
        }
    }

    for (int i = 1; i <= N; i++)
        res = (res + dp[N][i][0] + dp[N][i][1]) % MOD;
    if (N == 1)
        res = 1;

    cout << res;

    return 0;
}