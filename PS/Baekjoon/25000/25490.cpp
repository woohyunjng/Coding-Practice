#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 200001;
const int MOD = 1000000007;

int A[MAX], ans, V[2][MAX], S[3][MAX];

void dnc(int l, int r) {
    if (l == r) {
        ans = (ans + A[l] * A[l]) % MOD;
        return;
    }

    int m = l + r >> 1, X, Y, B, C;

    V[0][m + 1] = A[m], V[1][m + 1] = A[m];
    for (int i = m; i >= l; i--) {
        V[0][i] = min(V[0][i + 1], A[i]), V[1][i] = max(V[1][i + 1], A[i]);
        S[0][i] = V[0][i], S[1][i] = V[1][i], S[2][i] = V[0][i] * V[1][i] % MOD;
    }

    S[0][l - 1] = S[1][l - 1] = S[2][l - 1] = 0;
    for (int i = l; i <= m; i++) {
        S[0][i] += S[0][i - 1], S[1][i] += S[1][i - 1], S[2][i] += S[2][i - 1];
        S[0][i] %= MOD, S[1][i] %= MOD, S[2][i] %= MOD;
    }

    B = A[m + 1], C = A[m + 1];
    X = Y = m;

    for (int i = m + 1; i <= r; i++) {
        B = min(B, A[i]), C = max(C, A[i]);
        while (X >= l && V[0][X] > B && V[1][X] < C)
            X--;
        while (Y >= l && (V[0][Y] > B || V[1][Y] < C))
            Y--;
        ans = (ans + S[2][Y] - S[2][l - 1] + MOD) % MOD;
        ans = (ans + (m - X) * B % MOD * C % MOD) % MOD;
        if (X < l)
            continue;
        if (V[0][X] <= B)
            ans = (ans + C * (S[0][X] - S[0][Y]) % MOD) % MOD;
        else
            ans = (ans + B * (S[1][X] - S[1][Y]) % MOD) % MOD;
    }

    dnc(l, m), dnc(m + 1, r);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    dnc(1, N);

    cout << ans << '\n';

    return 0;
}