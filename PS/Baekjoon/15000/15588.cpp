#include <bits/stdc++.h>
#define int long long

#define MAX 1001000
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int dp[MAX], sm[MAX];

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

    int N, M, K, res = 1;
    cin >> N >> M >> K;

    res = fpow(M, N);

    dp[0] = 1;
    for (int i = 1; i < K; i++)
        dp[i] = (dp[i - 1] * M) % MOD, sm[i] = (sm[i - 1] + dp[i]) % MOD;
    for (int i = K; i <= N; i++)
        dp[i] = (sm[i - 1] - sm[i - K]) * (M - 1) % MOD, sm[i] = (sm[i - 1] + dp[i]) % MOD;
    cout << (res - dp[N] + MOD) % MOD << '\n';

    return 0;
}