#include <bits/stdc++.h>
#define int long long
using namespace std;

const int S = 41326, C = 538;
const int PR = 31, MOD = 1'000'000'007;

int A[S], dp[S], H[S], F[S];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int M, K, X, Y, Z = 0, ans = 0;
    bool flag;

    cin >> M >> K;
    for (int i = 0; i < K; i++)
        cin >> A[i];

    F[0] = 1;
    for (int i = 1; i <= S; i++) {
        for (int j = 0; j < K; j++)
            if (i - A[j] >= 0)
                dp[i] |= !dp[i - A[j]];
        H[i] = (H[i - 1] * PR + dp[i]) % MOD;
        F[i] = F[i - 1] * PR % MOD;
    }

    if (M <= S) {
        for (int i = 1; i <= M; i++)
            ans += !dp[i];
        cout << ans << '\n';
        return 0;
    }
    for (X = 1; X <= S; X++) {
        for (int j = 1; j <= C; j++) {
            flag = true;
            for (int k = 1; X + j * k <= S; k++)
                flag &= (H[X + j * k - 1] - H[X + j * (k - 1) - 1] * F[j] % MOD + MOD) % MOD == (H[X + j - 1] - H[X - 1] * F[j] % MOD + MOD) % MOD;
            if (flag) {
                Y = j;
                break;
            }
        }
        if (Y)
            break;
        ans += !dp[X], M--;
    }

    for (int i = X; i < X + Y; i++)
        Z += !dp[i];
    ans += (M / Y) * Z;
    for (int i = X; i < X + M % Y; i++)
        ans += !dp[i];
    cout << ans << '\n';

    return 0;
}