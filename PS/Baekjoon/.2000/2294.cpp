#include <bits/stdc++.h>
#define int long long
#define MAX 10010

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int dp[MAX], arr[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K;
    cin >> N >> K;

    fill(dp, dp + K + 1, 1e9);

    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    dp[0] = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = arr[i]; j <= K; j++) {
            dp[j] = min(dp[j], dp[j - arr[i]] + 1);
        }
    }

    if (dp[K] == 1e9)
        cout << -1;
    else
        cout << dp[K];

    return 0;
}