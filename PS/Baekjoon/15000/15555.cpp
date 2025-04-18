#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 3001;

int state[MAX][MAX], A[MAX][MAX], dp[MAX * 2][3];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, res = 0;
    string S;

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> S;
        for (int j = 1; j <= M; j++) {
            if (S[j - 1] == 'R')
                A[i][j] = 1;
            else if (S[j - 1] == 'G')
                A[i][j] = 2;
            else
                A[i][j] = 3;
        }
    }

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++) {
            if (A[i][j] != 2)
                continue;
            if (A[i - 1][j] == 1 && A[i + 1][j] == 3)
                state[i][j] |= 1;
            if (A[i][j - 1] == 1 && A[i][j + 1] == 3)
                state[i][j] |= 2;
        }

    for (int i = 2; i <= N + M; i++) {
        memset(dp, 0, sizeof(dp));
        for (int j = max(1ll, i - M); j <= min(N, i - 1); j++) {
            dp[j][0] = max({dp[j - 1][0], dp[j - 1][1], dp[j - 1][2]});
            if (state[j][i - j] & 1)
                dp[j][1] = max(dp[j - 1][0] + 1, dp[j - 1][1] + 1);
            if (state[j][i - j] & 2)
                dp[j][2] = max(dp[j - 1][0] + 1, dp[j - 1][2] + 1);
        }
        res += max({dp[min(N, i - 1)][0], dp[min(N, i - 1)][1], dp[min(N, i - 1)][2]});
    }

    cout << res << '\n';

    return 0;
}