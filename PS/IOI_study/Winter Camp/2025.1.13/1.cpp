#include <bits/stdc++.h>
#define int long long

#define MAX 17
using namespace std;

int val[MAX][MAX], dp[1 << MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, A, B, C;
    cin >> N;

    for (int i = 0; i < N * (N - 1) / 2; i++) {
        cin >> A >> B >> C, --A, --B;
        val[A][B] = val[B][A] = C;
    }

    for (int i = 0; i < (1 << N); i++) {
        if (__builtin_popcount(i) & 1)
            continue;

        for (int j = 0; j < N; j++) {
            if (!(i & (1 << j)))
                continue;
            for (int k = j + 1; k < N; k++) {
                if (!(i & (1 << k)))
                    continue;
                dp[i] = max(dp[i], dp[i ^ (1 << j) ^ (1 << k)] + val[j][k]);
            }
        }
    }

    cout << dp[(1 << N) - 1] << '\n';

    return 0;
}