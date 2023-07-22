#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, K, W, V;
    cin >> N >> K;

    int arr[N + 1][2] = {};

    for (int i = 1 ; i <= N ; i ++) {
        cin >> W >> V;
        arr[i][0] = W;
        arr[i][1] = V;
    }

    int dp[N + 1][K + 1] = {};
    for (int i = 1 ; i <= N ; i ++) {
        for (int j = 1 ; j <= K ; j ++) {
            if (arr[i][0] <= j) {
                dp[i][j] = dp[i - 1][j - arr[i][0]] + arr[i][1];
            }
            dp[i][j] = max(dp[i - 1][j], dp[i][j]);
            dp[i][j] = max(dp[i][j - 1], dp[i][j]);
        }
    }


    cout << dp[N][K];
}
