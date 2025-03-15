#include <bits/stdc++.h>
using namespace std;

const int MAX = 20;

int dp[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M;
    dp[0] = 1;

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        if (i == M)
            continue;
        if (i >= 3)
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        else if (i >= 2)
            dp[i] = dp[i - 1] + dp[i - 2];
        else
            dp[i] = dp[i - 1];
    }
    cout << dp[N] << '\n';

    return 0;
}