#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 500001;
const int PRIME = 31;
const int MOD = 998244353;

int S[MAX], T[MAX], M[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    string _S;
    int N, L, R, C, ans = 1;
    bool flag;

    cin >> _S, N = _S.size(), M[0] = 1;
    for (int i = 1; i <= N; i++) {
        S[i] = _S[i - 1] - 'A' + 1, M[i] = M[i - 1] * PRIME % MOD;
        T[i] = (T[i - 1] * PRIME + S[i]) % MOD;
    }

    L = 1, R = N;
    while (L <= R) {
        for (C = 1; L + C - 1 < R - C + 1; C++)
            if ((T[L + C - 1] - T[L - 1] * M[C] % MOD + MOD) % MOD == (T[R] - T[R - C] * M[C] % MOD + MOD) % MOD)
                break;

        if (L + C - 1 >= R - C + 1)
            ans = max(ans, R - L + 1), L = R + 1;
        else
            L += C, R -= C, ans = max(ans, C);
    }

    cout << ans << '\n';

    return 0;
}