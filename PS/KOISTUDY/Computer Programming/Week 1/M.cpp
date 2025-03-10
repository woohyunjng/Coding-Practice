#include <bits/stdc++.h>
using namespace std;

const int MAX = 30;

int dp[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;

    cin >> N;

    dp[0] = 1;
    for (int i = 1; i <= N; i++) {
        if (i >= 3)
            dp[i] += dp[i - 3];
        if (i >= 2)
            dp[i] += dp[i - 2];
        dp[i] += dp[i - 1];
    }

    cout << dp[N] << '\n';

    return 0;
}