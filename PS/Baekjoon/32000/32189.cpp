#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 3001;

int dp[MAX][MAX];

int calc(string S, string T) {
    int N = S.size(), M = T.size();
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (S[i - 1] == T[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return min(N, M) - dp[N][M];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    string S;
    int N, ans = 0;

    cin >> S, N = S.size();

    ans = max(ans, calc(S.substr(0, N / 2), S.substr(N / 2, N - N / 2)));
    ans = max(ans, calc(S.substr(0, N / 2 + 1), S.substr(N / 2 + 1, N - (N / 2 + 1))));

    cout << ans << '\n';

    return 0;
}