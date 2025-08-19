#include "beechtree.h"
#include <bits/stdc++.h>
using namespace std;

typedef array<int, 2> pr;

const int MAX = 200000;

int N, M, P[MAX], C[MAX],
    ans[MAX], S[MAX];
vector<int> adj[MAX];
set<pr> st[MAX];
map<int, int> mp[MAX];

bool chk(int X, int Y) {
    bool flag = adj[X].size() >= adj[Y].size();
    for (int i : adj[Y])
        flag &= mp[X].find(C[i]) != mp[X].end() && S[mp[X][C[i]]] >= S[i];
    return flag;
}

void dfs(int node) {
    set<int> ol;
    set<pr>::iterator iter;
    pr K;

    S[node] = 1;
    for (int i : adj[node]) {
        dfs(i), S[node] += S[i];
        ans[node] &= ans[i], ol.insert(C[i]);
    }
    ans[node] &= ol.size() == adj[node].size();

    st[node].insert({-S[node], node});
    for (int i : adj[node]) {
        if (st[node].size() < st[i].size())
            swap(st[node], st[i]);
        while (!st[i].empty() && ans[node]) {
            K = *st[i].begin(), st[i].erase(st[i].begin());
            iter = st[node].lower_bound(K);
            ans[node] &= iter == st[node].end() || chk(K[1], (*iter)[1]);
            ans[node] &= iter == st[node].begin() || chk((*prev(iter))[1], K[1]);
            st[node].insert(K);
        }
    }
}

vector<int> beechtree(int _N, int _M, vector<int> _P, vector<int> _C) {
    N = _N, M = _M, fill(ans, ans + N, 1);
    for (int i = 1; i < N; i++) {
        P[i] = _P[i], adj[P[i]].push_back(i);
        C[i] = _C[i], mp[P[i]][C[i]] = i;
    }

    dfs(0);

    vector<int> ans_v(N, 0);
    for (int i = 0; i < N; i++)
        ans_v[i] = ans[i];

    return ans_v;
}