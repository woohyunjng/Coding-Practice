#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 100001;
const int MOD = 1000000007;

int fpow(int N, int K) {
    int res = 1;
    while (K > 0) {
        if (K & 1)
            res = res * N % MOD;
        N = N * N % MOD, K >>= 1;
    }
    return res;
}

int T[MAX], X[MAX], Y[MAX], R[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, K, ans = 1, val = 1, SX, SY, P, Q;
    char C;
    vector<int> compX, compY;

    bool flag;

    cin >> N >> M >> K;
    for (int i = 1; i <= K; i++) {
        cin >> C >> Y[i] >> X[i], T[i] = C == '+';
        compX.push_back(X[i]), compY.push_back(Y[i]);
    }

    sort(compX.begin(), compX.end()), compX.erase(unique(compX.begin(), compX.end()), compX.end()), SX = compX.size();
    sort(compY.begin(), compY.end()), compY.erase(unique(compY.begin(), compY.end()), compY.end()), SY = compY.size();

    fill(R, R + SY + 1, -1);
    for (int i = 1; i <= K; i++) {
        P = lower_bound(compY.begin(), compY.end(), Y[i]) - compY.begin() + 1;
        Q = T[i] ^ (X[i] & 1);
        if (R[P] != -1 && R[P] != Q)
            R[P] = -2;
        else
            R[P] = Q;
    }

    flag = K == 0 || R[1] >= 0;
    for (int i = 1; i <= SY; i++)
        ans *= R[i] >= 0, flag &= (R[1] ^ (compY[1 - 1] & 1)) == (R[i] ^ (compY[i - 1] & 1));
    ans = ans * fpow(2, N - SY) % MOD;
    if (flag)
        ans = (ans - 1 + MOD) % MOD;
    if (K == 0)
        ans = (ans - 1 + MOD) % MOD;

    fill(R, R + SX + 1, -1);
    for (int i = 1; i <= K; i++) {
        P = lower_bound(compX.begin(), compX.end(), X[i]) - compX.begin() + 1;
        Q = T[i] ^ (Y[i] & 1);
        if (R[P] != -1 && R[P] != Q)
            R[P] = -2;
        else
            R[P] = Q;
    }
    for (int i = 1; i <= SX; i++)
        val *= R[i] >= 0;
    val = val * fpow(2, M - SX) % MOD;
    ans = (ans + val) % MOD;

    cout << ans << '\n';

    return 0;
}