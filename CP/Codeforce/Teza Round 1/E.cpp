#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 5001;
const int MOD = 1000000007;

int comb[MAX][MAX], fac[MAX];

int A[MAX], S[MAX][MAX], V[MAX], M[MAX][2], Z[MAX];

void solve() {
    int N, K = 0, X, Y, ans = 0;

    cin >> N;
    fill(Z, Z + N + 1, 0);

    for (int i = 1; i <= N; i++) {
        cin >> A[i], V[i] = V[i - 1];
        if (A[i] == -1)
            V[i]++, K++, A[i] = N;
        else
            Z[A[i]] = 1;
    }

    for (int i = 1; i <= N; i++)
        Z[i] += Z[i - 1];

    M[0][0] = N, M[N + 1][1] = N;
    for (int i = 1; i <= N; i++)
        M[i][0] = min(M[i - 1][0], A[i]);
    for (int i = N; i >= 1; i--)
        M[i][1] = min(M[i + 1][1], A[i]);

    for (int i = 1; i <= N; i++)
        for (int j = i; j <= N; j++) {
            X = V[j] - V[i - 1], Y = min(M[i - 1][0], M[j + 1][1]);
            S[X][0]++, S[X][Y]--;
        }

    for (int i = 0; i <= N; i++)
        for (int j = 0; j <= N; j++)
            S[i][j] = (S[i][j] + S[i][j - 1]) % MOD;

    for (int i = 0; i <= N; i++) {
        X = i + 1 - Z[i];
        for (int j = X; j <= K; j++)
            ans = (ans + comb[j][X] * fac[X] % MOD * fac[K - X] % MOD * S[j][i]) % MOD;
    }

    cout << ans << '\n';

    for (int i = 0; i <= N; i++)
        for (int j = 0; j <= N; j++)
            S[i][j] = 0;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;

    fac[0] = 1;
    for (int i = 1; i < MAX; i++)
        fac[i] = (fac[i - 1] * i) % MOD;

    comb[0][0] = 1;
    for (int i = 1; i < MAX; i++) {
        comb[i][0] = 1;
        for (int j = 1; j <= i; j++)
            comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
    }

    while (T--)
        solve();

    return 0;
}