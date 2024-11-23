#include <bits/stdc++.h>
#define int long long

#define MAX 1000100
#define MOD 998244353
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int dp[MAX], X[MAX];

void solve() {
    int N;
    cin >> N;

    cout << dp[N - 2] << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;

    dp[0] = 1, dp[1] = 2;
    X[0] = 0;

    for (int i = 1; i < MAX; i++)
        X[i] = ((i + 3) * X[i - 1] + i + 1) % MOD;

    for (int i = 2; i < MAX; i++)
        dp[i] = ((X[i - 1] - X[i - 2] + MOD) % MOD + 2 * dp[i - 1] - dp[i - 2] + MOD) % MOD;

    while (T--)
        solve();

    return 0;
}