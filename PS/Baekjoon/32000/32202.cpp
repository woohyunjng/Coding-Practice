#include <bits/stdc++.h>
#define int long long

#define MAX 1001000
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int dp[MAX][2];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;

    dp[1][0] = 2, dp[1][1] = 1;
    for (int i = 2; i <= N; i++) {
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) * 2 % MOD;
        dp[i][1] = dp[i - 1][0];
    }

    cout << (dp[N][0] + dp[N][1]) % MOD;

    return 0;
}