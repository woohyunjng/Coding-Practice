#include <bits/stdc++.h>
using namespace std;

const int MAX = 20;

int dp[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    dp[0] = 1, dp[1] = 1, dp[2] = 2;

    cin >> N;
    for (int i = 3; i <= N; i++)
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    cout << dp[N] << '\n';

    return 0;
}