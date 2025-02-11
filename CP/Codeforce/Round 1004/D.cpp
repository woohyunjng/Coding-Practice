#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define int long long

using namespace std;

const int MAX = 200;
const int MAX_M = 20000;
const int MOD = 1000000007;

int A[MAX_M], dp[MAX][MAX_M], comb[MAX][MAX];

void solve() {
    int N, C, M;
    cin >> N >> C >> M;
    for (int i = 1; i <= M; i++)
        cin >> A[i];

    dp[N][C] = 1;
    for (int i = N - 1; i >= 1; i--)
        for (int j = 0; j <= C; j++)
            for (int k = C; k <= min(M - j, (N - i) * C); k++)
                dp[i][j + k] = (dp[i][j + k] + dp[i + 1][k] * comb[C][C - j]) % MOD;
    cout << dp[1][M] << '\n';

    for (int i = 1; i <= N; i++)
        for (int j = 0; j <= M; j++)
            dp[i][j] = 0;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;

    for (int i = 0; i < MAX; i++) {
        comb[i][0] = 1;
        for (int j = 1; j <= i; j++)
            comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
    }

    while (T--)
        solve();

    return 0;
}