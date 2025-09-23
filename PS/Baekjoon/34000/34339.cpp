#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 100001;

int A[MAX], dp[101];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, ans = 0;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    for (int i = 1; i <= N; i++) {
        for (int j = 100 - A[i]; j >= 0; j--)
            dp[j + A[i]] = max(dp[j + A[i]], dp[j]);
        dp[A[i]] = i;
        ans += dp[100];
    }

    cout << ans << '\n';

    return 0;
}