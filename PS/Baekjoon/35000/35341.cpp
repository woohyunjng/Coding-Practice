#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")

#define int long long
using namespace std;

typedef array<int, 2> pr;

const int MAX = 100000;
const int MAX_LOG = 20;

int N, A[MAX], ans,
    dp[MAX][MAX_LOG], M[MAX][MAX_LOG],
    L[MAX][MAX_LOG], R[MAX][MAX_LOG];

void update(int X, int K) {
    int Y, BF = dp[X][K];
    ans -= dp[X][K], dp[X][K] = 1;

    if (K == 0)
        M[X][K] = A[X];
    else
        M[X][K] = max({M[X][K - 1], M[X + (1 << K)][K - 1], A[X + (1 << K) - 1]});

    if (K > 0) {
        dp[X][K] &= dp[X][K - 1] && dp[X + (1 << K)][K - 1];
        dp[X][K] &= M[X][K] > M[X][K - 1] && M[X][K] > M[X + (1 << K)][K - 1];
        R[X][K - 1] = L[X - (1 << K)][K - 1] = dp[X][K];
    }
    ans += dp[X][K];

    if (BF == 0 && dp[X][K] == 0)
        return;
    if (X - (1 << (K + 1)) >= 0)
        update(X - (1 << (K + 1)), K + 1);
    if (X + (1 << (K + 2)) - 1 <= N)
        update(X, K + 1);
}

int initialize(signed _N, vector<signed> _A) {
    N = _N, ans = N;
    for (int i = 0; i < N; i++) {
        A[i] = _A[i];
        dp[i][0] = 1, M[i][0] = A[i];
    }

    for (int i = 1; i < MAX_LOG; i++)
        for (int j = 0; j + (1 << (i + 1)) - 1 <= N; j++) {
            M[j][i] = max({M[j][i - 1], M[j + (1 << i)][i - 1], A[j + (1 << i) - 1]});
            dp[j][i] = dp[j][i - 1] && dp[j + (1 << i)][i - 1];
            dp[j][i] &= M[j][i] > M[j][i - 1] && M[j][i] > M[j + (1 << i)][i - 1];
            R[j][i - 1] = L[j + (1 << i)][i - 1] = dp[j][i], ans += dp[j][i];
        }

    return ans;
}

int update_sequence(signed X, signed Y) {
    A[X] = Y;
    for (int i = 0; i < MAX_LOG; i++)
        if ((X - (1 << i) + 1 >= 0 && X + (1 << i) - 1 < N))
            update(X - (1 << i) + 1, i);
    return ans;
}