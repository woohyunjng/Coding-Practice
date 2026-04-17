#include <bits/stdc++.h>
#define int long long

#define MAX 26

using namespace std;

int A[MAX], dp[1 << MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, res;
    cin >> N, res = N;

    for (int i = 0; i < N; i++)
        cin >> A[i];

    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            for (int k = j + 1; k < N; k++)
                dp[(1 << i) | (1 << j) | (1 << k)] = (A[i] ^ A[j] ^ A[k]) == 0;

    for (int i = 0; i < (1 << N); i++) {
        if (!dp[i])
            res = min(res, N - __builtin_popcount(i));
        else
            for (int j = 0; j < N; j++)
                dp[i | (1 << j)] = 1;
    }

    cout << res << '\n';

    return 0;
}
