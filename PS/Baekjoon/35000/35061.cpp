#include <bits/stdc++.h>
using namespace std;

const int MAX = 5001;

int N, dp[MAX][MAX][2], V[MAX][MAX], ans[MAX][MAX][4];

void calc(int X1, int Y1, int X2, int Y2, int T) {
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            dp[i][j][0] = dp[i][j][1] = 0;

    dp[X1][Y1][0] = V[X1][Y1];
    for (int i = X1; i <= X2; i++)
        for (int j = i == X1 ? Y1 + 1 : Y1; j <= Y2; j++)
            if (V[i][j])
                dp[i][j][0] = dp[i - 1][j][0] ^ dp[i][j - 1][0];

    dp[X2][Y2][1] = V[X2][Y2];
    for (int i = X2; i >= X1; i--)
        for (int j = i == X2 ? Y2 - 1 : Y2; j >= Y1; j--)
            if (V[i][j])
                dp[i][j][1] = dp[i + 1][j][1] ^ dp[i][j + 1][1];
    for (int i = X1; i <= X2; i++)
        for (int j = Y1; j <= Y2; j++)
            ans[i][j][T] = dp[i][j][0] & dp[i][j][1];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int res;
    string S;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> S;
        for (int j = 1; j <= N; j++)
            V[i][j] = S[j - 1] != '#';
    }

    calc(1, 2, N - 1, N, 0), calc(1, 2, N, N - 1, 1), calc(2, 1, N - 1, N, 2), calc(2, 1, N, N - 1, 3);

    for (int i = 1; i <= N; i++, cout << '\n')
        for (int j = 1; j <= N; j++) {
            if (!V[i][j])
                cout << '#';
            else {
                res = (ans[i][j][0] & ans[2][1][3]) ^ (ans[i][j][3] & ans[1][2][0]) ^ (ans[i][j][2] & ans[1][2][1]) ^ (ans[i][j][1] & ans[2][1][2]);
                cout << (res ? 'B' : 'W');
            }
        }

    return 0;
}