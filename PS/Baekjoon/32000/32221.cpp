#include <bits/stdc++.h>
#define int long long

#define MAX 1000010
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int arr[MAX], dp[MAX][2], sm[MAX][2];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K;
    cin >> N >> K;

    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    dp[1][1] = 1;
    sm[1][1] = 1;
    for (int i = 2; i <= N + 1; i++) {
        sm[i][1] = sm[i - 1][1];
        if (arr[i - 1] == 0)
            sm[i][1] += dp[i - 1][1];
        dp[i][1] = (dp[i][1] + sm[i][1] - sm[max(0ll, i - K - 1)][1] + MOD * 3ll) % MOD;
    }

    dp[1][0] = 1;
    sm[1][0] = 1;
    for (int i = 2; i <= N + 1; i++) {
        sm[i][0] = sm[i - 1][0];
        if (arr[i - 1] == 0)
            sm[i][0] += dp[i - 1][0];
        dp[i][0] = (dp[i][0] + sm[i][0] - sm[max(0ll, i - K)][0] + MOD * 3ll) % MOD;
    }

    cout << (dp[N + 1][1] - dp[N + 1][0] + MOD * 10ll) % MOD;

    return 0;
}