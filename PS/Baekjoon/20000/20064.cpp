#include "doll.h"
#include <bits/stdc++.h>

#define MAX 400000

using namespace std;

int cnt = 0, leaf = 0, K = 1, val[MAX], tree[MAX], state[MAX], X[MAX], Y[MAX];
vector<int> order;

int dfs(int n) {
    if (tree[n] == -1)
        return tree[n];
    else if (tree[n] == 1)
        return tree[n] = ++leaf;

    tree[n] = -(++cnt), X[-tree[n]] = dfs(n << 1), Y[-tree[n]] = dfs(n << 1 | 1);
    return tree[n];
}

void simulate(int n) {
    if (order.size() == leaf)
        return;
    if (tree[n] >= 0)
        order.push_back(tree[n]), simulate(1);
    else if (n != 1 && tree[n] == -1)
        simulate(1);

    state[n] ^= 1;
    simulate(state[n] ? (n << 1) : (n << 1 | 1));
}

void create_circuit(int M, vector<int> A) {
    A.push_back(0);
    int N = A.size();

    vector<int> C(M + 1, -1), ansX, ansY;

    if (N == 2) {
        fill(C.begin(), C.end(), 0), C[0] = A[0];
        answer(C, ansX, ansY);
        return;
    }

    while (K <= N)
        K <<= 1;

    fill(tree + K, tree + (K << 1) - N, -1), fill(tree + (K << 1) - N, tree + (K << 1), 1);
    for (int i = K; i > 1; i--)
        if (tree[i << 1] == -1 && tree[i << 1 | 1] == -1)
            tree[i] = -1;

    dfs(1), simulate(1);
    for (int i = 0; i < leaf; i++)
        val[order[i]] = A[i];

    ansX.resize(cnt), ansY.resize(cnt);
    for (int i = 0; i < cnt; i++)
        ansX[i] = X[i + 1] >= 0 ? val[X[i + 1]] : X[i + 1], ansY[i] = Y[i + 1] >= 0 ? val[Y[i + 1]] : Y[i + 1];
    answer(C, ansX, ansY);
}