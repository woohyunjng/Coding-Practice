#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;
const int MOD = 100007;

int dp[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;

    cin >> N;

    dp[0] = 1;

    for (int i = 1; i <= N; i++) {
        dp[i] = dp[i - 1];
        if (i >= 2)
            dp[i] += dp[i - 2] * 4;
        if (i >= 3)
            dp[i] += dp[i - 3] * 2;
        dp[i] %= MOD;
    }

    cout << dp[N] << '\n';

    return 0;
}