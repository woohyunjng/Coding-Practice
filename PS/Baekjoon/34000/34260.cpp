#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 31;
const int MAX_VAL = MAX * 100;
const int MOD = 998244353;

int S[MAX], dp[MAX_VAL], cnt[MAX_VAL], U[MAX_VAL], V[MAX_VAL];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int P, N, M, C, ans = 0;
    bool flag;

    cin >> P, dp[0] = 1;
    for (int i = 1; i <= P; i++) {
        cin >> N >> M;
        for (int j = 0; j < N; j++)
            cin >> S[j];
        for (int j = 0; j < M; j++)
            cin >> U[j] >> V[j], U[j]--, V[j]--;

        fill(cnt, cnt + MAX_VAL, 0);
        for (int j = 0; j < (1 << N); j++) {
            flag = true, C = 0;
            for (int k = 0; k < N; k++) {
                if (!(j & (1 << k)))
                    continue;
                C += S[k];
            }
            for (int k = 0; k < M; k++)
                if (!(j & (1 << U[k])) && (j & (1 << V[k])))
                    flag = false;
            if (flag)
                cnt[C]++;
        }

        for (int j = i * 100; j >= 0; j--)
            for (int k = 1; k <= min(j, 100ll); k++)
                dp[j] = (dp[j] + dp[j - k] * cnt[k] % MOD) % MOD;
    }

    for (int i = 0; i <= P * 100; i++)
        ans = (ans + dp[i] * i % MOD) % MOD;

    cout << ans << '\n';

    return 0;
}