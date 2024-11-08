#include <bits/stdc++.h>
#define int long long

#define MAX 2010
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int dp[MAX][MAX][2];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, B[2];
    vector<int> A[2];
    string S;

    cin >> T;

    while (T--) {
        cin >> N;

        for (int i = 0; i < 2; i++) {
            cin >> S;
            A[i].clear();

            for (char j : S) {
                if (j == '0')
                    A[i].clear();
                else if (j == '1')
                    continue;
                A[i].push_back(j != '+');
            }
            B[i] = A[i].size();
        }

        for (int i = 0; i <= B[0]; i++)
            dp[i][0][0] = 1;
        for (int i = 0; i <= B[1]; i++)
            dp[0][i][1] = 1;

        for (int i = 1; i <= B[0]; i++)
            for (int j = 1; j <= B[1]; j++) {
                dp[i][j][0] = (dp[i - 1][j][0] + dp[i - 1][j][1]) % MOD;
                if (A[0][i - 1] ^ A[1][j - 1])
                    dp[i][j][1] = (dp[i][j - 1][0] + dp[i][j - 1][1]) % MOD;
                else
                    dp[i][j][1] = dp[i][j - 1][1];
            }

        cout << (dp[B[0]][B[1]][0] + dp[B[0]][B[1]][1]) % MOD << '\n';
    }

    return 0;
}