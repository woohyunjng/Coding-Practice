#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 5001;
const int MOD = 998244353;

int S[MAX], dp[2][MAX * 2];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    string T;

    cin >> N >> T;

    for (int i = 1; i <= N; i++)
        S[i] = S[i - 1] + (T[i - 1] == '(' ? 1 : -1);

    dp[0][N] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = -i; j <= S[i]; j++) {
            if (j + 1 + N >= 0 && j + 1 + N < MAX * 2)
                dp[i & 1][j + N] = (dp[i & 1][j + N] + dp[i & 1 ^ 1][j + 1 + N]) % MOD;
            if (j - 1 + N >= 0 && j - 1 + N < MAX * 2)
                dp[i & 1][j + N] = (dp[i & 1][j + N] + dp[i & 1 ^ 1][j - 1 + N]) % MOD;
        }
        fill(dp[i & 1 ^ 1], dp[i & 1 ^ 1] + MAX * 2, 0);
    }

    cout << dp[N & 1][S[N] + N] << '\n';
    return 0;
}