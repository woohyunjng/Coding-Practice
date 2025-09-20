#include <bits/stdc++.h>
using namespace std;

const int MAX = 2001;

int A[MAX][MAX], S[MAX][MAX], V[MAX][MAX], ans[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, Q, X, Y;
    string _S;

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> _S;
        for (int j = 1; j <= M; j++)
            A[i][j] = _S[j - 1] == '#';
    }

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            S[i][j] = S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1] + A[i][j];

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++) {
            X = i, Y = j;
            for (int k = 10; k >= 0; k--) {
                if (X - (1 << k) < 0 || Y - (1 << k) < 0)
                    continue;
                if (S[i][j] - S[X - (1 << k)][j] - S[i][Y - (1 << k)] + S[X - (1 << k)][Y - (1 << k)] == 0) {
                    V[i][j] |= (1 << k);
                    X -= (1 << k), Y -= (1 << k);
                }
            }
        }

    for (int k = 10; k >= 0; k--) {
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= M; j++) {
                if (V[i][j] >= (1 << k)) {
                    ans[i][j] = max(ans[i][j], V[i][j]);
                    ans[i - V[i][j] + (1 << k)][j] = max(ans[i - V[i][j] + (1 << k)][j], V[i][j]);
                    ans[i][j - V[i][j] + (1 << k)] = max(ans[i][j - V[i][j] + (1 << k)], V[i][j]);
                    ans[i - V[i][j] + (1 << k)][j - V[i][j] + (1 << k)] = max(ans[i - V[i][j] + (1 << k)][j - V[i][j] + (1 << k)], V[i][j]);
                    V[i][j] = 0;
                }
            }
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= M; j++) {
                if (k != 0 && min(i, j) >= (1 << (k - 1))) {
                    ans[i - (1 << (k - 1))][j] = max(ans[i - (1 << (k - 1))][j], ans[i][j]);
                    ans[i][j - (1 << (k - 1))] = max(ans[i][j - (1 << (k - 1))], ans[i][j]);
                    ans[i - (1 << (k - 1))][j - (1 << (k - 1))] = max(ans[i - (1 << (k - 1))][j - (1 << (k - 1))], ans[i][j]);
                }
            }
    }

    cin >> Q;
    while (Q--) {
        cin >> X >> Y;
        cout << ans[X][Y] * ans[X][Y] << '\n';
    }

    return 0;
}