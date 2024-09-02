#include <bits/stdc++.h>
#define int long long

#define MAX_NUM 100
#define MAX 270100

using namespace std;

int dp[MAX][MAX_NUM];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, A, res = 0;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> A;
        dp[i][A] = 1;
        res = max(res, A);
    }

    for (int i = 1; i <= 80; i++) {
        for (int j = 1; j <= N; j++) {
            if (!dp[j][i])
                continue;
            res = max(res, i);
            if (dp[j + dp[j][i]][i] != 0)
                dp[j][i + 1] = dp[j + dp[j][i]][i] + dp[j][i];
        }
    }

    cout << res;

    return 0;
}