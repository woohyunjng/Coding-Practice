#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 200001;

int dp[MAX];

void solve() {
    int N, ans = 0;
    string S;

    cin >> S, N = S.size();
    if (S[0] != 's')
        S[0] = 's', ans++;
    if (S[N - 1] != 's')
        S[N - 1] = 's', ans++;

    for (int i = 1; i <= N - 2; i++) {
        dp[i] = dp[i - 1] + (S[i] == 'u' ? 1 : 0);
        if (S[i] == 'u')
            dp[i] = min(dp[i], dp[i - 2] + (S[i - 1] == 'u' ? 1 : 0));
    }

    cout << ans + dp[N - 2] << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;

    while (T--)
        solve();

    return 0;
}