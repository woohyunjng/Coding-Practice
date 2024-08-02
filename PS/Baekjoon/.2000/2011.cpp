#include <bits/stdc++.h>
#define int long long
#define MAX 5010
#define MOD 1000000

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int dp[MAX], arr[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K;
    string S;
    cin >> S;

    N = S.size();
    for (int i = 1; i <= N; i++)
        arr[i] = S[i - 1] - '0';

    dp[0] = 1;

    for (int i = 1; i <= N; i++) {
        K = arr[i - 1] * 10 + arr[i];
        if (1 <= arr[i])
            dp[i] = dp[i - 1];
        if (10 <= K && K <= 26)
            dp[i] = (dp[i] + dp[i - 2]) % MOD;
    }

    cout << dp[N];

    return 0;
}