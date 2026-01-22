#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAX = 100001;
const int MOD = 998244353;

int V[MAX], SV[MAX], TW[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, M, ans;

    TW[0] = 1;
    for (int i = 1; i < MAX; i++)
        TW[i] = TW[i - 1] * 2 % MOD;

    V[1] = 12, V[2] = 10;
    for (int i = 3; i < MAX; i++) {
        if (i & 1)
            V[i] = (V[i - 1] * 2 % MOD - TW[i / 2] + MOD) % MOD;
        else
            V[i] = V[i - 1] * 2 % MOD;
    }

    for (int i = 1; i < MAX; i++)
        SV[i] = (V[i] + SV[i - 1]) % MOD;

    cin >> T;
    while (T--) {
        cin >> N >> M, N--, M--;
        ans = (SV[N] + SV[M] - 12 + MOD) % MOD;
        cout << ans << '\n';
    }

    return 0;
}