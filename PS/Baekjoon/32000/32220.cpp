#include <bits/stdc++.h>
#define int long long

#define MAX 3100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int arr[MAX], dp[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K;
    cin >> N >> K;

    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    dp[0][K] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= K; j++) {
            if (i - j == 0) {
                dp[i][K] = (dp[i][K] + 1) % MOD;
                break;
            }
            dp[i][K] = (dp[i][K] + dp[i - 1 - j][K]) % MOD;
        }
    }

    dp[0][K - 1] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= K - 1; j++) {
            if (i - j == 0) {
                dp[i][K - 1] = (dp[i][K - 1] + 1) % MOD;
                break;
            }
            dp[i][K - 1] = (dp[i][K - 1] + dp[i - 1 - j][K - 1]) % MOD;
        }
    }

    cout << (dp[N][K] - dp[N][K - 1] + MOD * 10ll) % MOD;

    return 0;
}