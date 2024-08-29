#include <bits/stdc++.h>
#define int long long

#define MAX 60
#define MAX_VAL 1010
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

bool dp[MAX][MAX_VAL];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, S;

    cin >> N >> S;

    dp[2][0] = true;
    dp[3][1] = true;

    for (int i = 4; i <= N; i++)
        for (int j = 1; j <= i; j++)
            for (int k = j * (j + 1) / 2; k <= S; k++)
                dp[i][k] = dp[i][k] || dp[i - j][k - j * (j + 1) / 2];

    cout << dp[N][S];

    return 0;
}