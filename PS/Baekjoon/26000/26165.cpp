#include <bits/stdc++.h>
#define int long long

#define MAX 50000
#define SMAX 70
#define MOD 1000000007

using namespace std;

int N, A[MAX], C[MAX], _dp[SMAX][SMAX][SMAX][2];

int dp(int l, int r, int k, int cur) {
    if (_dp[l][r][k][cur] != -1)
        return _dp[l][r][k][cur];

    int v = cur == 0 ? l : r, x;
    if (l == r)
        x = 0;
    else if (cur == 0 && k == 0)
        x = C[l + 1] - C[l];
    else if (cur == 0 && k == 1)
        x = C[r] - C[l];
    else if (cur == 1 && k == 0)
        x = C[r] - C[l];
    else
        x = C[r] - C[r - 1];

    int to_r = r < N ? C[r + 1] - C[v] : -1;
    int to_l = l > 1 ? C[v] - C[l - 1] : -1;

    if (1 < l && r < N) {
        if (min(to_r, to_l) < 2 * x)
            return 0;

        if (to_r < to_l)
            return _dp[l][r][k][cur] = dp(l, r + 1, cur, 1);
        else if (to_r > to_l)
            return _dp[l][r][k][cur] = dp(l - 1, r, cur, 0);
        else
            return _dp[l][r][k][cur] = (dp(l, r + 1, cur, 1) + dp(l - 1, r, cur, 0)) % MOD;
    } else if (1 < l)
        return _dp[l][r][k][cur] = to_l >= 2 * x ? dp(l - 1, r, cur, 0) : 0;
    else if (r < N)
        return _dp[l][r][k][cur] = to_r >= 2 * x ? dp(l, r + 1, cur, 1) : 0;
    else
        return _dp[l][r][k][cur] = 1;
}

int get() {
    for (int i = 1; i <= N; i++)
        for (int j = i; j <= N; j++)
            _dp[i][j][0][0] = _dp[i][j][0][1] = _dp[i][j][1][0] = _dp[i][j][1][1] = -1;

    for (int i = 1; i <= N; i++)
        C[i] = A[i];
    sort(C + 1, C + N + 1);

    if (C[N] - C[1] < (1ll << (N - 2)))
        return 0;

    int res = 0;
    for (int i = 1; i <= N; i++)
        res = (res + dp(i, i, 0, 0)) % MOD;
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int Q, X, Y;

    cin >> N >> Q;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    if (N >= 65) {
        Q++;
        while (Q--)
            cout << 0 << '\n';
        return 0;
    }

    cout << get() << '\n';
    while (Q--) {
        cin >> X >> Y, A[X] = Y;
        cout << get() << '\n';
    }
}