#include <bits/stdc++.h>
using namespace std;

int dp[50];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;

    cin >> N;

    dp[1] = 1;
    for (int i = 2; i <= N; i++) {
        dp[i] = 100000;
        for (int j = 1; j < i; j++)
            dp[i] = min(dp[i], dp[j] * 2 + (1 << (i - j)) - 1);
    }

    cout << dp[N] << '\n';

    return 0;
}