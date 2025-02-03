#include <bits/stdc++.h>
#define int long long

#define MAX 20
#define MAX_N 400000

using namespace std;

int A[MAX_N], cnt[MAX], dp[1 << MAX][MAX * 2], mn[1 << MAX][2];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X, val[3] = {0, 0}, ans, V;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < M; j++)
            cin >> X, A[i] |= X << j, cnt[j] += X;
        dp[A[i]][__builtin_popcount(A[i])]++;
    }

    for (int i = 0; i < M; i++) {
        if (cnt[i] == N / 2)
            val[0] |= 1 << i;
        else if (cnt[i] == N / 2 + 1)
            val[1] |= 1 << i;
        else if (cnt[i] > N / 2 + 1)
            val[2] |= 1 << i;
    }

    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < (1 << MAX); j++) {
            if (j & (1 << i))
                dp[j ^ (1 << i)][__builtin_popcount(j) - 1] += dp[j][__builtin_popcount(j)];
        }

    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < (1 << MAX); j++) {
            if (!(j & (1 << i)))
                continue;
            for (int k = 0; k < MAX; k++)
                dp[j][k] += dp[j ^ (1 << i)][k] - dp[j][k + 1];
        }

    for (int i = 0; i < (1 << MAX); i++)
        for (int j = MAX; j >= 0; j--) {
            if (!dp[i][j])
                continue;
            if (dp[i][j] == 1)
                mn[i][1] = mn[i][0], mn[i][0] = j;
            else
                mn[i][0] = mn[i][1] = j;
        }

    for (int i = 1; i <= N; i++) {
        X = (val[0] & ~A[i]) | (val[1] & A[i]);
        ans = __builtin_popcount(val[0] | val[1] | val[2]) - __builtin_popcount(val[0] & A[i]) - mn[X][mn[X][0] == __builtin_popcount(X & A[i])];
        cout << ans << '\n';
    }

    return 0;
}