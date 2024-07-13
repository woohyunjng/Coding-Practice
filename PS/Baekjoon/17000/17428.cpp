#include <bits/stdc++.h>
#define int long long
#define MAX 100

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int dp[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K, A = 0;

    cin >> N >> K;
    dp[1][1] = 1;
    for (int i = 2; i <= N; i++) {
        for (int j = i % 2; j <= i; j += 2) {
            dp[i][j] = dp[i - 1][j + 1];
            if (j)
                dp[i][j] += dp[i - 1][j - 1];
        }
    }

    if (K >= dp[N][0]) {
        cout << -1;
        return 0;
    }

    while (N--) {
        if (K < dp[N][A + 1]) {
            cout << "(";
            A++;
        } else {
            cout << ")";
            K -= dp[N][A-- + 1];
        }
    }

    return 0;
}