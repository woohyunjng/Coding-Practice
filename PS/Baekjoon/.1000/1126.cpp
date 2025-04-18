#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAX_N = 101;
const int MAX_K = 500001;

int arr[MAX_N], dp[MAX_N][MAX_K];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, S = 0;
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> arr[i], S += arr[i];

    dp[0][arr[0]] = arr[0];
    for (int i = 1; i < N; i++) {
        dp[i][arr[i]] = max(arr[i], dp[i - 1][arr[i]]);
        for (int j = 0; j <= S; j++) {
            if (!dp[i - 1][j])
                continue;
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            dp[i][j + arr[i]] = max(dp[i - 1][j] + arr[i], dp[i - 1][j + arr[i]]);
            if (j >= arr[i])
                dp[i][j - arr[i]] = max(dp[i][j - arr[i]], max(dp[i - 1][j - arr[i]], dp[i - 1][j]));
            else
                dp[i][arr[i] - j] = max(dp[i][arr[i] - j], max(dp[i - 1][arr[i] - j], dp[i - 1][j] - j + arr[i]));
        }
    }

    cout << (dp[N - 1][0] ? dp[N - 1][0] : -1);

    return 0;
}