#include <bits/stdc++.h>
using namespace std;

const int MAX = 1001;

bool dp[MAX][MAX];
int A[MAX], B[MAX], ansA[MAX], ansB[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X, Y;

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    for (int i = 1; i <= M; i++)
        cin >> B[i];

    dp[0][0] = true;
    for (int i = 1; i <= N; i++)
        dp[i][0] = dp[i - 1][0] && (A[i] == 0 || A[i] == i);
    for (int i = 1; i <= M; i++)
        dp[0][i] = dp[0][i - 1] && (B[i] == 0 || B[i] == i);

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++) {
            dp[i][j] = false;
            dp[i][j] |= (dp[i - 1][j] && (A[i] == 0 || A[i] == i + j));
            dp[i][j] |= (dp[i][j - 1] && (B[j] == 0 || B[j] == i + j));
        }

    X = N, Y = M;
    while (X + Y > 0) {
        if (X > 0 && dp[X - 1][Y] && (A[X] == 0 || A[X] == X + Y))
            ansA[X] = X + Y, X--;
        else
            ansB[Y] = X + Y, Y--;
    }

    for (int i = 1; i <= N; i++)
        cout << ansA[i] << ' ';
    cout << '\n';
    for (int i = 1; i <= M; i++)
        cout << ansB[i] << ' ';
    cout << '\n';

    return 0;
}