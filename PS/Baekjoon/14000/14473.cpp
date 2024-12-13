#include <bits/stdc++.h>

#define MAX 100100
#define MAX_COLOR 21

using namespace std;

int A[MAX], sm[MAX][MAX_COLOR], dp[1 << MAX_COLOR];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X;
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        cin >> A[i], sm[i][--A[i]] = 1;

    for (int i = 1; i <= N; i++)
        for (int j = 0; j < M; j++)
            sm[i][j] += sm[i - 1][j];

    for (int i = 0; i < M; i++)
        dp[1 << i] = sm[sm[N][i]][i];

    for (int i = 0; i < (1 << M); i++) {
        X = 0;
        for (int j = 0; j < M; j++)
            if (i & (1 << j))
                X += sm[N][j];

        for (int j = 0; j < M; j++)
            if (!(i & (1 << j)))
                dp[i | (1 << j)] = max(dp[i | (1 << j)], dp[i] + sm[X + sm[N][j]][j] - sm[X][j]);
    }

    cout << N - dp[(1 << M) - 1] << '\n';

    return 0;
}