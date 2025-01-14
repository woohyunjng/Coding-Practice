#include <bits/stdc++.h>
#define int long long

#define MAX 4100
#define MAX_K 810
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;

int U[MAX][MAX], sm[MAX][MAX], C[MAX][MAX], dp[MAX_K][MAX];

void dnc_opt(int x, int l, int r, int s, int e) {
    if (l > r)
        return;
    int mid = l + r >> 1, opt = s, res = INF, val;

    for (int i = s; i <= min(mid, e); i++) {
        val = dp[x - 1][i] + C[i + 1][mid];
        if (val < res)
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
        for (int j = 1; j <= N; j++) {
            cin >> U[i][j];
            sm[i][j] = U[i][j] + sm[i - 1][j] + sm[i][j - 1] - sm[i - 1][j - 1];
        }

    for (int i = 1; i <= N; i++)
        for (int j = i; j <= N; j++)
            C[i][j] = (sm[j][j] - sm[i - 1][j] - sm[j][i - 1] + sm[i - 1][i - 1]) / 2;

    for (int i = 1; i <= N; i++)
        dp[1][i] = C[1][i];

    for (int i = 2; i <= K; i++)
        dnc_opt(i, 1, N, 0, N - 1);
    cout << dp[K][N] << '\n';

    return 0;
}