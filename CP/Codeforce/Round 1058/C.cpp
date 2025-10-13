#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define int long long

using namespace std;

typedef array<int, 2> pr;
typedef array<int, 3> tp;

const int MAX = 400001;
const int MOD = 1'000'000'007;

int A[MAX], fac[MAX], inv[MAX], TW[MAX], D[MAX];

int comb(int N, int K) {
    if (K > N || K < 0)
        return 0;
    return (((fac[N] * inv[K]) % MOD) * inv[N - K]) % MOD;
}

int fpow(int N, int K) {
    int res = 1;
    while (K) {
        if (K & 1)
            res = (res * N) % MOD;
        N = (N * N) % MOD, K >>= 1;
    }
    return res;
}

int invf(int N) { return fpow(N, MOD - 2); }

void solve() {
    int N, ans = 0, S = 0, X;
    bool flag = true;

    cin >> N;
    for (int i = 0; i <= N; i++)
        cin >> A[i], flag &= A[i] == -1 || A[i] <= N;

    for (int i = 0; i <= N; i++) {
        if (A[i] == -1 || A[i] > N)
            continue;

        if (A[A[i]] == -1)
            A[A[i]] = i;
        else if (A[i] != 0)
            flag &= A[A[i]] == i;
        else
            A[A[i]] += i;
    }

    if (!flag) {
        cout << 0 << '\n';
        return;
    }

    D[0] = D[1] = 1;
    for (int i = 2; i <= N; i++)
        D[i] = (D[i - 1] + (i - 1) * D[i - 2]) % MOD;

    // Sum: D[i] * V[S - i]
    // V[i]는 i개 골랐을 떄

    for (int i = 1; i <= N; i++)
        S += A[i] == -1;

    for (int i = 0; i <= S; i++) {
        if (A[N] == -1)
            ans += D[S - i] * comb(S - 1, i) % MOD;
        else
            ans += D[S - i] * comb(S, i) % MOD;
        ans %= MOD;
    }

    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;

    fac[0] = 1, TW[0] = 1;
    for (int i = 1; i < MAX; i++)
        fac[i] = (fac[i - 1] * i) % MOD, TW[i] = (TW[i - 1] * 2) % MOD;
    inv[MAX - 1] = invf(fac[MAX - 1]);
    for (int i = MAX - 2; i >= 0; i--)
        inv[i] = (inv[i + 1] * (i + 1)) % MOD;

    while (T--)
        solve();

    return 0;
}