#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 21;

int _dp[MAX][MAX][MAX];

int dp(int A, int B, int C) {
    if (A <= 0 || B <= 0 || C <= 0)
        return 1;
    if (A > 20 || B > 20 || C > 20)
        return dp(20, 20, 20);
    if (_dp[A][B][C] != -1)
        return _dp[A][B][C];
    if (A < B && B < C)
        return _dp[A][B][C] = dp(A, B, C - 1) + dp(A, B - 1, C - 1) - dp(A, B - 1, C);
    return _dp[A][B][C] = dp(A - 1, B, C) + dp(A - 1, B - 1, C) + dp(A - 1, B, C - 1) - dp(A - 1, B - 1, C - 1);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int A, B, C;

    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            for (int k = 0; k < MAX; k++)
                _dp[i][j][k] = -1;

    while (true) {
        cin >> A >> B >> C;
        if (A == -1 && B == -1 && C == -1)
            break;
        cout << "w(" << A << ", " << B << ", " << C << ") = " << dp(A, B, C) << '\n';
    }

    return 0;
}