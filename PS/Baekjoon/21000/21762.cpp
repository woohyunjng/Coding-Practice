#include <bits/stdc++.h>
using namespace std;

const int MAX = 200001;

int X[MAX], Y[MAX], W[MAX], L[MAX][2], R[MAX][2], S[MAX][30][2];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, M, K;
    string _X, _Y, _W;
    bool ans;

    cin >> T;
    while (T--) {
        cin >> _X >> _Y >> _W, ans = false;

        N = _X.size(), M = _Y.size(), K = _W.size();

        for (int i = 0; i < N; i++) {
            X[i + 1] = _X[i] - 'a' + 1;
            for (int j = 1; j <= 26; j++)
                S[i + 1][j][0] = S[i][j][0];
            S[i + 1][X[i + 1]][0]++;
        }

        for (int i = 0; i < M; i++) {
            Y[i + 1] = _Y[i] - 'a' + 1;
            for (int j = 1; j <= 26; j++)
                S[i + 1][j][1] = S[i][j][1];
            S[i + 1][Y[i + 1]][1]++;
        }

        for (int i = 0; i < K; i++)
            W[i + 1] = _W[i] - 'a' + 1;

        L[0][0] = L[0][1] = 0;
        for (int i = 1; i <= K; i++) {
            L[i][0] = L[i - 1][0] + 1, L[i][1] = L[i - 1][1] + 1;
            while (X[L[i][0]] != W[i])
                L[i][0]++;
            while (Y[L[i][1]] != W[i])
                L[i][1]++;
        }

        R[K + 1][0] = N + 1, R[K + 1][1] = M + 1;
        for (int i = K; i >= 1; i--) {
            R[i][0] = R[i + 1][0] - 1, R[i][1] = R[i + 1][1] - 1;
            while (X[R[i][0]] != W[i])
                R[i][0]--;
            while (Y[R[i][1]] != W[i])
                R[i][1]--;
        }

        for (int i = 0; i <= K; i++) {
            for (int j = 1; j <= 26; j++) {
                if (S[R[i + 1][0] - 1][j][0] - S[L[i][0]][j][0] > 0 &&
                    S[R[i + 1][1] - 1][j][1] - S[L[i][1]][j][1] > 0)
                    ans = true;
            }
        }

        cout << (ans ? 1 : 0) << '\n';
    }

    return 0;
}