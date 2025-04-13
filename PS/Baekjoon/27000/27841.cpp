#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX_N = 100001;
const int MAX_M = 21;
const int MOD = 1000000007;

int A[MAX_M][MAX_N], V[MAX_N], cnt[1 << MAX_M], dp[1 << MAX_M][MAX_M];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, K, X = 0, ans = 0;
    string S;

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> S;
        for (int j = 1; j <= N; j++)
            A[i][j] = S[j - 1] == 'H';
    }

    for (int i = 1; i <= N; i++)
        V[i] = (i + i * V[i - 1]) % MOD;

    for (int i = 1; i <= N; i++) {
        X = 0;
        for (int j = 0; j < M; j++)
            X |= A[j][i] << j;
        cnt[X]++;
    }

    for (int i = 0; i < (1 << M); i++) {
        X = 1;
        for (int j = M - 1; j >= 0; j--)
            if (i & (1 << j))
                X = (X + dp[i ^ (1 << j)][j]) % MOD;

        K = X * V[cnt[i]] % MOD, ans = (ans + K) % MOD;
        dp[i][0] = K;

        for (int j = 0; j < M - 1; j++) {
            dp[i][j + 1] = dp[i][j];
            if (i & (1 << j))
                dp[i][j + 1] = (dp[i][j + 1] + dp[i ^ (1 << j)][j]) % MOD;
        }
    }

    cout << ans << '\n';

    return 0;
}