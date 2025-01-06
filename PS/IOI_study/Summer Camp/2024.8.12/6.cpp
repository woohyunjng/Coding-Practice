#include <bits/stdc++.h>
#define int long long

#define MAX 100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int dp[MAX][MAX], two[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, X;
    bool Y = true;
    cin >> N >> K;

    dp[1][1] = 1;
    for (int i = 2; i <= N; i++) {
        for (int j = i % 2; j <= i; j += 2) {
            dp[i][j] = dp[i - 1][j + 1];
            if (j)
                dp[i][j] += dp[i - 1][j - 1];
        }
    }

    two[0] = 1;
    for (int i = 1; i <= N; i++)
        two[i] = two[i - 1] << 1;

    if (K >= two[N] - dp[N][0]) {
        cout << -1;
        return 0;
    }

    X = 0;
    for (int i = 1; i <= N; i++) {
        Y = Y && (X >= 0);
        if (!Y) {
            if (K < two[N - i])
                cout << "(";
            else {
                cout << ")";
                K -= two[N - i];
            }
        } else {
            if (K < two[N - i] - dp[N - i][X + 1]) {
                cout << "(";
                X++;
            } else {
                cout << ")";
                K -= two[N - i] - dp[N - i][X + 1];
                X--;
            }
        }
    }

    return 0;
}