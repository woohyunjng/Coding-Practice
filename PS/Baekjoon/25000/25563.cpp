#include <bits/stdc++.h>
#define int long long

#define MAX_N 2000000
#define MAX 21

using namespace std;

int A[MAX_N], dp[1 << MAX], cnt[1 << MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, ans[3] = {0, 0, 0};

    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> A[i], cnt[A[i]]++;
        if ((A[i] & K) == K)
            dp[A[i] ^ K]++;
    }

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < (1 << MAX); j++)
            if (j & (1 << i))
                dp[j] += dp[j ^ (1 << i)];
    }

    for (int i = 1; i <= N; i++) {
        if ((A[i] & K) != K)
            continue;
        ans[0] += dp[((1 << MAX) - 1) ^ (A[i] ^ K)];
        if (A[i] == K)
            ans[0]--;
    }

    fill(dp, dp + (1 << MAX), 0);

    for (int i = 1; i <= N; i++) {
        if ((A[i] | K) == K)
            dp[((1 << MAX) - 1) ^ A[i]]++;
    }

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < (1 << MAX); j++)
            if (j & (1 << i))
                dp[j] += dp[j ^ (1 << i)];
    }

    for (int i = 1; i <= N; i++) {
        if ((A[i] | K) != K)
            continue;
        ans[1] += dp[((1 << MAX) - 1) ^ (A[i] ^ K)];
        if (A[i] == K)
            ans[1]--;
    }

    for (int i = 1; i <= N; i++) {
        ans[2] += cnt[A[i] ^ K];
        if ((A[i] ^ K) == A[i])
            ans[2]--;
    }

    ans[0] = ans[0] / 2, ans[1] = ans[1] / 2, ans[2] = ans[2] / 2;
    cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';

    return 0;
}