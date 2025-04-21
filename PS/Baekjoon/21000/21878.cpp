#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 1001;
const int INF = 0x3f3f3f3f3f3f3f3f;

int K[MAX], dp[MAX][MAX][2][3];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, S, V, X, Y;

    cin >> N >> S >> V;
    for (int i = 1; i < N; i++)
        cin >> K[i];

    X = S / V, Y = S % V;
    if (Y == 0)
        X--, Y = V;

    function<int(int)> val = [&](int x) { return x == 0 ? 0 : (x == 1 ? V : Y); };

    for (int i = 1; i <= N; i++)
        for (int j = 0; j <= X; j++)
            for (int k = 0; k < 2; k++)
                for (int l = 0; l < 3; l++)
                    dp[i][j][k][l] = INF;

    dp[1][0][0][0] = dp[1][1][0][1] = dp[1][0][1][2] = 0;

    for (int i = 2; i <= N; i++)
        for (int j = 0; j <= X; j++)
            for (int k = 0; k < 2; k++)
                for (int l = 0; l < 3; l++) {
                    if ((l == 2 && k == 0) || (l == 1 && j == 0))
                        continue;
                    for (int m = 0; m < 3; m++) {
                        if (l == 0)
                            dp[i][j][k][l] = min(dp[i][j][k][l], dp[i - 1][j][k][m] + K[i - 1] * val(m) * val(l));
                        else if (l == 1)
                            dp[i][j][k][l] = min(dp[i][j][k][l], dp[i - 1][j - 1][k][m] + K[i - 1] * val(m) * val(l));
                        else if (l == 2)
                            dp[i][j][k][l] = min(dp[i][j][k][l], dp[i - 1][j][0][m] + K[i - 1] * val(m) * val(l));
                    }
                }

    cout << min({dp[N][X][1][0], dp[N][X][1][1], dp[N][X][1][2]}) << '\n';

    return 0;
}