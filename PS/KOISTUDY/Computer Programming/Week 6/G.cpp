#include <bits/stdc++.h>
#define int long long

using namespace std;

int dp[21];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;

    cin >> N;

    dp[0] = dp[1] = 1;
    for (int i = 2; i <= N; i++) {
        for (int j = 0; j <= i - 1; j++)
            dp[i] += dp[j] * dp[i - 1 - j];
    }

    cout << dp[N] << '\n';

    return 0;
}