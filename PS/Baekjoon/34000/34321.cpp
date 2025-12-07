#include <bits/stdc++.h>
using namespace std;

const int MAX = 500001;
const int MAX_LOG = 20;

int A[MAX], B[MAX], mxA[MAX][MAX_LOG], mxB[MAX][MAX_LOG],
    sparse[MAX][MAX_LOG], msparse[MAX][MAX_LOG];

vector<int> solve(
    vector<int> &_A,
    vector<int> &_B,
    vector<pair<int, int>> &queries) {

    int N = _A.size(), Q = queries.size(), L, R, V, VM, X, Y, ans;
    vector<int> ans_lst;

    for (int i = 1; i <= N; i++) {
        A[i] = min(i + _A[i - 1], N), B[i] = min(i + _B[i - 1], N);
        mxA[i][0] = i, mxB[i][0] = i;
    }
    for (int j = 1; j < MAX_LOG; j++)
        for (int i = 1; i + (1 << j) - 1 <= N; i++) {
            mxA[i][j] = A[mxA[i][j - 1]] > A[mxA[i + (1 << (j - 1))][j - 1]] ? mxA[i][j - 1] : mxA[i + (1 << (j - 1))][j - 1];
            mxB[i][j] = B[mxB[i][j - 1]] > B[mxB[i + (1 << (j - 1))][j - 1]] ? mxB[i][j - 1] : mxB[i + (1 << (j - 1))][j - 1];
        }

    function<int(int, int)> qmxA = [&](int l, int r) {
        int k = __lg(r - l + 1);
        return A[mxA[l][k]] > A[mxA[r - (1 << k) + 1][k]] ? mxA[l][k] : mxA[r - (1 << k) + 1][k];
    };
    function<int(int, int)> qmxB = [&](int l, int r) {
        int k = __lg(r - l + 1);
        return B[mxB[l][k]] > B[mxB[r - (1 << k) + 1][k]] ? mxB[l][k] : mxB[r - (1 << k) + 1][k];
    };

    for (int i = 1; i <= N; i++) {
        sparse[i][0] = A[i], sparse[i][1] = max(B[i], A[qmxA(i, A[i])]);
        msparse[i][0] = i, msparse[i][1] = A[i];
    }
    for (int j = 2; j < MAX_LOG; j++)
        for (int i = 1; i <= N; i++) {
            X = B[qmxB(i, msparse[i][j - 1])];
            sparse[i][j] = max({sparse[qmxA(i, sparse[i][j - 1])][j - 1], sparse[qmxB(i, sparse[i][j - 1])][j - 1],
                                X, msparse[qmxA(i, X)][j - 1], msparse[qmxB(i, X)][j - 1]});
            msparse[i][j] = max({sparse[qmxA(i, msparse[i][j - 1])][j - 1], sparse[qmxB(i, msparse[i][j - 1])][j - 1],
                                 X, msparse[qmxA(i, sparse[i][j - 1])][j - 1], msparse[qmxB(i, sparse[i][j - 1])][j - 1]});
        }

    for (int i = 0; i < Q; i++) {
        L = queries[i].first + 1, R = queries[i].second + 1, ans = 0;
        V = A[L], VM = L;

        if (R <= A[L]) {
            ans_lst.push_back(L == R ? 0 : 1);
            continue;
        }

        for (int i = MAX_LOG - 1; i >= 0; i--) {
            X = B[qmxB(L, VM)];
            Y = max({sparse[qmxA(L, V)][i], sparse[qmxB(L, V)][i],
                     X, msparse[qmxA(L, X)][i], msparse[qmxB(L, X)][i]});
            if (Y < R) {
                VM = max({sparse[qmxA(L, VM)][i], sparse[qmxB(L, VM)][i],
                          msparse[qmxA(L, V)][i], msparse[qmxB(L, V)][i]});
                V = Y, ans += (1 << i);
            }
        }

        ans_lst.push_back(ans + 2);
    }

    return ans_lst;
}