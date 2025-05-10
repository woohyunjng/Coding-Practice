#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MOD = 1000000007;
const int MAX = 100001;

int fpow(int N, int K) {
    int res = 1;
    while (K) {
        if (K & 1)
            res = (res * N) % MOD;
        N = (N * N) % MOD, K >>= 1;
    }
    return res;
}

int fac[MAX], inv[MAX];

int comb(int N, int K) {
    if (N < K || K < 0)
        return 0;
    return fac[N] * inv[K] % MOD * inv[N - K] % MOD;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, A, B, C, ans;

    fac[0] = 1;
    for (int i = 1; i < MAX; i++)
        fac[i] = fac[i - 1] * i % MOD;
    inv[MAX - 1] = fpow(fac[MAX - 1], MOD - 2);
    for (int i = MAX - 2; i >= 0; i--)
        inv[i] = inv[i + 1] * (i + 1) % MOD;

    cin >> T;
    while (T--) {
        cin >> N >> A >> B >> C;

        if (B % 2 == 1 || (N - A - B - C) < A + B / 2 - 1) {
            cout << 0 << '\n';
            continue;
        }

        ans = comb(N - A - B - C + 1, A + B / 2) * comb(A + B / 2, A) % MOD;
        ans = ans * fac[A] % MOD * fac[B] % MOD * fac[C] % MOD;
        ans = ans * comb(C + B / 2 - 1, C) % MOD;

        cout << ans << '\n';
    }

    return 0;
}