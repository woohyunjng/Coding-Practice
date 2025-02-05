#include <bits/stdc++.h>
#define int long long

#define MAX 300

using namespace std;

bool dp[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, M;
    string A, B, K;

    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> A >> B >> K;
        N = A.size(), M = B.size();

        dp[0][0] = true;
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= M; j++) {
                if (i == 0 && j == 0)
                    continue;
                if (i > 0 && dp[i - 1][j] && A[i - 1] == K[i + j - 1])
                    dp[i][j] = true;
                else if (j > 0 && dp[i][j - 1] && B[j - 1] == K[i + j - 1])
                    dp[i][j] = true;
                else
                    dp[i][j] = false;
            }
        }

        if (dp[N][M])
            cout << "Data set " << t << ": yes\n";
        else
            cout << "Data set " << t << ": no\n";
    }

    return 0;
}