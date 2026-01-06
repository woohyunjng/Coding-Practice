#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 2001;
const int INF = 0x3f3f3f3f3f3f3f3f;

int A[MAX], B[MAX], dp[MAX][MAX][2][2], V[MAX][MAX];

// [대충 골랐는지][건설 했는지]

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    for (int i = 1; i < N; i++)
        cin >> B[i];

    for (int i = 0; i <= N; i++)
        for (int j = i + 1; j <= N; j++)
            for (int x = 0; x < 2; x++)
                for (int y = 0; y < 2; y++)
                    dp[i][j][x][y] = -INF;

    for (int x = 0; x < 2; x++)
        for (int y = 0; y < 2; y++)
            dp[0][0][x][y] = -INF;
    dp[0][0][0][0] = 0;

    for (int i = 1; i <= N; i++) {
        for (int x = 0; x < 2; x++)
            for (int y = 0; y < 2; y++)
                dp[i][0][x][y] = -INF;
        dp[i][0][0][0] = 0;

        for (int j = 1; j <= i; j++) {
            dp[i][j][0][0] = V[i - 1][j];
            dp[i][j][1][0] = V[i - 1][j - 1] + A[i];
            dp[i][j][1][1] = A[i] + B[i - 1] + dp[i - 1][j - 1][1][0];

            for (int x = 0; x < 2; x++)
                for (int y = 0; y < 2; y++)
                    V[i][j] = max(V[i][j], dp[i][j][x][y]);
        }
    }

    for (int i = 1; i <= N; i++)
        cout << V[N][i] << '\n';

    return 0;
}