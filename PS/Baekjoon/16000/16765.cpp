#include <bits/stdc++.h>
#define int long long

#define MAX 10100
#define MAX_K 1010

using namespace std;
typedef pair<int, int> pr;

int dp[MAX], S[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, res = 0, X = 0;
    cin >> N >> K;

    for (int i = 1; i <= N; i++)
        cin >> S[i];

    for (int i = 1; i <= N; i++) {
        X = 0;
        for (int j = 1; j <= min(K, i); j++) {
            X = max(X, S[i - j + 1]);
            dp[i] = max(dp[i - j] + X * j, dp[i]);
        }
    }

    cout << dp[N] << '\n';

    return 0;
}