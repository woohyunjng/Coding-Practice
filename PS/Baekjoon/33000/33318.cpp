#include <bits/stdc++.h>

#define MAX 200100

using namespace std;
typedef array<int, 2> pr;

int N, sz[MAX], in[MAX], parent[MAX], depth[MAX], top[MAX], cnt, ans;
pr tree[MAX * 4], lazy[MAX * 4];
vector<int> adj[MAX];

pr merge(pr A, pr B) { return {A[0] + B[0], depth[A[1]] > depth[B[1]] ? A[1] : B[1]}; }

void lazy_propagate(int n, int s, int e) {
    if (lazy[n][0] == 0 && lazy[n][1] == 0)
        return;
    tree[n] = merge(tree[n], lazy[n]);
    if (s != e) {
        lazy[n << 1] = merge(lazy[n << 1], lazy[n]);
        lazy[n << 1 | 1] = merge(lazy[n << 1 | 1], lazy[n]);
    }
    lazy[n][0] = lazy[n][1] = 0;
}

void update(int n, int s, int e, int l, int r, pr v) {
    lazy_propagate(n, s, e);
    if (r < s || e < l)
        return;
    else if (l <= s && e <= r) {
        lazy[n] = merge(lazy[n], v);
        lazy_propagate(n, s, e);
        return;
    } else {
        int m = s + e >> 1;
        update(n << 1, s, m, l, r, v), update(n << 1 | 1, m + 1, e, l, r, v);
        tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
    }
}

pr query(int n, int s, int e, int l, int r) {
    lazy_propagate(n, s, e);
    if (r < s || e < l)
        return {0, 0};
    else if (l <= s && e <= r)
        return tree[n];
    else {
        int m = s + e >> 1;
        return merge(query(n << 1, s, m, l, r), query(n << 1 | 1, m + 1, e, l, r));
    }
}

void dfs1(int node, int par) {
    sz[node] = 1, parent[node] = par, depth[node] = depth[par] + 1;
    for (int &i : adj[node]) {
        if (i == par)
            continue;
        dfs1(i, node), sz[node] += sz[i];
        if (sz[i] > sz[adj[node][0]])
            swap(i, adj[node][0]);
    }
}

void dfs2(int node, int par) {
    in[node] = ++cnt;
    for (int i : adj[node]) {
        if (i == par)
            continue;
        top[i] = i == adj[node][0] ? top[node] : i;
        dfs2(i, node);
    }
}

void initialize(int n, vector<int> A, vector<int> B) {
    N = n;
    for (int i = 0; i < N - 1; i++)
        adj[A[i] + 1].push_back(B[i] + 1), adj[B[i] + 1].push_back(A[i] + 1);

    dfs1(1, 0), top[1] = 1, dfs2(1, 0);
    update(1, 1, N, in[1], in[1], {0, 1});
}

int generate(int v, bool result) {
    v++;
    int P = v, X = v, val;
    pr K;

    while (X) {
        K = query(1, 1, N, in[top[X]], in[X]);
        if (K[1]) {
            P = K[1];
            break;
        }
        X = parent[top[X]];
    }
    val = query(1, 1, N, in[P], in[P])[0];
    ans -= val / 2;

    if (result) {
        X = v;
        while (X) {
            if (top[X] == top[P]) {
                update(1, 1, N, in[P], in[X], {1, 0});
                break;

            } else {
                update(1, 1, N, in[top[X]], in[X], {1, 0});
                X = parent[top[X]];
            }
        }
    } else {
        for (int i : adj[v]) {
            if (i == parent[v])
                continue;
            update(1, 1, N, in[i], in[i], {0, i});
            val = query(1, 1, N, in[i], in[i])[0], ans += val / 2;
            X = v;
            while (X) {
                if (top[X] == top[P]) {
                    update(1, 1, N, in[P], in[X], {-val, 0});
                    break;

                } else {
                    update(1, 1, N, in[top[X]], in[X], {-val, 0});
                    X = parent[top[X]];
                }
            }
        }
    }
    val = query(1, 1, N, in[P], in[P])[0];
    ans += val / 2;

    return ans;
}
