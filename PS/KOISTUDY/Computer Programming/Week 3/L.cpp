#include <bits/stdc++.h>
using namespace std;

const int MAX = 1001;

int dp[MAX][MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M;
    string A, B;

    cin >> A >> B;
    N = A.size(), M = B.size();

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (A[i - 1] == B[j - 1])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
        }

    cout << dp[N][M] << '\n';

    return 0;
}