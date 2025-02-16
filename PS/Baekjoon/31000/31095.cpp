#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 6000;
const int MOD = 1000000007;

int dp[MAX][MAX], comb[MAX][MAX], cnt[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N = MAX - 1, K;

    for (int i = 0; i <= N; i++) {
        comb[i][0] = 1;
        for (int j = 1; j <= i; j++)
            comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
    }

    cnt[0] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++)
            dp[i][1] = (dp[i][1] + comb[i - 1][j - 1] * cnt[i - j]) % MOD;
        for (int j = 2; j <= i; j++)
            dp[i][j] = cnt[j - 1] * dp[i - j + 1][1] % MOD * comb[i - 1][j - 1] % MOD;
        for (int j = 1; j <= i; j++)
            cnt[i] = (cnt[i] + dp[i][j]) % MOD;
    }

    cin >> T;
    while (T--) {
        cin >> N >> K;
        cout << dp[N][K] << '\n';
    }

    return 0;
}