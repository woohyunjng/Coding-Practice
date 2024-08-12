#include <bits/stdc++.h>
#define int long long

#define MAX 200
#define MOD 100000
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int dp[MAX][MAX][2][2];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int W, H;
    cin >> W >> H;

    for (int i = 1; i <= W; i++)
        dp[i][1][0][0] = 1;
    for (int i = 1; i <= H; i++)
        dp[1][i][1][0] = 1;

    for (int i = 2; i <= W; i++) {
        for (int j = 2; j <= H; j++) {
            dp[i][j][1][0] = (dp[i][j - 1][1][1] + dp[i][j - 1][1][0]) % MOD;
            dp[i][j][0][0] = (dp[i - 1][j][0][1] + dp[i - 1][j][0][0]) % MOD;
            dp[i][j][1][1] = dp[i][j - 1][0][0];
            dp[i][j][0][1] = dp[i - 1][j][1][0];
        }
    }

    cout << (dp[W][H][0][0] + dp[W][H][0][1] + dp[W][H][1][0] + dp[W][H][1][1]) % MOD << endl;

    return 0;
}