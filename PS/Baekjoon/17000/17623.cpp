#include <bits/stdc++.h>
using namespace std;

const int MAX = 1001;

string C = " (){}[]";

string dp[MAX];

string min(string X, string Y) {
    if (X.size() < Y.size())
        return X;
    else if (X.size() > Y.size())
        return Y;
    else if (X < Y)
        return X;
    else
        return Y;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N = 1000;
    string S;

    dp[1] = "12", dp[2] = "34", dp[3] = "56";

    for (int i = 4; i <= N; i++) {
        dp[i] = string(N, '7');
        if (i % 2 == 0)
            dp[i] = min(dp[i], "1" + dp[i / 2] + "2");
        if (i % 3 == 0)
            dp[i] = min(dp[i], "3" + dp[i / 3] + "4");
        if (i % 5 == 0)
            dp[i] = min(dp[i], "5" + dp[i / 5] + "6");
        for (int j = 1; j <= i - 1; j++)
            dp[i] = min(dp[i], dp[j] + dp[i - j]);
    }

    for (int i = 1; i <= N; i++) {
        S = dp[i], dp[i] = "";
        for (char j : S)
            dp[i] += C[j - '0'];
    }

    cin >> T;
    while (T--) {
        cin >> N;
        cout << dp[N] << '\n';
    }

    return 0;
}