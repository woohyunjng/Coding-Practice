#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 100000
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int dp[60][3100];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, S, res = 0;
    cin >> N >> M >> S;

    dp[0][0] = 1;
    for (int i = 1; i <= M; i++) {
        for (int j = N * N; j > 0; j--) {
            for (int k = i; k <= S; k++)
                dp[j][k] = (dp[j][k] + dp[j - 1][k - i]) % MOD;
        }
    }

    cout << dp[N * N][S];

    return 0;
}