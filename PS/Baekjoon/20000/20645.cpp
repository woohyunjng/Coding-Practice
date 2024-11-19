#include <bits/stdc++.h>
#define int long long

#define MAX 100100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int dp[MAX][4][4][4], A[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, res = 0;
    string S;

    cin >> S;
    N = S.size();

    for (int i = 1; i <= N; i++) {
        if (S[i - 1] == 'A')
            A[i] = 0;
        else if (S[i - 1] == 'G')
            A[i] = 1;
        else if (S[i - 1] == 'C')
            A[i] = 2;
        else if (S[i - 1] == 'T')
            A[i] = 3;
        else
            A[i] = -1;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 4; j++) {
            if (A[i] != -1 && A[i] != j)
                continue;

            for (int k = 0; k < 4; k++) {
                if (i == 1) {
                    dp[i][k][j][j] = 1;
                    continue;
                }

                for (int l = 0; l < 4; l++) {
                    for (int m = 0; m < 4; m++) {
                        if (j != m)
                            dp[i][k][l][j] = (dp[i][k][l][j] + dp[i - 1][k][l][m]) % MOD;
                        if (k == m)
                            dp[i][l][j][j] = (dp[i][l][j][j] + dp[i - 1][k][l][m]) % MOD;
                    }
                }
            }
        }
    }

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            res = (res + dp[N][i][j][i]) % MOD;

    cout << res << '\n';

    return 0;
}