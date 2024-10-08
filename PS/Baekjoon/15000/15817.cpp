#include <bits/stdc++.h>
#define int long long

#define MAX_N 110
#define MAX 10100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int dp[MAX_N][MAX], arr[MAX_N][2];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, L, C;

    cin >> N >> X;
    for (int i = 1; i <= N; i++)
        cin >> arr[i][0] >> arr[i][1];

    dp[0][0] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= X; j++) {
            for (int k = 0; k <= arr[i][1]; k++) {
                if (j + k * arr[i][0] > X)
                    break;
                dp[i][j + k * arr[i][0]] = (dp[i][j + k * arr[i][0]] + dp[i - 1][j]);
            }
        }
    }

    cout << dp[N][X];

    return 0;
}