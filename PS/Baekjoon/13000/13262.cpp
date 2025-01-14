#include <bits/stdc++.h>
#define int long long

#define MAX 5100
using namespace std;

int dp[MAX][MAX], A[MAX], C[MAX][MAX];

void dnc_opt(int x, int l, int r, int s, int e) {
    if (l > r)
        return;
    int mid = l + r >> 1, opt = s, val, res = -1;

    for (int i = s; i <= min(mid - 1, e); i++) {
        val = dp[x - 1][i] + C[i + 1][mid];
        if (val > res)
            res = val, opt = i;
    }

    dp[x][mid] = res;
    dnc_opt(x, l, mid - 1, s, opt), dnc_opt(x, mid + 1, r, opt, e);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K;
    cin >> N >> K;

    for (int i = 1; i <= N; i++)
        cin >> A[i];

    for (int i = 1; i <= N; i++) {
        C[i][i] = A[i];
        for (int j = i + 1; j <= N; j++)
            C[i][j] = C[i][j - 1] | A[j];
    }

    for (int i = 1; i <= N; i++)
        dp[1][i] = C[1][i];

    for (int i = 2; i <= K; i++)
        dnc_opt(i, 1, N, 0, N - 1);
    cout << dp[K][N] << '\n';

    return 0;
}