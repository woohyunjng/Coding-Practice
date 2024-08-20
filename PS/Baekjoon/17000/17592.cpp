#include <bits/stdc++.h>
#define int long long

#define MAX 510
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int M[MAX][MAX], dp[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++)
            cin >> M[i][j];
    }

    for (int i = 2; i <= N; i++) {
        for (int j = 1; j + i - 1 <= N; j++) {
            if (M[j][j + i - 1])
                dp[j][j + i - 1] = dp[j + 1][j + i - 2] + 1;
            for (int k = j; k < j + i - 1; k++)
                dp[j][j + i - 1] = max(dp[j][j + i - 1], dp[j][k] + dp[k + 1][j + i - 1]);
        }
    }

    cout << dp[1][N];

    return 0;
}