#include <bits/stdc++.h>
#define int long long
#define MAX 1010
#define INF 0x7f7f7f7f7f7f7f7f
#define MOD 10007

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int dp[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    string S;

    cin >> S;
    N = S.size();

    fill(&dp[0][0], &dp[N][N], 0);
    for (int i = 0; i < N; i++)
        dp[i][i] = 1;

    for (int i = 2; i <= N; i++) {
        for (int j = 0; j <= N - i; j++) {
            int k = i + j - 1;
            if (S[j] == S[k])
                dp[j][k] = (dp[j + 1][k] + dp[j][k - 1] + 1) % MOD;
            else
                dp[j][k] = (dp[j + 1][k] + dp[j][k - 1] - dp[j + 1][k - 1] + MOD) % MOD;
        }
    }

    cout << dp[0][N - 1];

    return 0;
}