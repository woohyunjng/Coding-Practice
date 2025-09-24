#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAX = 300001;
const int MAX_L = 61;
const int MAX_K = 4;
const int MOD = 1000000007;

int A[3][MAX_L], S[MAX],
    dp[MAX_L][MAX_L][MAX_K + 1],
    ddp[MAX_L][MAX_L][MAX_L][MAX_K + 1],
    tdp[2][MAX_L][MAX_L][MAX_L][MAX_K + 1],

    V[2][MAX][MAX_K + 1], D[MAX_L];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    string _X, _Y, _Z, _S;
    int L[3], N, Q, K, ans;

    cin >> _X >> _Y >> _Z, L[0] = _X.size(), L[1] = _Y.size(), L[2] = _Z.size();
    for (int i = 1; i <= L[0]; i++)
        A[0][i] = _X[i - 1] - 'a';
    for (int i = 1; i <= L[1]; i++)
        A[1][i] = _Y[i - 1] - 'a';
    for (int i = 1; i <= L[2]; i++)
        A[2][i] = _Z[i - 1] - 'a';
    K = max({L[0], L[1], L[2]});

    for (int i = 0; i <= K; i++)
        dp[0][i][MAX_K] = 1;
    for (int t = 0; t < 3; t++)
        for (int i = 1; i <= L[t]; i++) {
            for (int j = 1; j <= L[t]; j++) {
                dp[i][j][MAX_K] = 0;
                for (int k = 0; k < MAX_K; k++) {
                    if (A[t][j] == k)
                        dp[i][j][k] = dp[i - 1][j - 1][MAX_K];
                    else
                        dp[i][j][k] = dp[i][j - 1][k];
                    dp[i][j][MAX_K] = (dp[i][j][MAX_K] + dp[i][j][k]) % MOD;
                }
            }
            D[i] += dp[i][L[t]][MAX_K], D[i] %= MOD;
        }

    for (int i = 0; i <= K; i++)
        for (int j = 0; j <= K; j++)
            ddp[0][i][j][MAX_K] = 1;
    for (int t1 = 0; t1 < 3; t1++)
        for (int t2 = t1 + 1; t2 < 3; t2++)
            for (int i = 1; i <= min(L[t1], L[t2]); i++) {
                for (int j = 1; j <= L[t1]; j++)
                    for (int k = 1; k <= L[t2]; k++) {
                        ddp[i][j][k][MAX_K] = 0;
                        for (int l = 0; l < MAX_K; l++) {
                            if (A[t1][j] == A[t2][k] && A[t1][j] == l)
                                ddp[i][j][k][l] = ddp[i - 1][j - 1][k - 1][MAX_K];
                            else
                                ddp[i][j][k][l] = ddp[i][j - 1][k][l] + ddp[i][j][k - 1][l] - ddp[i][j - 1][k - 1][l];
                            ddp[i][j][k][MAX_K] = (ddp[i][j][k][MAX_K] + ddp[i][j][k][l]) % MOD;
                        }
                    }
                D[i] = (D[i] - ddp[i][L[t1]][L[t2]][MAX_K] + MOD) % MOD;
            }

    for (int i = 0; i <= K; i++)
        for (int j = 0; j <= K; j++)
            for (int k = 0; k <= K; k++)
                tdp[0][i][j][k][MAX_K] = 1;
    for (int i = 1; i <= min({L[0], L[1], L[2]}); i++) {
        for (int j = 1; j <= L[0]; j++)
            for (int k = 1; k <= L[1]; k++)
                for (int l = 1; l <= L[2]; l++) {
                    tdp[i & 1][j][k][l][MAX_K] = 0;
                    for (int m = 0; m < MAX_K; m++) {
                        if (A[0][j] == A[1][k] && A[1][k] == A[2][l] && A[0][j] == m)
                            tdp[i & 1][j][k][l][m] = tdp[(i & 1) ^ 1][j - 1][k - 1][l - 1][MAX_K];
                        else
                            tdp[i & 1][j][k][l][m] = (tdp[i & 1][j - 1][k][l][m] + tdp[i & 1][j][k - 1][l][m] + tdp[i & 1][j][k][l - 1][m] - tdp[i & 1][j - 1][k - 1][l][m] - tdp[i & 1][j - 1][k][l - 1][m] - tdp[i & 1][j][k - 1][l - 1][m] + tdp[i & 1][j - 1][k - 1][l - 1][m] + MOD * 3) % MOD;
                        tdp[i & 1][j][k][l][MAX_K] = (tdp[i & 1][j][k][l][MAX_K] + tdp[i & 1][j][k][l][m]) % MOD;
                    }
                }
        D[i] = (D[i] + tdp[i & 1][L[0]][L[1]][L[2]][MAX_K]) % MOD;
        for (int j = 0; j <= L[0]; j++)
            for (int k = 0; k <= L[1]; k++)
                for (int l = 0; l <= L[2]; l++)
                    for (int m = 0; m <= MAX_K; m++)
                        tdp[(i & 1) ^ 1][j][k][l][m] = 0;
    }

    cin >> Q;
    while (Q--) {
        cin >> _S, N = _S.size(), ans = K + 1;
        for (int i = 1; i <= N; i++)
            S[i] = _S[i - 1] - 'a';

        for (int i = 0; i <= N; i++)
            V[0][i][MAX_K] = 1;
        for (int i = 1; i <= K; i++) {
            for (int j = 1; j <= N; j++) {
                V[i & 1][j][MAX_K] = 0;
                for (int k = 0; k < MAX_K; k++) {
                    if (S[j] == k)
                        V[i & 1][j][k] = V[(i & 1) ^ 1][j - 1][MAX_K];
                    else
                        V[i & 1][j][k] = V[i & 1][j - 1][k];
                    V[i & 1][j][MAX_K] = (V[i & 1][j][MAX_K] + V[i & 1][j][k]) % MOD;
                }
            }
            if (D[i] != V[i & 1][N][MAX_K]) {
                ans = i;
                break;
            }
            for (int j = 0; j <= N; j++)
                for (int k = 0; k <= MAX_K; k++)
                    V[(i & 1) ^ 1][j][k] = 0;
        }

        cout << ans << '\n';
    }

    return 0;
}