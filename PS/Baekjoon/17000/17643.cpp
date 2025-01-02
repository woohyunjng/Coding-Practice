#include <bits/stdc++.h>
#define int long long

#define MAX 19
#define MOD 998244353

using namespace std;

int adj[MAX], dp[1 << MAX];
bool chk[1 << MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, U, V, res = (MOD + 1) / 2;

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        cin >> U >> V, U--, V--;
        adj[U] |= 1 << V, adj[V] |= 1 << U;
    }

    for (int i = 0; i < (1 << N); i++)
        for (int j = 0; j < N; j++)
            for (int k = j + 1; k < N; k++)
                if ((i & (1 << j)) && (i & (1 << k)) && (adj[j] & (1 << k)))
                    chk[i] = true;

    dp[0] = 1;
    for (int i = 1; i < (1 << N); i++) {
        for (int j = i; j; j = (i & (j - 1))) {
            if (chk[j])
                continue;
            dp[i] = (dp[i] + dp[i ^ j] * ((__builtin_popcount(j) & 1) ? 1 : -1) + MOD) % MOD;
        }
    }

    cout << res * M % MOD * dp[(1 << N) - 1] % MOD << '\n';

    return 0;
}