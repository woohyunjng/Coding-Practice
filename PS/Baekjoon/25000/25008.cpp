#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 998244353;
const int PR = 31;

signed findP(char T[], char P[], signed N, signed M) {
    vector<int> D(26, 0), A(N, 0), B(N, 0), PW(N + 1, 1);
    vector<vector<int>> arr(N, vector<int>());

    int ans = 0, X = 0, Y = 0, C;

    for (int i = 1; i <= N; i++)
        PW[i] = PW[i - 1] * PR % MOD;
    for (int i = M - 1; i >= 0; i--) {
        C = P[i] - 'a';
        if (D[C] != 0)
            B[i] = D[C] - i;
        D[C] = i;
    }
    for (int i = 0; i < M; i++)
        Y = (Y * PR + B[i]) % MOD;

    fill(D.begin(), D.end(), 0);
    for (int i = N - 1; i >= 0; i--) {
        C = T[i] - 'a', B[i] = 0;
        if (D[C] != 0)
            A[i] = D[C] - i, arr[D[C]].push_back(i);
        D[C] = i;
    }

    for (int i = 0; i < M; i++) {
        X = (X * PR + B[i]) % MOD;
        for (int j : arr[i])
            X = (X + A[j] * PW[i - j] % MOD) % MOD, B[j] = A[j];
    }
    ans += X == Y;

    for (int i = M; i < N; i++) {
        X = (X - B[i - M] * PW[M - 1] % MOD + MOD) % MOD * PR % MOD;
        for (int j : arr[i])
            if (j >= i - M + 1)
                X = (X + A[j] * PW[i - j] % MOD) % MOD, B[j] = A[j];
        ans += X == Y;
    }

    return ans;
}