#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int dp[MAX], S[MAX], C[MAX], T[MAX];
vector<int> arr[MAX];

int fpow(int N, int K) {
    int res = 1;
    while (K) {
        if (K & 1)
            res = res * N % MOD;
        K >>= 1, N = N * N % MOD;
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, K, res = 1, val = 0;
    char X;

    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++)
        cin >> S[i] >> C[i], arr[C[i]].push_back(i);

    while (M--)
        cin >> X, T[X - 'A' + 1]++;

    dp[0] = 1;
    for (int i = 1; i <= K; i++)
        for (int j = 1; j <= N; j++)
            if (i - S[j] >= 0)
                dp[i] = (dp[i] + dp[i - S[j]]) % MOD;

    for (int i = 1; i <= N; i++) {
        C[i] = 0;
        for (int j : arr[i])
            C[i] = (C[i] + dp[K - S[j]]) % MOD;
    }

    for (int i = 1; i <= 26; i++) {
        if (T[i] == 0)
            continue;
        val = 0;
        for (int j = 1; j <= N; j++)
            val = (val + fpow(C[j], T[i])) % MOD;
        res = res * val % MOD;
    }

    cout << res << '\n';

    return 0;
}