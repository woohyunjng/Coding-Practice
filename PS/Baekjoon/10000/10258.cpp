#include <bits/stdc++.h>
#define int long long

#define MAX 50
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int dp[MAX][2], power[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N;
    string S;

    power[0] = 1;
    for (int i = 1; i < MAX; i++)
        power[i] = power[i - 1] * 2;

    cin >> T;

    while (T--) {
        cin >> S;
        N = S.size();

        for (int i = 1; i <= N; i++) {
            if (S[N - i] == '0') {
                dp[i][0] = dp[i - 1][0];
                dp[i][1] = dp[i - 1][1] + power[i - 1];
            } else {
                dp[i][0] = dp[i - 1][1] + power[i - 1];
                dp[i][1] = dp[i - 1][0];
            }
        }

        cout << dp[N][0] << '\n';

        fill(dp[0], dp[MAX], 0);
    }

    return 0;
}