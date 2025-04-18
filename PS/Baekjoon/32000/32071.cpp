#include <bits/stdc++.h>
using namespace std;

const int MAX = 3010;

int A[MAX][MAX], L[MAX][MAX], R[MAX][MAX], D[MAX][MAX][2], K[MAX][MAX], S[MAX * 3][4];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, V[2] = {0, 0}, ans = 0;
    string C;

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> C;
        for (int j = 1; j <= M; j++)
            A[i][j] = C[j - 1] - '0';
    }

    for (int i = 2; i <= N + M; i++)
        for (int j = max(1, i - M); j <= min(i - 1, N); j++) {
            if (A[j][i - j])
                L[j][i - j] = L[j - 1][i - j - 1] + 1;
            if (A[j][M + 1 - (i - j)])
                R[j][M + 1 - (i - j)] = R[j - 1][M + 2 - (i - j)] + 1;
        }

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++) {
            K[i][j] = max(0, L[i][j] + R[i][j] - 1);
            V[(i + j) & 1] = max(V[(i + j) & 1], K[i][j]);
            D[i][j][0] = L[i][j], D[i][j][1] = R[i][j];
            S[i - j + MAX][0] = max(S[i - j + MAX][0], K[i][j]);
            S[i + j][2] = max(S[i + j][2], K[i][j]);
        }

    for (int i = N - 1; i >= 1 - M; i--)
        for (int j = max(1, i + 1); j <= min(N, i + M); j++) {
            if (!A[j][j - i])
                continue;
            D[j][j - i][0] = max(D[j][j - i][0], D[j + 1][j - i - 1][0] + 1);
            S[i + MAX][1] = max(S[i + MAX][1], D[j][j - i][0]);
        }

    for (int i = N + M; i >= 2; i--)
        for (int j = max(1, i - M); j <= min(i - 1, N); j++) {
            if (!A[j][i - j])
                continue;
            D[j][i - j][1] = max(D[j][i - j][1], D[j + 1][i - j + 1][1] + 1);
            S[i][3] = max(S[i][3], D[j][i - j][1]);
        }

    ans = V[0] + V[1];

    for (int i = 1 - M; i <= N - 1; i++)
        S[i + MAX][0] = max(S[i + MAX][0], S[i - 2 + MAX][0]);
    for (int i = N - 1; i >= 1 - M; i--)
        S[i + MAX][1] = max(S[i + MAX][1], S[i + 2 + MAX][1]);
    for (int i = 1 - M; i <= N - 1; i++)
        ans = max(ans, S[i + MAX][0] + S[i + 2 + MAX][1]);

    for (int i = 2; i <= N + M; i++)
        S[i][2] = max(S[i][2], S[i - 2][2]);
    for (int i = N + M; i >= 2; i--)
        S[i][3] = max(S[i][3], S[i + 2][3]);
    for (int i = 2; i <= N + M; i++)
        ans = max(ans, S[i][2] + S[i + 2][3]);

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++) {
            if (i >= 2)
                ans = max(ans, K[i][j] + K[i - 2][j]);
            K[i][j] = max({K[i][j], K[i - 1][j - 1], K[i - 1][j + 1]});
        }

    cout << ans << '\n';

    return 0;
}