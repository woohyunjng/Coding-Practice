#include <iostream>
using namespace std;

int dp[1010][1010], A[1010];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        for (int j = 0; j <= N; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= i)
                dp[i][j] = max(dp[i][j], dp[i][j - i] + A[i]);
        }
    }

    cout << dp[N][N] << '\n';
}