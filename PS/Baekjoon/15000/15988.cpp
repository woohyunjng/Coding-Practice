#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 1000001;
const int MOD = 1000000009;

int dp[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N;

    dp[0] = 1;
    for (int i = 1; i < MAX; i++) {
        if (i >= 3)
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        else if (i >= 2)
            dp[i] = dp[i - 1] + dp[i - 2];
        else
            dp[i] = dp[i - 1];
        dp[i] %= MOD;
    }

    cin >> T;
    while (T--) {
        cin >> N;
        cout << dp[N] << '\n';
    }

    return 0;
}