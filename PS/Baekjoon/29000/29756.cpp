#include <bits/stdc++.h>
#define int long long

#define MAX 1100
using namespace std;

int S[MAX], H[MAX], dp[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K;
    cin >> N >> K;

    for (int i = 1; i <= N; i++)
        cin >> S[i];
    for (int i = 1; i <= N; i++)
        cin >> H[i];

    for (int i = 1; i <= N; i++) {
        for (int j = 100; j >= 0; j--) {
            if (j - H[i] >= 0)
                dp[i + 1][min(100ll, j + K - H[i])] = max(dp[i + 1][min(100ll, j + K - H[i])], dp[i][j] + S[i]);
            dp[i + 1][min(100ll, j + K)] = max(dp[i + 1][min(100ll, j + K)], dp[i][j]);
        }
    }

    cout << *max_element(dp[N + 1], dp[N + 1] + 101) << '\n';

    return 0;
}