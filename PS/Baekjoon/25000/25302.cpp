#include "cactus.h"
#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;

const int MAX = 500001;
const int MAX_LOG = 21;

int N, H[MAX], V[MAX], G[MAX][2];
pr sparse[MAX][MAX_LOG][2];

void init(vector<signed> h) {
    N = h.size();
    for (int i = 0; i < N; i++) {
        H[i + 1] = h[i], V[i + 1] = V[i] + H[i + 1];
        G[i + 1][0] = N + 1, G[i + 1][1] = 0;
    }

    vector<int> st;
    int X;

    st.clear();
    for (int i = 1; i <= N; i++) {
        while (!st.empty() && H[st.back()] < H[i])
            X = st.back(), st.pop_back(), G[X][0] = i - 1;
        st.push_back(i);
    }

    st.clear();
    for (int i = N; i >= 1; i--) {
        while (!st.empty() && H[st.back()] < H[i])
            X = st.back(), st.pop_back(), G[X][1] = i + 1;
        st.push_back(i);
    }

    for (int i = 1; i <= N; i++) {
        sparse[i][0][0] = {H[i] * (G[i][0] == N + 1 ? 0 : G[i][0] - i + 1), G[i][0]};
        sparse[i][0][1] = {H[i] * (G[i][1] == 0 ? 0 : i - G[i][1] + 1), G[i][1]};
    }

    for (int i = 1; i < MAX_LOG; i++)
        for (int j = 1; j <= N; j++) {
            sparse[j][i][0] = {
                sparse[j][i - 1][0][0] + sparse[sparse[j][i - 1][0][1] + 1][i - 1][0][0],
                sparse[sparse[j][i - 1][0][1] + 1][i - 1][0][1]};
            sparse[j][i][1] = {
                sparse[j][i - 1][1][0] + sparse[sparse[j][i - 1][1][1] - 1][i - 1][1][0],
                sparse[sparse[j][i - 1][1][1] - 1][i - 1][1][1]};
        }
}

int query(signed S, signed E) {
    int ans = 0;
    S++, E++;

    for (int i = MAX_LOG - 1; i >= 0; i--) {
        if (sparse[S][i][0][1] <= E)
            ans += sparse[S][i][0][0], S = sparse[S][i][0][1] + 1;
    }

    for (int i = MAX_LOG - 1; i >= 0; i--) {
        if (sparse[E][i][1][1] >= S)
            ans += sparse[E][i][1][0], E = sparse[E][i][1][1] - 1;
    }

    return ans - (V[E] - V[S - 1]);
}