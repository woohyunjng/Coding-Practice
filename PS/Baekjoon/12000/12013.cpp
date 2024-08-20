#include <bits/stdc++.h>
#define int long long

#define MAX 5000
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int A[MAX], dp[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, res = 0;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> A[i];

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j + i - 1 <= N; j++) {
            if (i == 1)
                dp[j][j + i - 1] = A[j];
            else {
                for (int k = j; k < j + i - 1; k++) {
                    if (dp[j][k] == dp[k + 1][j + i - 1] && dp[j][k])
                        dp[j][j + i - 1] = max(dp[j][j + i - 1], dp[j][k] + 1);
                }
            }
            res = max(res, dp[j][j + i - 1]);
        }
    }

    cout << res;

    return 0;
}