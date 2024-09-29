#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x3f3f3f3f3f3f3f3f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int arr[MAX], dp[MAX][100];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, k, s, res = 0;
    cin >> N >> k >> s;

    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    if (k >= 44) {
        cout << "MEGA";
        return 0;
    }

    fill(&dp[0][0], &dp[N][100], -INF);

    dp[0][0] = s;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= k; j++) {
            if (dp[i - 1][j] + arr[i] > 0)
                dp[i][j] = dp[i - 1][j] + arr[i];
            if (j > 0)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] * 2);

            if (dp[i][j] >= (1ll << 44)) {
                cout << "MEGA";
                return 0;
            }
        }
    }

    for (int i = 0; i <= k; i++)
        res = max(res, dp[N][i]);

    if (res > 100000000000)
        cout << "MEGA";
    else
        cout << (res <= 0 ? -1 : res);

    return 0;
}