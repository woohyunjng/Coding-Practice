#include <bits/stdc++.h>
#define int long long
#define MAX 3010
#define INF 0x7f7f7f7f7f7f7f7f
#define MOD 1000000007

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int arr[MAX], dp[MAX][MAX], sm[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, res = 0;
    string S;
    cin >> S;

    N = S.size() + 1;

    for (int i = 2; i <= N; i++)
        arr[i] = (S[i - 2] == '>' ? 0 : 1);

    dp[1][1] = 1;
    for (int i = 1; i <= N; i++)
        sm[1][i] = 1;

    for (int i = 2; i <= N; i++) {
        if (arr[i]) {
            for (int j = i; j > 1; j--)
                dp[i][j] = sm[i - 1][j - 1] % MOD;
        } else {
            for (int j = 1; j < i; j++)
                dp[i][j] = (sm[i - 1][N] - sm[i - 1][j - 1] + MOD) % MOD;
        }

        for (int j = 1; j <= N; j++)
            sm[i][j] = (sm[i][j - 1] + dp[i][j]) % MOD;
    }

    res = sm[N][N];
    cout << res;

    return 0;
}