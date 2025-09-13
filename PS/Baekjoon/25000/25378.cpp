#include <bits/stdc++.h>
using namespace std;

const int MAX = 2501;

int A[MAX], dp[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i], dp[i] = dp[i - 1] + 1;
        X = A[i];
        for (int j = i - 1; j >= 1; j--) {
            X = A[j] - X;
            if (X == 0)
                dp[i] = min(dp[i], dp[j - 1] + i - j);
            if (X < 0)
                break;
        }
    }

    cout << dp[N] << '\n';

    return 0;
}