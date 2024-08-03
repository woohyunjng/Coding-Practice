#include <bits/stdc++.h>
#define int long long
#define MAX 110
#define INF 0x7f7f7f7f7f7f7f7f
#define MOD 1000000000

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int dp[MAX][MAX];

int get_dp(int N, int K) {
    if (K <= 0 && N != 2)
        return 0;
    if (dp[N][K] != -1)
        return dp[N][K];

    int res = 0;

    for (int i = 3; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
            res = (res + get_dp(N - i + 2, K - j) * ((get_dp(i - 1, j) + get_dp(i - 1, j - 1)) % MOD) % MOD) % MOD;
        }
    }

    return dp[N][K] = res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K;
    cin >> N >> K;

    if (K > N - 2) {
        cout << -1 << '\n';
        return 0;
    }

    for (int i = 0; i <= N; i++)
        for (int j = 0; j <= K; j++)
            dp[i][j] = -1;

    dp[2][0] = 1;

    cout << get_dp(N, K) % MOD << '\n';

    return 0;
}