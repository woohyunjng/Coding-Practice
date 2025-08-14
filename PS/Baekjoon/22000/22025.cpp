#include "parks.h"
#include <bits/stdc++.h>
using namespace std;

typedef array<int, 2> pr;

const int MAX = 800001;

int N, M, X[MAX], Y[MAX], FX[MAX], FY[MAX], U[MAX], V[MAX], uf[MAX];
pr go[4] = {{0, -2}, {0, 2}, {-2, 0}, {2, 0}};
map<pr, int> mp;

int find(int X) { return uf[X] == X ? X : uf[X] = find(uf[X]); }
void uni(int X, int Y) {
    X = find(X), Y = find(Y);
    if (X == Y)
        return;
    if (X > Y)
        swap(X, Y);
    uf[Y] = X;
}

int construct_roads(vector<int> x, vector<int> y) {
    int A, B;
    bool connected = true;
    vector<int> ans[4];

    N = x.size();
    for (int i = 0; i < N; i++) {
        X[i] = x[i], Y[i] = y[i], uf[i] = i;
        for (int j = 0; j < 4; j++) {
            A = X[i] + go[j][0], B = Y[i] + go[j][1];
            if (mp.find({A, B}) == mp.end())
                continue;
            U[M] = mp[{A, B}], V[M] = i, uni(U[M], V[M]), M++;
        }
        mp[{X[i], Y[i]}] = i;
    }
    mp.clear();

    for (int i = 0; i < N; i++)
        connected &= find(0) == find(i);
    if (!connected)
        return 0;

    for (int i = 0; i < M; i++) {
        if (X[U[i]] == X[V[i]]) {
            A = X[U[i]], B = (Y[U[i]] + Y[V[i]]) / 2;
            if ((A + 1) / 2 % 2 + B / 2 % 2 == 1)
                FX[i] = A + 1, FY[i] = B;
        } else {
            A = (X[U[i]] + X[V[i]]) / 2, B = Y[U[i]];
            if ((A / 2 % 2 + (B + 1) / 2 % 2) % 2 == 0)
                FX[i] = A, FY[i] = B + 1;
        }
        if (FX[i] != 0)
            mp[{FX[i], FY[i]}] = i;
    }

    for (int i = 0; i < M; i++) {
        if (FX[i])
            continue;
        if (X[U[i]] == X[V[i]]) {
            A = X[U[i]], B = (Y[U[i]] + Y[V[i]]) / 2;
            if (mp.find({A - 1, B}) == mp.end())
                FX[i] = A - 1, FY[i] = B;
        } else {
            A = (X[U[i]] + X[V[i]]) / 2, B = Y[U[i]];
            if (mp.find({A, B - 1}) == mp.end())
                FX[i] = A, FY[i] = B - 1;
        }
        if (FX[i] != 0)
            mp[{FX[i], FY[i]}] = i;
    }

    for (int i = 0; i < M; i++) {
        if (!FX[i])
            continue;
        ans[0].push_back(U[i]), ans[1].push_back(V[i]);
        ans[2].push_back(FX[i]), ans[3].push_back(FY[i]);
    }

    build(ans[0], ans[1], ans[2], ans[3]);
    return 1;
}