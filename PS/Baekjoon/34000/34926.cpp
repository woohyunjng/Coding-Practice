#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000001;

bool dp[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K;
    string S;

    cin >> N >> K >> S, dp[N - 1] = true;
    for (int i = N - 2; i >= 0; i--) {
        if (S[i] == '#')
            continue;
        dp[i] |= dp[i + 1];
        if (i + K < N)
            dp[i] |= dp[i + K];
    }

    cout << (dp[0] ? "YES" : "NO") << '\n';

    return 0;
}