#include "star.h"
#include <bits/stdc++.h>
using namespace std;

#define MAX 1010

int N, K, A[MAX], res[2][MAX][MAX];

void init(int n, vector<int> a, int k) {
    int X;

    N = n, K = k;
    for (int i = 0; i < N; i++)
        A[i] = a[i];

    if (K > 1) {
        for (int i = 0; i * K < N; i++) {
            res[0][i][0] = A[i * K];
            for (int j = 1; j < K && i * K + j < N; j++)
                res[0][i][j] = star(res[0][i][j - 1], A[i * K + j]);

            if (i) {
                res[1][i][1] = A[i * K - 1];
                for (int j = 2; j < K; j++)
                    res[1][i][j] = star(A[i * K - j], res[1][i][j - 1]);
            }
        }
    }
}

int query(int L, int R) {
    if (K == 0)
        return A[L];
    if (K == 1)
        return star(A[L], A[R]);

    int X = L / K, P, Q;
    if (L % K == 0)
        return star(res[0][X][K - 1], res[0][X + 1][0]);
    else {
        X++;
        P = res[1][X][X * K - L], Q = res[0][X][R - X * K];
        return star(P, Q);
    }
}
