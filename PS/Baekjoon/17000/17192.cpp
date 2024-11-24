#include <bits/stdc++.h>
#define int long long

#define MAX 410
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int dp[MAX][MAX], A[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, X, Y;
    cin >> N >> K;
    K++;

    for (int i = 1; i <= N; i++)
        cin >> A[i], dp[i][0] = INF;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= min(i, K); j++) {
            X = 0, Y = 0, dp[i][j] = INF;
            for (int k = i; k >= 1; k--) {
                X = max(X, A[k]), Y += A[k];
                dp[i][j] = min(dp[i][j], dp[k - 1][j - 1] + X * (i - k + 1) - Y);
            }
        }
    }

    cout << dp[N][K] << '\n';

    return 0;
}