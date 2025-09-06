#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 100001;

int A[MAX], S[MAX], dp[MAX][4];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i], S[i] = S[i - 1] + A[i];

    if (S[N] % 4 != 0) {
        cout << 0 << '\n';
        return 0;
    }

    X = S[N] / 4;
    for (int i = 0; i <= N; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= N; j++) {
            dp[j][i] = dp[j - 1][i];
            if (S[j] == i * X)
                dp[j][i] += dp[j - 1][i - 1];
        }

    cout << dp[N - 1][3] << '\n';

    return 0;
}