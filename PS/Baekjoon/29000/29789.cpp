#include "incursion.h"

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pr;

const int MAX = 45001;

int sz[MAX], parent[MAX];
vector<int> cent, adj[MAX];
bool chk[MAX];

int dfs1(int node, int par, int cap) {
    bool flag = true;
    sz[node] = 1, parent[node] = par;
    for (int i : adj[node]) {
        if (i == par)
            continue;
        dfs1(i, node, cap), sz[node] += sz[i];
        flag &= sz[i] <= cap / 2;
    }
    if (flag && (cap - sz[node]) <= cap / 2)
        cent.push_back(node);
    return sz[node];
}

void dfs2(int node, int par) {
    for (int i : adj[node]) {
        if (i == par)
            continue;
        if (i == par)
            continue;
        dfs2(i, node), chk[node] |= chk[i];
    }
}

vector<int> mark(vector<pr> F, int safe) {
    int N = F.size() + 1, X, Y;
    vector<int> ans(N, 0);

    for (int i = 0; i <= N; i++)
        adj[i].clear(), chk[i] = false;
    cent.clear();

    for (pr i : F)
        adj[i.first].push_back(i.second), adj[i.second].push_back(i.first);
    dfs1(1, 0, N), chk[safe] = true;

    if (cent.size() > 1) {
        X = cent[0], Y = cent[1];
        adj[X].erase(find(adj[X].begin(), adj[X].end(), Y)), adj[Y].erase(find(adj[Y].begin(), adj[Y].end(), X));

        adj[0].push_back(X), adj[X].push_back(0);
        adj[0].push_back(Y), adj[Y].push_back(0);
    } else
        adj[0].push_back(cent[0]), adj[cent[0]].push_back(0);

    dfs2(0, -1);

    for (int i = 1; i <= N; i++)
        ans[i - 1] = chk[i];
    return ans;
}

bool dfs3(int node, int par, int K) {
    if (K == 0) {
        visit(par);
        return false;
    }

    vector<int> child;
    for (int i : adj[node]) {
        if (i == par || chk[i])
            continue;
        child.push_back(i);
    }

    sort(child.begin(), child.end(), [&](int x, int y) { return sz[x] > sz[y]; });
    for (int i : child) {
        if (!dfs3(i, node, visit(i)))
            continue;
        return true;
    }
    return true;
}

void locate(vector<pr> F, int _X, int _K) {
    int N = F.size() + 1, X, Y, K = _K;

    for (int i = 0; i <= N; i++)
        adj[i].clear(), chk[i] = false;
    cent.clear();

    for (pr i : F)
        adj[i.first].push_back(i.second), adj[i.second].push_back(i.first);
    dfs1(1, 0, N), fill(chk + 1, chk + N + 1, false);

    if (cent.size() > 1) {
        X = cent[0], Y = cent[1];
        adj[X].erase(find(adj[X].begin(), adj[X].end(), Y)), adj[Y].erase(find(adj[Y].begin(), adj[Y].end(), X));

        adj[0].push_back(X), adj[X].push_back(0);
        adj[0].push_back(Y), adj[Y].push_back(0);
    } else
        adj[0].push_back(cent[0]), adj[cent[0]].push_back(0);
    dfs1(0, -1, N);

    X = _X, chk[X] = true;

    while (K == 0) {
        chk[X] = true;
        if (parent[X] == 0) {
            for (int j : adj[0]) {
                if (chk[j])
                    continue;
                X = j, K = visit(X), chk[X] = true;
                if (K > 0)
                    break;
            }
        } else
            X = parent[X], K = visit(X);
    }

    dfs3(X, parent[X], K);
}