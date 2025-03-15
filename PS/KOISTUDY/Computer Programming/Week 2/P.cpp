#include <bits/stdc++.h>
using namespace std;

const int MAX = 11;

int A[MAX], dp[1 << MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];

    for (int i = 1; i < (1 << N); i++)
        dp[i] = 1000000;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            dp[(1 << i) | (1 << j)] = max(A[i], A[j]);

    for (int i = 1; i < (1 << N); i++) {
        for (int j = 0; j < N; j++)
            for (int k = j + 1; k < N; k++) {
                if (!(i & (1 << j)) || !(i & (1 << k)))
                    continue;
                dp[i] = min({dp[i], dp[i ^ (1 << j)] + A[k] + max(A[j], A[k]), dp[i ^ (1 << k)] + A[j] + max(A[j], A[k])});
            }
        for (int j = 0; j < N; j++)
            for (int k = j + 1; k < N; k++)
                for (int l = 0; l < N; l++) {
                    if (!(i & (1 << j)) || !(i & (1 << k)) || (i & (1 << l)))
                        continue;
                    dp[i] = min(dp[i], dp[i ^ ((1 << j) | (1 << k) | (1 << l))] + A[l] + max(A[j], A[k]));
                }
    }

    cout << dp[(1 << N) - 1] << '\n';

    return 0;
}