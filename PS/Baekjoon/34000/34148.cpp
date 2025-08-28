#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 100002;
const int MOD = 998244353;

int A[MAX], S[MAX], T[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, L, R, ans = 0;

    cin >> N >> Q, T[0] = 1;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    for (int i = 0; i < Q; i++) {
        cin >> L >> R, S[L]++, S[R + 1]--;
        T[i + 1] = (T[i] << 1ll) % MOD;
    }

    for (int i = 1; i <= N; i++) {
        S[i] += S[i - 1];
        if (S[i] == 0)
            ans += A[i] * T[Q] % MOD;
        else
            ans += T[Q - 1];
        ans %= MOD;
    }

    cout << ans << '\n';

    return 0;
}