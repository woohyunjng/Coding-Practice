#include <bits/stdc++.h>
#define int long long

#define MAX 310
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int dp[MAX][MAX], A[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X = 0, Y;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> A[i];

    for (int i = 2; i <= N; i++) {
        for (int j = 1; i + j - 1 <= N; j++) {
            dp[j][i + j - 1] = dp[j + 1][i + j - 1];
            if (A[j] == A[i + j - 1])
                dp[j][i + j - 1] = max(dp[j][i + j - 1], dp[j + 1][i + j - 2] + 1);
            for (int k = j + 1; k <= i + j - 1; k++)
                dp[j][i + j - 1] = max(dp[j][i + j - 1], dp[j][k] + dp[k][i + j - 1]);
        }
    }

    cout << N - dp[1][N] << '\n';

    return 0;
}