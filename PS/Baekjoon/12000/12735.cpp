#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 1001;
const int MOD = 1000000007;

int A[MAX], B[MAX], D[MAX][2], dp[MAX][MAX], cnt[MAX][MAX], S[MAX][MAX], fac[MAX], inv_fac[MAX];

int inv(int K) {
    int res = 1, P = MOD - 2;
    while (P) {
        if (P & 1)
            res = res * K % MOD;
        K = K * K % MOD, P >>= 1;
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, Y, Z, ans = 0;
    vector<int> C;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i] >> B[i], B[i]++;
        C.push_back(A[i]), C.push_back(B[i]);
    }

    fac[0] = 1;
    for (int i = 1; i <= N + 1; i++)
        fac[i] = fac[i - 1] * i % MOD;
    inv_fac[N + 1] = inv(fac[N + 1]);
    for (int i = N; i >= 0; i--)
        inv_fac[i] = inv_fac[i + 1] * (i + 1) % MOD;

    sort(C.begin(), C.end()), C.erase(unique(C.begin(), C.end()), C.end()), X = (int)C.size() - 1;

    for (int i = 1; i <= N; i++) {
        D[i][0] = lower_bound(C.begin(), C.end(), A[i]) - C.begin();
        D[i][1] = lower_bound(C.begin(), C.end(), B[i]) - C.begin();
    }

    for (int i = 1; i <= X; i++)
        for (int j = 0; j <= N; j++) {
            S[i][j] = S[i][j - 1];
            if (D[j][0] < i && i <= D[j][1])
                S[i][j]++;

            Y = C[i] - C[i - 1];
            if (Y + j < Y - 1)
                continue;
            cnt[i][j] = inv_fac[j + 1];
            for (int k = 0; k < j + 1; k++)
                cnt[i][j] *= (Y + j - k), cnt[i][j] %= MOD;
        }

    dp[0][0] = 1;
    for (int i = 0; i <= N; i++)
        for (int j = 1; j <= X; j++) {
            dp[i][j] = dp[i][j - 1];
            if (j <= D[i][0] || D[i][1] < j)
                continue;
            for (int k = 0; k < i; k++)
                if (S[j][i] - S[j][k] > 0)
                    dp[i][j] += cnt[j][S[j][i] - S[j][k] - 1] * dp[k][j - 1] % MOD, dp[i][j] %= MOD;
        }

    for (int i = 1; i <= N; i++)
        ans += dp[i][X], ans %= MOD;
    cout << ans << '\n';

    return 0;
}