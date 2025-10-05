#include <bits/stdc++.h>
#define ll __int128_t
using namespace std;

const int MAX = 30;
const int TEN = 10;
const ll INF = (ll)0x3f3f3f3f3f3f3f3f * 100;

ll dp[MAX][1 << TEN][2], A[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, S, K;
    ll ans = INF;
    string _S;

    cin >> _S >> K, S = _S.size();
    for (int i = 1; i <= S; i++)
        A[i] = _S[i - 1] - '0';
    N = max(K + 1, S + 1);

    for (int i = S; i >= 1; i--)
        A[N - S + i] = A[i];
    for (int i = 1; i <= N - S; i++)
        A[i] = 0;

    for (int i = 0; i <= N; i++)
        for (int j = 0; j < (1 << TEN); j++)
            for (int k = 0; k < 2; k++)
                dp[i][j][k] = INF;

    dp[0][0][0] = 0;
    for (int i = 1; i <= N; i++)
        for (int j = 0; j < (1 << TEN); j++)
            for (int k = 0; k < 2; k++) {
                if (dp[i - 1][j][k] == INF)
                    continue;
                for (int l = 0; l < TEN; l++) {
                    if (k == 0 && l < A[i])
                        continue;
                    if (dp[i - 1][j][k] == 0 && l == 0)
                        dp[i][j][0] = min(dp[i][j][0], (ll)0);
                    else
                        dp[i][j | (1 << l)][k | (l > A[i])] = min((ll)dp[i][j | (1 << l)][k | (l > A[i])], (ll)dp[i - 1][j][k] * 10 + (ll)l);
                }
            }

    for (int j = 0; j < (1 << TEN); j++)
        if (__builtin_popcountll(j) == K)
            ans = min(ans, min(dp[N][j][0], dp[N][j][1]));

    cout << (long long)ans << '\n';

    return 0;
}