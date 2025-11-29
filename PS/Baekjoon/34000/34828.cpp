#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 100001;
const int BUCKET = 301;
const int MOD = 998244353;

int fac[BUCKET][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int Q, N, K, ans;

    for (int i = 1; i < BUCKET; i++) {
        fac[i][0] = 1;
        for (int j = 1; j < MAX; j++) {
            if (j < i)
                fac[i][j] = j;
            else
                fac[i][j] = fac[i][j - i] * j % MOD;
        }
    }

    cin >> Q;
    while (Q--) {
        cin >> N >> K;
        if (K < BUCKET)
            cout << fac[K][N] << '\n';
        else {
            ans = 1;
            while (N > 0)
                ans = ans * N % MOD, N -= K;
            cout << ans << '\n';
        }
    }

    return 0;
}