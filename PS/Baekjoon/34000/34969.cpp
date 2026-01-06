#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MOD = 998244353;
const int MAX = 2000001;

int A[MAX], V[MAX];

int inv(int X) {
    int res = 1, K = MOD - 2;
    while (K) {
        if (K & 1)
            res = (res * X) % MOD;
        X = (X * X) % MOD, K >>= 1;
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X, ans = 0;

    cin >> N >> M, X = 1;

    for (int i = 1; i <= (M << 1) - 1; i++)
        A[i] = min(i, (M << 1) - i);

    V[1] = 1;
    for (int i = 1; i <= N; i++)
        V[1] = V[1] * A[i] % MOD;
    for (int i = 2; i + N - 1 <= (M << 1) - 1; i++)
        V[i] = V[i - 1] * inv(A[i - 1]) % MOD * A[i + N - 1] % MOD;

    for (int i = 1; i <= N; i++) {
        if (i > M || N - i + 1 > M)
            continue;
        ans = (ans + V[M - i + 1]) % MOD;
    }

    for (int i = 1; i <= M - 1; i++)
        A[i] = A[((M - 1) << 1) + 1 - i] = i;

    V[1] = 1;
    for (int i = 1; i <= N; i++)
        V[1] = V[1] * A[i] % MOD;
    for (int i = 2; i + N - 1 <= ((M - 1) << 1); i++)
        V[i] = V[i - 1] * inv(A[i - 1]) % MOD * A[i + N - 1] % MOD;

    for (int i = 1; i + 1 <= N; i++) {
        if (i > M - 1 || N - i > M - 1)
            continue;
        ans = (ans - V[M - i] + MOD) % MOD;
    }

    cout << ans << '\n';

    return 0;
}