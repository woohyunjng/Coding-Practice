#include <iostream>
#define MOD 10007
using namespace std;

int dp[1010][11];

int main() {
    int N, res = 0;
    cin >> N;

    dp[0][0] = 1;
    for (int i = 1; i <= N; i++)
        for (int j = 0; j <= 9; j++)
            for (int k = 0; k <= j; k++)
                dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;

    for (int i = 0; i <= 9; i++)
        res = (res + dp[N][i]) % MOD;

    cout << res << '\n';
}