#include <bits/stdc++.h>
#define int long long

#define MAX 251
#define MAX_S 1010
#define INF 1e9

using namespace std;

int dp[2][MAX_S], W[MAX], T[MAX];

signed main() { /*
     freopen("talent.in", "r", stdin);
     freopen("talent.out", "w", stdout);*/

    int N, X, res = 0, st, en, mid;
    cin >> N >> X;

    for (int i = 1; i <= N; i++)
        cin >> W[i] >> T[i];

    st = 1, en = INF;
    while (st <= en) {
        mid = st + en >> 1;

        fill(&dp[0][0], &dp[2][0], -INF);
        dp[0][0] = 0;

        for (int i = 1; i <= N; i++)
            for (int j = 0; j <= X; j++) {
                dp[i & 1][j] = max(dp[i & 1][j], dp[~i & 1][j]);
                dp[i & 1][min(X, j + W[i])] = max(dp[i & 1][min(X, j + W[i])], dp[~i & 1][j] + 1000 * T[i] - mid * W[i]);
            }

        if (dp[N & 1][X] >= 0)
            res = mid, st = mid + 1;
        else
            en = mid - 1;
    }

    cout << res << '\n';

    return 0;
}