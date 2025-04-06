#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 5001;
const int INF = 0x3f3f3f3f3f3f3f3f;

int A[MAX], dp[MAX][MAX], S[MAX];

void solve() {
    int N, ans = 0;

    cin >> N;

    for (int i = 0; i <= N; i++) {
        S[i] = -1;
        for (int j = 0; j <= N; j++)
            dp[i][j] = INF;
    }
    dp[0][0] = 0;

    for (int i = 1; i <= N; i++) {
        cin >> A[i], ans += i * i;
        S[A[i]] = i & 1;
    }

    for (int i = 1; i <= N; i++)
        for (int j = 0; j <= min(i, (N + 1) / 2); j++) {
            if (S[i] != 0 && j > 0)
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
            if (S[i] != 1)
                dp[i][j] = min(dp[i][j], dp[i - 1][j]);
            dp[i][j] += j * (N / 2 - (i - j)) + (i - j) * ((N + 1) / 2 - j);
        }

    ans -= dp[N][(N + 1) / 2];
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