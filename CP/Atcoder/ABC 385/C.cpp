#include <bits/stdc++.h>
#define int long long

#define MAX 3100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int H[MAX * 2], dp[MAX * 2][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, res = 0;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> H[i];

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (dp[i][j] == 0)
                dp[i][j] = 1;
            if (H[i + j] == H[i])
                dp[i + j][j] = max(dp[i + j][j], dp[i][j] + 1);
            res = max(res, dp[i][j]);
        }
    }

    cout << res << '\n';

    return 0;
}