#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 21;

int dp[1 << MAX], A[1 << MAX], cnt[1 << MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, ans;

    cin >> T;
    while (T--) {
        cin >> N, ans = N;
        fill(dp, dp + (1 << MAX), 0), fill(cnt, cnt + (1 << MAX), 0);

        for (int i = 1; i <= N; i++)
            cin >> A[i], dp[A[i]]++, cnt[A[i]]++;

        for (int i = 0; i < MAX; i++)
            for (int j = 0; j < (1 << MAX); j++)
                if (!(j & (1 << i)))
                    dp[j ^ (1 << i)] += dp[j];

        for (int i = 1; i <= N; i++)
            ans += dp[A[i]] - cnt[A[i]];
        for (int i = 0; i < (1 << MAX); i++)
            ans += cnt[i] * (cnt[i] - 1);

        cout << ans << '\n';
    }

    return 0;
}