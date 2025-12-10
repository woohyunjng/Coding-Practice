#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 101;

int V[3][MAX][MAX], C[3][MAX][MAX];
bool chk[MAX][MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    bool ans = true;
    string S;

    cin >> N;
    for (int i = 0; i < 3; i++) {
        for (int j = N - 1; j >= 0; j--) {
            cin >> S;
            for (int k = 0; k < N; k++) {
                V[i][j][k] = S[k] - '0';
                if (V[i][j][k])
                    continue;
                for (int l = 0; l < N; l++) {
                    if (i == 0)
                        chk[l][k][j] = true;
                    else if (i == 1)
                        chk[j][l][k] = true;
                    else
                        chk[k][j][l] = true;
                }
            }
        }
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++) {
                if (chk[i][j][k])
                    continue;
                C[0][k][j]++, C[1][i][k]++, C[2][j][i]++;
            }

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                ans &= V[i][j][k] == (C[i][j][k] != 0);

    cout << (ans ? "Yes" : "No") << '\n';

    return 0;
}