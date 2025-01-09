#include <bits/stdc++.h>
#define int long long

#define MAX 110
#define MAX_S 5010
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;

int dp[MAX][MAX_S], S[MAX], Q[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, A, B, res = 0;
    cin >> N >> A >> B;

    for (int i = 1; i <= N; i++)
        cin >> S[i] >> Q[i];

    fill(&dp[0][0], &dp[MAX][0], INF);
    dp[0][0] = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = i; j >= 1; j--) {
            for (int k = A; k >= S[i]; k--) {
                dp[j][k] = min(dp[j][k], dp[j - 1][k - S[i]] + Q[i]);
                if (dp[j][k] <= B)
                    res = max(res, j);
            }
        }
    }

    cout << res << '\n';

    return 0;
}