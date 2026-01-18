#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 8001;
const int INF = 0x3f3f3f3f3f3f3f3f;

int A[MAX], C[MAX],
    dp[2][MAX];

void solve() {
    int N;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    for (int i = 1; i <= N; i++)
        cin >> C[i];

    fill(dp[0], dp[0] + N + 1, INF), dp[0][0] = 0;
    for (int i = 1; i <= N; i++) {
        fill(dp[i & 1], dp[i & 1] + N + 1, INF);
        for (int j = 0; j <= N; j++)
            dp[i & 1][j] = min(dp[i & 1][j], dp[(i - 1) & 1][j] + C[i]);
        for (int j = 0; j <= N; j++)
            if (A[j] <= A[i])
                dp[i & 1][i] = min(dp[i & 1][i], dp[(i - 1) & 1][j]);
    }

    cout << *min_element(dp[N & 1], dp[N & 1] + N + 1) << '\n';
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