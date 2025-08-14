#include "tickets.h"
#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef array<int, 2> pr;

const int MAX = 1500;

int V[MAX][MAX], R[MAX], L[MAX];
bool chk[MAX];
vector<int> D[MAX][2];

int find_maximum(signed K, vector<vector<signed>> X) {
    int N = X.size(), M = X[0].size(), ans = 0, C;

    vector<int> idx;
    vector<vector<signed>> ans_v;
    ans_v.resize(N, vector<signed>(M, -1));

    priority_queue<pr, vector<pr>, greater<pr>> pq;
    pr Y;

    for (int i = 0; i < N; i++)
        idx.push_back(i);

    for (int i = 0; i < N; i++) {
        for (int j = M - K; j < M; j++)
            V[i][j] = 1, ans += X[i][j];
        L[i] = 0, R[i] = M - K;
        pq.push({X[i][L[i]] + X[i][R[i]], i});
    }

    C = N / 2 * K;
    while (C--) {
        Y = pq.top(), pq.pop(), ans -= Y[0];
        V[Y[1]][R[Y[1]]++] = 0, V[Y[1]][L[Y[1]]++] = -1;
        if (R[Y[1]] < M)
            pq.push({X[Y[1]][L[Y[1]]] + X[Y[1]][R[Y[1]]], Y[1]});
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            if (V[i][j] == 0)
                continue;
            D[i][(V[i][j] + 1) / 2].push_back(j);
        }

    for (int i = 0; i < K; i++) {
        sort(idx.begin(), idx.end(), [&](int x, int y) { return D[x][0].size() > D[y][0].size(); });
        for (int j = 0; j < N / 2; j++) {
            ans_v[idx[j]][D[idx[j]][0].back()] = i, D[idx[j]][0].pop_back();
            ans_v[idx[j + N / 2]][D[idx[j + N / 2]][1].back()] = i, D[idx[j + N / 2]][1].pop_back();
        }
    }

    allocate_tickets(ans_v);

    return ans;
}