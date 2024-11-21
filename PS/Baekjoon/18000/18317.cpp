#include <bits/stdc++.h>
#define int long long

#define MAX 5100
#define MAX_NUM 4000000
#define PLUS 2000000

using namespace std;

int A[MAX], dp[MAX][MAX], val[MAX][MAX], cnt[MAX_NUM];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, L, R;
    cin >> N >> Q;

    for (int i = 1; i <= N; i++)
        cin >> A[i];

    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            val[i][j] = cnt[-(A[i] + A[j]) + PLUS];
            cnt[A[j] + PLUS]++;
        }

        for (int j = i + 1; j <= N; j++)
            cnt[A[j] + PLUS]--;
    }

    for (int i = 1; i <= N; i++)
        for (int j = 1; i + j - 1 <= N; j++)
            dp[j][i + j - 1] = dp[j][i + j - 2] + dp[j + 1][i + j - 1] - dp[j + 1][i + j - 2] + val[j][i + j - 1];

    while (Q--) {
        cin >> L >> R;
        cout << dp[L][R] << '\n';
    }

    return 0;
}