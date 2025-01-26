#include "werewolf.h"
#include <bits/stdc++.h>

#define MAX 300000
#define MAX_LOG 22

using namespace std;

vector<int> tree[MAX * 2], adj[MAX], child[MAX][2];
int N, union_par[MAX][2], A[MAX], in[MAX][2], out[MAX][2], cnt, parent[MAX][MAX_LOG][2];

int find(int t, int x) { return x == union_par[x][t] ? x : union_par[x][t] = find(t, union_par[x][t]); }

void dfs(int t, int n) {
    in[n][t] = cnt++;
    for (int i = 1; i < MAX_LOG; i++)
        if (parent[n][i - 1][t] != -1)
            parent[n][i][t] = parent[parent[n][i - 1][t]][i - 1][t];

    for (int i : child[n][t])
        dfs(t, i);
    out[n][t] = cnt;
}

void init() {
    for (int i = 0; i < N; i++)
        tree[i + N].push_back(A[i]);
    for (int i = N - 1; i > 0; i--) {
        tree[i].resize(tree[i << 1].size() + tree[i << 1 | 1].size());
        merge(tree[i << 1].begin(), tree[i << 1].end(), tree[i << 1 | 1].begin(), tree[i << 1 | 1].end(), tree[i].begin());
    }
}

int query(int l, int r, int x, int y) {
    int res = 0;
    for (l += N, r += N + 1; l < r; l >>= 1, r >>= 1) {
        if (l & 1)
            res += upper_bound(tree[l].begin(), tree[l].end(), y) - lower_bound(tree[l].begin(), tree[l].end(), x), l++;
        if (r & 1)
            r--, res += upper_bound(tree[r].begin(), tree[r].end(), y) - lower_bound(tree[r].begin(), tree[r].end(), x);
    }
    return res;
}

vector<int> check_validity(int n, vector<int> X, vector<int> Y,
                           vector<int> S, vector<int> E,
                           vector<int> L, vector<int> R) {
    N = n;
    int M = X.size(), Q = S.size(), l, r, x, y, Z;

    for (int i = 0; i < M; i++)
        adj[X[i]].push_back(Y[i]), adj[Y[i]].push_back(X[i]);

    for (int i = 0; i < N; i++) {
        union_par[i][0] = union_par[i][1] = i;
        for (int j = 0; j < MAX_LOG; j++)
            parent[i][j][0] = parent[i][j][1] = -1;
    }

    for (int i = N - 1; i >= 0; i--) {
        for (int j : adj[i]) {
            if (j < i || find(0, i) == find(0, j))
                continue;
            child[i][0].push_back(find(0, j));
            parent[find(0, j)][0][0] = i, union_par[find(0, j)][0] = i;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j : adj[i]) {
            if (j > i || find(1, i) == find(1, j))
                continue;
            child[i][1].push_back(find(1, j));
            parent[find(1, j)][0][1] = i, union_par[find(1, j)][1] = i;
        }
    }

    cnt = 0, dfs(0, 0);
    cnt = 0, dfs(1, N - 1);

    for (int i = 0; i < N; i++)
        A[in[i][0]] = in[i][1];
    init();

    vector<int> ans(Q);
    for (int i = 0; i < Q; ++i) {
        Z = S[i];
        for (int j = MAX_LOG - 1; j >= 0; j--)
            if (parent[Z][j][0] != -1 && parent[Z][j][0] >= L[i])
                Z = parent[Z][j][0];
        l = in[Z][0], r = out[Z][0] - 1;

        Z = E[i];
        for (int j = MAX_LOG - 1; j >= 0; j--) {
            if (parent[Z][j][1] != -1 && parent[Z][j][1] <= R[i])
                Z = parent[Z][j][1];
        }
        x = in[Z][1], y = out[Z][1] - 1;

        ans[i] = query(l, r, x, y) > 0;
    }

    return ans;
}