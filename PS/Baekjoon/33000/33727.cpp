#include <bits/stdc++.h>
using namespace std;

const int MAX = 5000001;
const int MAX_B = 21;

int A[MAX], dp[1 << MAX_B];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X = 0, ans = 0, K, V;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i], A[i]--, X = max(X, A[i]);
    ans = X + 1;

    for (int i = 0; i < (1 << (X + 1)); i++) {
        while ((dp[i] + 2 <= N && (i & (1 << A[dp[i] + 2]))) || (dp[i] + 1 <= N && (i & (1 << A[dp[i] + 1]))))
            dp[i]++;
        if (dp[i] >= N - 1)
            ans = min(ans, __builtin_popcount(i));

        for (int j = 1; j <= X; j++)
            dp[(i ^ (1 << (j - 1))) | (1 << j)] = max(dp[(i ^ (1 << (j - 1))) | (1 << j)], dp[i]);
        dp[i | 1] = max(dp[i | 1], dp[i]);
    }

    cout << ans << '\n';

    return 0;
}