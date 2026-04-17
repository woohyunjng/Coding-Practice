#include <bits/stdc++.h>
#define int long long

#define MAX 6100
#define MOD 1000000007ll

using namespace std;

int fpow(int A, int B) {
    int res = 1;
    while (B) {
        if (B & 1)
            res = res * A % MOD;
        A = A * A % MOD, B >>= 1;
    }
    return res;
}

int dp[MAX], A[MAX], B[MAX], fac[MAX], inv[MAX], comb[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, L, X = 0, K, res_cnt = 1, res = 0;
    vector<int> arr;

    cin >> L;
    fac[0] = 1;
    for (int i = 1; i <= L * 2; i++)
        fac[i] = fac[i - 1] * i % MOD;
    inv[L * 2] = fpow(fac[L * 2], MOD - 2);
    for (int i = L * 2 - 1; i >= 0; i--)
        inv[i] = inv[i + 1] * (i + 1) % MOD;

    for (int i = 0; i <= L; i++) {
        for (int j = 0; j <= i; j++) {
            if (!j || i == j)
                comb[i][j] = 1;
            else
                comb[i][j] = fac[i] * inv[j] % MOD * inv[i - j] % MOD;
        }
    }

    dp[0] = 1ll, dp[1] = 1ll, dp[2] = 1ll;
    for (int i = 3; i <= L * 2; i++) {
        for (int j = 1; j < i; j += 2) {
            K = comb[i - 1][j] * dp[j] % MOD * dp[i - j - 1] % MOD;
            dp[i] = (dp[i] + K) % MOD;
        }
    }

    cin >> N, X = 1;
    for (int i = 1; i <= N; i++) {
        cin >> K;
        if (K == 1)
            A[X++] = 0;
        else if (K == 2)
            A[X++] = 1, A[X++] = 2;
    }

    cin >> M, X = 1;
    for (int i = 1; i <= M; i++) {
        cin >> K;
        if (K == 1)
            B[X++] = 0;
        else if (K == 2)
            B[X++] = 1, B[X++] = 2;
    }

    for (int i = 1; i <= L; i++) {
        if (A[i] == B[i])
            continue;
        X = 0;
        while (A[i] + B[i] != 2)
            i++, X++;
        arr.push_back(X);
    }

    for (int i : arr)
        res += i, res_cnt = res_cnt * dp[i] % MOD * inv[i] % MOD;
    res_cnt = res_cnt * fac[res] % MOD;

    cout << res << ' ' << res_cnt << '\n';

    return 0;
}