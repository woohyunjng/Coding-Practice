#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 2000;

int dp[MAX], A[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, ans = 0;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    for (int i = 1; i <= N; i++) {
        dp[i] = A[i];
        for (int j = 1; j < i; j++) {
            if (A[j] >= A[i])
                continue;
            dp[i] = max(dp[i], dp[j] + A[i]);
        }
    }

    for (int i = 1; i <= N; i++)
        ans = max(ans, dp[i]);
    cout << ans << '\n';

    return 0;
}