#include <bits/stdc++.h>
#define int long long

#define MAX 2000000
#define MAX_K 21
#define INF 2147483647
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int dp[MAX], cst[MAX], cnt[MAX_K][MAX_K], val[MAX_K][MAX_K];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, A, L, R, K = 0, res = 0, X;
    string S;

    cin >> N >> S;

    for (int i = 1; i <= N; i++)
        K = max(K, S[i - 1] - 'A' + 1ll);

    for (int i = 1; i < N; i++)
        cnt[S[i - 1] - 'A'][S[i] - 'A']++;

    for (int i = 0; i < (1 << K); i++) {
        for (int j = 0; j < K; j++) {
            for (int k = 0; k < K; k++) {
                if ((i & (1 << j)) && !(i & (1 << k)))
                    cst[i] += cnt[j][k];
            }
        }
    }

    for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) {
            fill(dp, dp + (1 << K), INF);
            dp[0] = 0;

            for (int x = 1; x < (1 << K); x++) {
                X = __builtin_popcount(x) - 1;
                for (int y = 0; y < K; y++) {
                    if ((X == i && y != S[0] - 'A') || (X == j && y != S[N - 1] - 'A'))
                        continue;
                    if (x & (1 << y))
                        dp[x] = min(dp[x], dp[x ^ (1 << y)] + cst[x]);
                }
            }

            val[i][j] = dp[(1 << K) - 1];
        }
    }

    cin >> Q;
    while (Q--) {
        cin >> A >> L >> R;
        res = 0x7f7f7f7f7f7f7f7f;

        for (int i = 0; i < K; i++) {
            for (int j = 0; j < K; j++) {
                if (val[i][j] == INF)
                    continue;
                res = min(res, val[i][j] * R + (val[i][j] + i - j) * L);
            }
        }

        cout << res + N * A << '\n';
    }

    return 0;
}