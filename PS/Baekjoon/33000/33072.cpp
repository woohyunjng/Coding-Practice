#include <bits/stdc++.h>
#define int long long

#define MAX 510
using namespace std;

int C[MAX], P[MAX], dp[2][MAX * MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, p, q, X, Y, st, en, mid, res;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> C[i];
    for (int i = 1; i <= N; i++)
        cin >> P[i];

    cin >> p >> q;
    for (int i = 1; i <= N; i++)
        C[i] = q * P[i] - p * C[i];

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= N * 500; j++) {
            dp[i & 1][j] = dp[i & 1 ^ 1][j];
            if (j >= P[i])
                dp[i & 1][j] = max(dp[i & 1][j], dp[i & 1 ^ 1][j - P[i]] + C[i]);
        }
    }

    cin >> Q;
    while (Q--) {
        cin >> X >> Y;
        X = p * X - q * Y;
        st = 0, en = N * 500, res = -1;
        while (st <= en) {
            mid = st + en >> 1;
            if (dp[N & 1][mid] >= X)
                en = mid - 1, res = mid;
            else
                st = mid + 1;
        }
        cout << res << '\n';
    }

    return 0;
}