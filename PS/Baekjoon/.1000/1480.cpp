#include <bits/stdc++.h>
#define int long long

#define MAX 13
using namespace std;

int A[1 << MAX], sm[1 << MAX], dp[MAX][1 << MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, C, res = 0;
    cin >> N >> M >> C;

    for (int i = 0; i < N; i++)
        cin >> A[1 << i];

    for (int i = 0; i < 1 << N; i++)
        for (int j = 0; j < N; j++)
            if (i & 1 << j)
                sm[i] += A[1 << j];

    for (int i = 1; i <= M; i++) {
        for (int j = 0; j < 1 << N; j++) {
            if (sm[j] - dp[i][j] <= C) {
                for (int k = 0; k < 1 << N; k++)
                    if (!(j & k))
                        dp[i + 1][j | k] = max(dp[i + 1][j | k], sm[j]);
                res = max(res, (int)__builtin_popcount(j));
            }
        }
    }

    cout << res << '\n';

    return 0;
}