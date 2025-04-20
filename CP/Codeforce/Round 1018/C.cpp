#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 1001;
const int INF = 0x3f3f3f3f3f3f3f3f;

int H[MAX][MAX], A[MAX], B[MAX], V[MAX], dp[MAX][2];

void solve() {
    int N, ans = 0;
    bool flag = true;

    cin >> N;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> H[i][j];

    for (int i = 1; i <= N; i++)
        cin >> A[i];
    for (int i = 1; i <= N; i++)
        cin >> B[i];

    for (int i = 1; i < N; i++) {
        V[i + 1] = 7;
        for (int j = 1; j <= N; j++) {
            if (H[i][j] - H[i + 1][j] == 0)
                V[i + 1] &= ~(1 << 0);
            else if (H[i][j] - H[i + 1][j] == 1)
                V[i + 1] &= ~(1 << 1);
            else if (H[i][j] - H[i + 1][j] == -1)
                V[i + 1] &= ~(1 << 2);
        }
        flag &= (V[i + 1] != 0);
    }

    dp[1][0] = 0, dp[1][1] = A[1];
    for (int i = 2; i <= N; i++) {
        dp[i][0] = dp[i][1] = INF;
        if (V[i] & (1 << 0))
            dp[i][0] = min(dp[i][0], dp[i - 1][0]), dp[i][1] = min(dp[i][1], dp[i - 1][1] + A[i]);
        if (V[i] & (1 << 1))
            dp[i][1] = min(dp[i][1], dp[i - 1][0] + A[i]);
        if (V[i] & (1 << 2))
            dp[i][0] = min(dp[i][0], dp[i - 1][1]);
    }

    if (min(dp[N][0], dp[N][1]) >= INF)
        flag = false;
    ans += min(dp[N][0], dp[N][1]);

    for (int i = 1; i < N; i++) {
        V[i + 1] = 7;
        for (int j = 1; j <= N; j++) {
            if (H[j][i] - H[j][i + 1] == 0)
                V[i + 1] &= ~(1 << 0);
            else if (H[j][i] - H[j][i + 1] == 1)
                V[i + 1] &= ~(1 << 1);
            else if (H[j][i] - H[j][i + 1] == -1)
                V[i + 1] &= ~(1 << 2);
        }
        flag &= (V[i + 1] != 0);
    }

    dp[1][0] = 0, dp[1][1] = B[1];
    for (int i = 2; i <= N; i++) {
        dp[i][0] = dp[i][1] = INF;
        if (V[i] & (1 << 0))
            dp[i][0] = min(dp[i][0], dp[i - 1][0]), dp[i][1] = min(dp[i][1], dp[i - 1][1] + B[i]);
        if (V[i] & (1 << 1))
            dp[i][1] = min(dp[i][1], dp[i - 1][0] + B[i]);
        if (V[i] & (1 << 2))
            dp[i][0] = min(dp[i][0], dp[i - 1][1]);
    }

    if (min(dp[N][0], dp[N][1]) >= INF)
        flag = false;
    ans += min(dp[N][0], dp[N][1]);

    if (!flag)
        ans = -1;
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;

    while (T--)
        solve();

    return 0;
}