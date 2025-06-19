#include <bits/stdc++.h>
using namespace std;

const int MAX = 10'000'000;

int dp[MAX + 1], V[MAX + 1];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int M, Q, X;

    cin >> M >> Q;
    while (M--) {
        cin >> X;
        for (int i = X; i - 1 <= MAX; i += X)
            V[i - 1] = X - 1;
        V[MAX] = max(V[MAX], MAX % X);
    }

    for (int i = MAX; i >= 1; i--)
        V[i] = max(V[i], V[i + 1] - 1);

    for (int i = 1; i <= MAX; i++)
        dp[i] = (V[i] == 0 || dp[i - V[i]] == -1) ? -1 : dp[i - V[i]] + 1;

    while (Q--) {
        cin >> X;
        if (dp[X] == -1)
            cout << "oo\n";
        else
            cout << dp[X] << '\n';
    }

    return 0;
}