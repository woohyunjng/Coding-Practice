#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;
const int MOD = 100000007;

int dp[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;

    cin >> N;

    dp[0] = 1, dp[1] = 1;
    for (int i = 2; i <= N; i++)
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;

    cout << dp[N] << '\n';

    return 0;
}