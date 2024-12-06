#include <bits/stdc++.h>
#define int long long

#define MAX 100100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int dp[MAX][30][3], A[MAX];

int win(int A, int B) {
    if (A == 0)
        return B == 1;
    if (A == 1)
        return B == 2;
    if (A == 2)
        return B == 0;
    return 0;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, res = 0;
    char X;
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> X;
        A[i] = X == 'H' ? 0 : (X == 'P' ? 1 : 2);
    }

    fill(&dp[0][0][0], &dp[MAX][0][0], -INF);
    dp[0][0][0] = dp[0][0][1] = dp[0][0][2] = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K + 1; j++) {
            for (int k = 0; k < 3; k++) {
                dp[i][j][k] = *max_element(dp[i - 1][j - 1], dp[i - 1][j - 1] + 3) + win(A[i], k);
                dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + win(A[i], k));
                res = max(res, dp[i][j][k]);
            }
        }
    }

    cout << res << '\n';

    return 0;
}