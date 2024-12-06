#include <bits/stdc++.h>
#define int long long

#define MAX 1100
#define MOD 1000000007
#define INF 0x3f3f3f3f3f3f3f3f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int dp[MAX][MAX][2], A[MAX][2], B[MAX][2];

int dis(int X1, int Y1, int X2, int Y2) { return (X1 - X2) * (X1 - X2) + (Y1 - Y2) * (Y1 - Y2); }

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int H, G;
    cin >> H >> G;

    for (int i = 1; i <= H; i++)
        cin >> A[i][0] >> A[i][1];
    for (int i = 1; i <= G; i++)
        cin >> B[i][0] >> B[i][1];

    fill(&dp[0][0][0], &dp[MAX][0][0], INF);

    dp[1][0][0] = dp[1][0][1] = 0;
    for (int i = 2; i <= H; i++)
        dp[i][0][0] = dp[i - 1][0][0] + dis(A[i][0], A[i][1], A[i - 1][0], A[i - 1][1]);
    B[0][0] = A[1][0], B[0][1] = A[1][1];
    for (int i = 1; i <= G; i++)
        dp[1][i][1] = dp[1][i - 1][1] + dis(B[i][0], B[i][1], B[i - 1][0], B[i - 1][1]);

    for (int i = 2; i <= H; i++)
        for (int j = 1; j <= G; j++) {
            dp[i][j][0] = min(
                dp[i - 1][j][0] + dis(A[i][0], A[i][1], A[i - 1][0], A[i - 1][1]),
                dp[i - 1][j][1] + dis(A[i][0], A[i][1], B[j][0], B[j][1]));
            dp[i][j][1] = min(
                dp[i][j - 1][0] + dis(A[i][0], A[i][1], B[j][0], B[j][1]),
                dp[i][j - 1][1] + dis(B[j][0], B[j][1], B[j - 1][0], B[j - 1][1]));
        }

    cout << dp[H][G][0] << '\n';

    return 0;
}