#include <bits/stdc++.h>
#define int long long

#define MAX 10010
using namespace std;

int dp[2][MAX], arr[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;

    for (int i = 1; i < N; i++)
        cin >> arr[i];

    fill(dp[0], dp[0] + N + 1, -1);
    dp[0][0] = 0;

    for (int i = 1; i <= N; i++) {
        fill(dp[i & 1], dp[i & 1] + N + 1, -1);
        for (int j = 1; j <= i; j++) {
            dp[i & 1][j] = INF;
            if (dp[(i & 1) ^ 1][j - 1] != -1)
                dp[i & 1][j] = min(dp[i & 1][j], dp[(i & 1) ^ 1][j - 1]);
            if (dp[(i & 1) ^ 1][i - j] != -1 && i != 1)
                dp[i & 1][j] = min(dp[i & 1][j], dp[(i & 1) ^ 1][i - j] + arr[i - 1]);
        }
    }

    cout << dp[N & 1][N >> 1];

    return 0;
}