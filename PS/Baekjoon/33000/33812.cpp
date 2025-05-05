#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;

bitset<MAX> V, X;
int dp[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, R, Y, ans;
    string S;

    cin >> N >> K >> R;

    for (int i = 0; i < N; i++)
        V[i] = 1;

    while (R--) {
        for (int i = 0; i < K; i++)
            cin >> Y, X[Y - 1] = 1;
        cin >> S;
        V &= (S == "satisfied") ? ~X : X, X.reset();
    }

    dp[1] = 0;
    for (int i = 2; i <= N; i++) {
        if (K <= N - i)
            dp[i] = dp[max((i + 1) / 2, i - K)] + 1;
        else if (i >= K * 2)
            dp[i] = dp[i - K] + 1;
        else if (i / 2 >= K - (N - i))
            dp[i] = dp[(i + 1) / 2] + 1;
        else
            dp[i] = dp[K - (N - i)] + 1;
    }
    cout << dp[V.count()] << '\n';

    return 0;
}