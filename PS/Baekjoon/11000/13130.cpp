#include <bits/stdc++.h>
#define int long long

#define MAX 17
using namespace std;

int A[MAX], fac[MAX], dp[1 << MAX], chk[1 << MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, S;
    bool flag;
    cin >> N;

    fac[0] = 1;
    for (int i = 1; i <= N; i++)
        fac[i] = fac[i - 1] * i;

    for (int i = 0; i < N; i++)
        cin >> A[i];

    for (int i = 1; i < (1 << N); i++) {
        S = (int)__builtin_popcount(i), flag = true;
        for (int j = 0; j < N; j++)
            if (i & (1 << j))
                flag &= (A[j] % S == 0);
        if (flag)
            chk[i] = S;
    }

    dp[0] = 1;
    for (int i = 1; i < (1 << N); i++) {
        for (int j = 0; j < N; j++)
            if (i & (1 << j)) {
                S = j;
                break;
            }

        for (int j = i; j > 0; j = (j - 1) & i) {
            if (!(j & (1 << S)) || !chk[j])
                continue;
            dp[i] += dp[i ^ j] * fac[chk[j] - 1];
        }
    }

    cout << dp[(1 << N) - 1] << '\n';

    return 0;
}