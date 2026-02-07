#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;

const int MAX = 500000;
const int MAX_K = 21;
const int MOD = 1'000'000'007;

int A[MAX], V[1 << MAX_K], inv[MAX_K];
pr dp[MAX_K][1 << MAX_K];

int fpow(int N, int K) {
    int res = 1;
    while (K) {
        if (K & 1)
            res = res * N % MOD;
        N = N * N % MOD, K >>= 1;
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, ans;

    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> A[i], dp[0][A[i]][0]++;
    for (int i = 1; i <= K; i++)
        inv[i] = fpow(i, MOD - 2);

    for (int i = 0; i < K; i++)
        for (int j = 0; j < (1 << K); j++) {
            if (j & (1 << i))
                continue;
            for (int k = i + 1; k > 0; k--) {
                dp[k][j][0] += dp[k - 1][j ^ (1 << i)][0];
                dp[k][j][1] += dp[k - 1][j ^ (1 << i)][1];
                dp[k][j ^ (1 << i)] = {
                    dp[k - 1][j][0] + dp[k - 1][j ^ (1 << i)][0],
                    dp[k - 1][j][1] + dp[k - 1][j ^ (1 << i)][0] + dp[k - 1][j ^ (1 << i)][1]};
            }
            dp[0][j ^ (1 << i)] = {0, 0};
        }

    for (int i = 0; i < N; i++) {
        ans = 0;
        for (int j = 1; j <= K; j++)
            ans += dp[j][A[i]][1] * inv[j] % MOD, ans %= MOD;
        cout << ans << '\n';
    }

    return 0;
}