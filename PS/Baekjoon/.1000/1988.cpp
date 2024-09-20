#include <bits/stdc++.h>
#define int long long

#define MAX 3100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int arr[MAX], dp[2][MAX][2];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, B;
    cin >> N >> B;

    for (int j = 0; j <= B; j++)
        dp[0][j][1] = dp[1][j][1] = -1;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        for (int k = 1; k <= min(B, i); k++) {
            if (dp[i & 1 ^ 1][k - 1][1] != -1)
                dp[i & 1][k][1] = max(dp[i & 1 ^ 1][k - 1][0], dp[i & 1 ^ 1][k - 1][1] + arr[i]);
            else
                dp[i & 1][k][1] = dp[i & 1 ^ 1][k - 1][0];
            if (dp[i & 1 ^ 1][k][1] != -1)
                dp[i & 1][k][0] = max(dp[i & 1 ^ 1][k][0], dp[i & 1 ^ 1][k][1]);
            else
                dp[i & 1][k][0] = dp[i & 1 ^ 1][k][0];
        }
    }

    cout << max(dp[N & 1][B][0], dp[N & 1][B][1]);

    return 0;
}