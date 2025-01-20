#include <bits/stdc++.h>
#define int long long

#define MAX 300000
#define MOD 998244353

using namespace std;

int A[MAX], dp[MAX][2];

void solve() {
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> A[i];

    dp[0][1] = 1;
    dp[1][0] = 1, dp[1][1] = A[1] == 0;

    for (int i = 2; i <= N; i++) {
        dp[i][0] = dp[i - 1][1];
        dp[i][1] = (dp[i - 1][1] * (A[i] == A[i - 1]) + dp[i - 1][0] * (A[i] == A[i - 2] + 1)) % MOD;
    }

    cout << (dp[N][0] + dp[N][1]) % MOD << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;

    while (T--)
        solve();

    return 0;
}