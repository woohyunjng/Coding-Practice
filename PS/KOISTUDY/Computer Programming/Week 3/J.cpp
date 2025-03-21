#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;
const int MOD = 100007;

int dp[MAX][3]; // 0 -> 가득 1 -> 위가 빔 2 -> 아래가 빔

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;

    cin >> N;

    dp[0][0] = 1;
    for (int i = 1; i <= N; i++) {
        dp[i][0] = (dp[i - 1][0] * 2 + dp[i - 1][1] + dp[i - 1][2]) % MOD;
        dp[i][1] = dp[i][2] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;

        if (i >= 2)
            dp[i][0] = (dp[i][0] + dp[i - 2][0]) % MOD;
    }

    cout << dp[N][0] << '\n';

    return 0;
}