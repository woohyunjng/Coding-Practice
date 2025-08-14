#include "circuit.h"
#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef array<int, 2> pr;

const int MAX = 200001;
const int MOD = 1'000'002'022;

vector<int> adj[MAX];
int A[MAX], V[MAX], C[MAX], tree[MAX * 4][2], lazy[MAX * 4], N, M;

void dfs(int node) {
    vector<int> prf, suf;
    prf.push_back(1), suf.push_back(1);

    V[node] = 1;
    for (int i : adj[node]) {
        dfs(i), V[node] = V[node] * V[i] % MOD;
        prf.push_back(prf.back() * V[i] % MOD);
    }
    if (node < N)
        V[node] = V[node] * adj[node].size() % MOD;

    reverse(adj[node].begin(), adj[node].end());
    for (int i : adj[node])
        suf.push_back(suf.back() * V[i] % MOD);

    reverse(suf.begin(), suf.end());

    reverse(adj[node].begin(), adj[node].end());
    for (int j = 0; j < adj[node].size(); j++)
        C[adj[node][j]] = prf[j] * suf[j + 1] % MOD;
}

void down_dfs(int node, int val) {
    if (node >= N)
        V[node - N] = val;
    for (int i : adj[node])
        down_dfs(i, val * C[i] % MOD);
}

void seg_init(int n, int s, int e) {
    if (s == e)
        tree[n][0] = V[s] * A[s] % MOD, tree[n][1] = V[s] * (A[s] ^ 1) % MOD;
    else {
        int m = s + e >> 1;
        seg_init(n << 1, s, m), seg_init(n << 1 | 1, m + 1, e);
        tree[n][0] = (tree[n << 1][0] + tree[n << 1 | 1][0]) % MOD;
        tree[n][1] = (tree[n << 1][1] + tree[n << 1 | 1][1]) % MOD;
    }
}

void lazy_update(int n, int s, int e) {
    if (!lazy[n])
        return;
    swap(tree[n][0], tree[n][1]);
    if (s ^ e)
        lazy[n << 1] ^= lazy[n], lazy[n << 1 | 1] ^= lazy[n];
    lazy[n] = 0;
}

void update(int n, int s, int e, int l, int r) {
    lazy_update(n, s, e);
    if (r < s || e < l)
        return;
    else if (l <= s && e <= r)
        lazy[n] = 1, lazy_update(n, s, e);
    else {
        int m = s + e >> 1;
        update(n << 1, s, m, l, r), update(n << 1 | 1, m + 1, e, l, r);
        tree[n][0] = (tree[n << 1][0] + tree[n << 1 | 1][0]) % MOD;
        tree[n][1] = (tree[n << 1][1] + tree[n << 1 | 1][1]) % MOD;
    }
}

void init(signed _N, signed _M, vector<signed> P, vector<signed> _A) {
    N = _N, M = _M;
    for (int i = 0; i < M; i++)
        A[i] = _A[i];
    for (int i = 1; i < N + M; i++)
        adj[P[i]].push_back(i);

    dfs(0), down_dfs(0, 1);
    seg_init(1, 0, M - 1);
}

signed count_ways(signed L, signed R) {
    update(1, 0, M - 1, L - N, R - N);
    return tree[1][0];
}