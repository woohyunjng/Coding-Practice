#include <bits/stdc++.h>
#define int long long

#define MAX 2000100
#define BASE 31
#define MOD 1000000007

using namespace std;

string A[MAX];
int pi[MAX], S[MAX];
map<int, int> dp;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, L, X, res = 0;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> A[i];

    for (int i = 1; i <= N; i++) {
        L = A[i].size(), X = 0, S[0] = A[i][0] - 'A' + 1;
        for (int j = 1; j < L; j++) {
            pi[j] = 0, S[j] = (S[j - 1] * BASE + A[i][j] - 'A' + 1) % MOD;
            while (X > 0 && A[i][j] != A[i][X])
                X = pi[X - 1];
            if (A[i][j] == A[i][X])
                pi[j] = ++X;
        }

        for (int j = L - 1; j >= 0; j = pi[j] - 1)
            if (dp.find(S[j]) != dp.end())
                dp[S[L - 1]] = max(dp[S[L - 1]], dp[S[j]] + 1);
        dp[S[L - 1]] = max(dp[S[L - 1]], 1ll);
        res = max(res, dp[S[L - 1]]);
    }

    cout << res << '\n';

    return 0;
}