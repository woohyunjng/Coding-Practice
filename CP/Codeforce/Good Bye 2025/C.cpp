#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 200001;
const int INF = 0x3f3f3f3f3f3f3f3f;

int A[MAX], S[MAX], dp[MAX][2];

void solve() {
    int N, ans = -INF;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i], S[i] = S[i - 1] + A[i];

    dp[1][0] = A[1], dp[1][1] = -INF;
    for (int i = 2; i <= N; i++) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + A[i];
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) - A[i];
    }

    for (int i = 1; i <= N; i++)
        ans = max(ans, max(dp[i - 1][0], dp[i - 1][1]) - (S[N] - S[i]));

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