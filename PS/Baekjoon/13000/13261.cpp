#include <bits/stdc++.h>
#define int long long

#define MAX_L 8010
#define MAX_G 810
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;

int C[MAX_L], sm[MAX_L], dp[MAX_G][MAX_L];

void dnc_opt(int x, int l, int r, int s, int e) {
    if (l > r)
        return;
    int m = l + r >> 1, opt = -1, res = INF, val;

    for (int i = s; i <= min(m - 1, e); i++) {
        val = dp[x - 1][i] + (sm[m] - sm[i]) * (m - i);
        if (val < res)
            res = val, opt = i;
    }
    dp[x][m] = res;
    dnc_opt(x, l, m - 1, s, opt), dnc_opt(x, m + 1, r, opt, e);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int L, G;
    cin >> L >> G;

    for (int i = 1; i <= L; i++) {
        cin >> C[i], sm[i] = sm[i - 1] + C[i];
        dp[1][i] = sm[i] * i;
    }

    for (int i = 2; i <= G; i++)
        dnc_opt(i, 1, L, 0, L - 1);
    cout << dp[G][L] << '\n';

    return 0;
}