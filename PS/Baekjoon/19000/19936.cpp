#include "biscuits.h"
#include <bits/stdc++.h>

#define int long long

using namespace std;

const int MAX = 62;

int S[MAX];
unordered_map<int, int> _dp[MAX];

int dp(int K, int M) {
    if (K < 0)
        return M >= 0;
    else if (_dp[K].count(M))
        return _dp[K][M];

    int res = dp(K - 1, min({S[K], M, (1ll << K) - 1}));
    if (min(S[K], M) >= (1ll << K))
        res += dp(K - 1, min((1ll << K) - 1, min(S[K], M) - (1ll << K)));
    return _dp[K][M] = res;
}

int count_tastiness(int X, vector<int> A) {
    int K = A.size();

    S[0] = A[0];
    for (int i = 1; i < K; i++)
        S[i] = S[i - 1] + A[i] * (1ll << i);
    for (int i = K; i < MAX; i++)
        S[i] = S[i - 1];
    for (int i = 0; i < MAX; i++)
        S[i] /= X, _dp[i].clear();

    return dp(MAX - 1, S[MAX - 1]);
}