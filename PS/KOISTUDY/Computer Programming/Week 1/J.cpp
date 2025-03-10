#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;

int dp[MAX][MAX], A[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    dp[1][A[1]] = 1;
    for (int i = 2; i <= N - 1; i++) {
        for (int j = A[i]; j <= 20; j++)
            dp[i][j - A[i]] += dp[i - 1][j];
        for (int j = 0; j <= 20 - A[i]; j++)
            dp[i][j + A[i]] += dp[i - 1][j];
    }

    cout << dp[N - 1][A[N]] << '\n';

    return 0;
}