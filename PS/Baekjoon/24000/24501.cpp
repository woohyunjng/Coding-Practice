#include <bits/stdc++.h>
#define int long long

#define MAX 3100
#define MOD 1000000007

using namespace std;

int arr[MAX][MAX], dp[MAX][MAX][3], sm[MAX][MAX][3];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M;
    string S;

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> S;
        for (int j = 1; j <= M; j++) {
            if (S[j - 1] == 'E')
                arr[i][j] = 0;
            else if (S[j - 1] == 'S')
                arr[i][j] = 1;
            else
                arr[i][j] = 2;
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (arr[i][j] == 0)
                dp[i][j][0] = 1;
            else if (arr[i][j] == 1)
                dp[i][j][1] = (sm[i - 1][j][0] + sm[i][j - 1][0] - sm[i - 1][j - 1][0] + MOD) % MOD;
            else
                dp[i][j][2] = (sm[i - 1][j][1] + sm[i][j - 1][1] - sm[i - 1][j - 1][1] + MOD) % MOD;

            sm[i][j][0] = (sm[i][j - 1][0] + sm[i - 1][j][0] - sm[i - 1][j - 1][0] + dp[i][j][0] + MOD) % MOD;
            sm[i][j][1] = (sm[i][j - 1][1] + sm[i - 1][j][1] - sm[i - 1][j - 1][1] + dp[i][j][1] + MOD) % MOD;
            sm[i][j][2] = (sm[i][j - 1][2] + sm[i - 1][j][2] - sm[i - 1][j - 1][2] + dp[i][j][2] + MOD) % MOD;
        }
    }

    cout << sm[N][M][2] << '\n';

    return 0;
}