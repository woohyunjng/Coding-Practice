#include <bits/stdc++.h>
using namespace std;

const int MAX = 250002;

int X[MAX], dp[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> X[i], dp[X[i]] = MAX;

    for (int i = 1; i < N; i++)
        if (X[i + 1] - X[i] == 1) {
            cout << -1 << '\n';
            return 0;
        }

    for (int i = 1; i <= X[N] + 1; i++) {
        if (dp[i] == MAX)
            continue;
        dp[i] = min(dp[i - 1], dp[i - 2]) + 1;
    }

    cout << dp[X[N] + 1] << '\n';

    return 0;
}