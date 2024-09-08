#include <bits/stdc++.h>
#define int long long

#define MAX 110
#define INF 0x7f7f7f7f7f7f7f7f

using namespace std;

int N, arr[MAX], dp[MAX][MAX][2];

int get_dp(int A, int B, int mask) {
    if (B > N || A < 1)
        return INF;
    if (dp[A][B][mask] != INF)
        return dp[A][B][mask];

    int res = INF;
    if (mask == 0) {
        if (A > 1)
            res = min(res, get_dp(A - 1, B, 0) + (A - 1 + N - B) * (arr[A] - arr[A - 1]));
        if (B < N)
            res = min(res, get_dp(A, B + 1, 1) + (A - 1 + N - B) * (arr[B + 1] - arr[A]));
    } else {
        if (A > 1)
            res = min(res, get_dp(A - 1, B, 0) + (A - 1 + N - B) * (arr[B] - arr[A - 1]));
        if (B < N)
            res = min(res, get_dp(A, B + 1, 1) + (A - 1 + N - B) * (arr[B + 1] - arr[B]));
    }

    return dp[A][B][mask] = res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, res, A, X;
    cin >> T;

    while (T--) {
        cin >> N >> A;
        for (int i = 2; i <= N; i++) {
            cin >> arr[i];
            arr[i] += arr[i - 1];
        }

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++)
                dp[i][j][0] = dp[i][j][1] = INF;
        }

        dp[1][N][0] = dp[1][N][1] = 0;
        res = min(get_dp(A, A, 0), get_dp(A, A, 1));

        cout << res << '\n';
    }

    return 0;
}