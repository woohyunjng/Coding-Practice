#include <bits/stdc++.h>
#define int long long

#define MAX 1100

using namespace std;
typedef pair<int, int> pr;

pr dp[MAX][MAX];
int A[MAX][MAX], P[MAX][MAX];

pr max(pr A, pr B) {
    if (A.first == B.first)
        return {A.first, max(A.second, B.second)};
    else if (A.first > B.first)
        return A;
    return B;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X, Y;
    cin >> N;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> A[i][j];

    cin >> M;
    for (int i = 1; i <= M; i++)
        cin >> X >> Y, P[X][Y] = 1;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            dp[i][j].first += A[i][j], dp[i][j].second += P[i][j];
        }

    cout << dp[N][N].first << ' ' << dp[N][N].second << '\n';

    return 0;
}