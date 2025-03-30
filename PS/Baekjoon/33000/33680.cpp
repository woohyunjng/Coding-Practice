#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MOD = 1000000007;

int fpow(int N, int K) {
    int res = 1;
    while (K) {
        if (K & 1)
            res = (res * N) % MOD;
        N = (N * N) % MOD, K >>= 1;
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int Q, P, N, ans;

    cin >> Q;
    while (Q--) {
        cin >> P >> N;
        ans = (fpow(P, N) - 1 + MOD) % MOD * fpow(P - 1, MOD - 2) % MOD;
        cout << ans << '\n';
    }

    return 0;
}