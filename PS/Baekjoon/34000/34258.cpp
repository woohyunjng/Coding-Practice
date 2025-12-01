#include "macht.h"
#include <bits/stdc++.h>
using namespace std;

const int MAX = 50001;
const int INF = 100000;

vector<int> adj[MAX], arr[MAX];
int N, sz[MAX], top[MAX], W[MAX], D[MAX];
bool chk[MAX];

void dfs1(int node) {
    sz[node] = 1;
    for (int &i : adj[node]) {
        dfs1(i), sz[node] += sz[i];
        if (sz[i] > sz[adj[node][0]])
            swap(i, adj[node][0]);
    }
}

void dfs2(int node) {
    arr[top[node]].push_back(node);
    for (int i : adj[node]) {
        top[i] = i == adj[node][0] ? top[node] : i;
        dfs2(i);
    }
}

void unravel(vector<int> U, vector<int> V) {
    int N = (int)U.size() + 1, ans = INF, val;
    for (int i = 0; i < N - 1; i++)
        adj[U[i]].push_back(V[i]), D[V[i]] = i;

    vector<int> rt, nxt, leaf, R(N - 1, 0), F(N, 0);
    vector<vector<int>> lst;

    dfs1(0), dfs2(0);
    for (int i : adj[0])
        rt.push_back(top[i]);

    while (!rt.empty()) {
        lst.push_back(rt);
        for (int i : rt)
            chk[i] = true;

        for (int i : rt)
            for (int j : arr[i])
                for (int k : adj[j])
                    if (!chk[top[k]])
                        nxt.push_back(top[k]);
        rt = nxt, nxt.clear();
    }

    mt19937 rng(random_device{}());
    shuffle(lst.begin(), lst.end(), rng);

    for (vector<int> v : lst) {
        fill(F.begin(), F.end(), 0), fill(R.begin(), R.end(), 1), leaf.clear();
        for (int i : v) {
            leaf.push_back(arr[i].back()), F[leaf.back()] = ans;
            for (int j : arr[i])
                R[D[j]] = j == 0 ? R[D[j]] : 0;
        }

        if (trigger(R, F) != ((long long)ans) * (long long)leaf.size()) {
            val = 0;
            for (long long st = 1, en = ans - 1, md; st <= en;) {
                md = st + en >> 1;
                for (int i : leaf)
                    F[i] = md;
                if (trigger(R, F) == md * (long long)leaf.size())
                    val = md, st = md + 1;
                else
                    en = md - 1;
            }
            ans = min(ans, val);
        }
    }

    answer(ans);
}
