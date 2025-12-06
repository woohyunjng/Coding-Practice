#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 200001;

int V[MAX], S[MAX][2], KO[MAX][2], KE[MAX][2];

int fpow(int N, int K, int P) {
    int res = 1;
    while (K) {
        if (K & 1)
            res = res * N % P;
        N = N * N % P, K >>= 1;
    }
    return res;
}

void solve() {
    int N, M, P, B = 1, ans = 0, R, L = 0;

    cin >> N >> M >> P;

    S[0][0] = V[0] = 1;
    for (int i = 1; i <= N; i++) {
        B = B * M % P, V[i] = fpow(B, P - 2, P);
        S[i][0] = (S[i - 1][0] + V[i]) % P;
        S[i][1] = (S[i - 1][1] + i * V[i]) % P;
    }

    for (int i = 1; i <= N; i++) {
        R = min(i - 1, N - i);
        KO[i][0] = S[R][0], KO[i][1] = (S[R][0] + 2 * S[R][1]) % P;
        L += KO[i][0], L %= P;
        ans += (KO[i][1] - (KO[i][0] * KO[i][0]) % P + P) % P, ans %= P;
    }

    for (int i = 1; i < N; i++) {
        R = min(i, N - i);
        KE[i][0] = (S[R][0] - 1 + P) % P, KE[i][1] = (2 * S[R][1] - (S[R][0] - 1) + P * 2) % P;
        L += KE[i][0], L %= P;
        ans += (KE[i][1] - (KE[i][0] * KE[i][0]) % P + P) % P, ans %= P;
    }

    ans += L * L % P, ans %= P;
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;

    while (T--)
        solve();

    return 0;
}