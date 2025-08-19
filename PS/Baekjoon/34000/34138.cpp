#include <bits/stdc++.h>
using namespace std;

const int MAX = 2001;

int A[MAX][MAX], S[MAX][MAX], ans[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X;
    string T;

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> T;
        for (int j = 1; j <= M; j++)
            A[i][j] = T[j - 1] == 'X';
    }

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            S[i][j] = S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1] + A[i][j];

    for (int i = 1 - M; i <= N - 1; i++) {
        X = 0;
        for (int j = 1; j <= N; j++) {
            if (j - i <= 0 || j - i > M || A[j][j - i] == 0) {
                X = j;
                continue;
            }

            while (S[j][j - i] + S[X][X - i] - S[X][j - i] - S[j][X - i] != j - X)
                X++;
            ans[1]++, ans[j - X + 1]--;
        }
    }

    for (int i = 1; i <= min(N, M); i++) {
        ans[i] += ans[i - 1];
        cout << ans[i] << '\n';
    }

    return 0;
}