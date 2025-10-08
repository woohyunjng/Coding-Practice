#include <bits/stdc++.h>
using namespace std;

const int MAX = 1001;

bool dp[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;

    cin >> N, dp[0] = true;

    for (int i = 1; i <= N; i++) {
        if (i >= 1)
            dp[i] |= !dp[i - 1];
        if (i >= 3)
            dp[i] |= !dp[i - 3];
        if (i >= 4)
            dp[i] |= !dp[i - 4];
    }

    cout << (dp[N] ? "SK" : "CY") << '\n';

    return 0;
}