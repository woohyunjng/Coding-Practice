#include <bits/stdc++.h>
#define int long long
#define MAX 50010
#define MOD 10007

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int dp[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N;
    cin >> T;

    dp[1] = 1;

    for (int i = 2; i <= 50000; i++) {
        dp[i] = (4 * dp[i - 1] - dp[i - 2] + MOD) % MOD;
    }

    while (T--) {
        cin >> N;
        cout << dp[N] << ' ' << N * (2 * dp[N] - dp[N - 1] - 1 + MOD) % MOD << '\n';
    }

    return 0;
}