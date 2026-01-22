#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 998244353;

int fpow(int N, int K) {
    int res = 1;
    N %= MOD;
    while (K) {
        if (K & 1)
            res = res * N % MOD;
        N = N * N % MOD, K >>= 1;
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, L, R, ans;

    cin >> T;
    while (T--) {
        cin >> N >> L >> R;
        if (L == R)
            cout << 1 << '\n';
        else {
            ans = (fpow(R - L + 1, N) - fpow(R - L, N) * 2 % MOD + MOD) % MOD;
            ans = (ans + fpow(R - L - 1, N)) % MOD;
            cout << ans << '\n';
        }
    }

    return 0;
}