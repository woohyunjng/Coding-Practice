#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pr;

const int MAX = 201;

int D[MAX], S[MAX];
vector<int> adj[MAX];

void dfs(int node, int par) {
    D[node] = D[par] + 1, S[node] = 1;
    for (int i : adj[node]) {
        if (i == par)
            continue;
        dfs(i, node), S[node] += S[i];
    }
}

int get_cent(int node, int par, int cap) {
    for (int i : adj[node]) {
        if (i == par)
            continue;
        if (S[i] * 2 > cap)
            return get_cent(i, node, cap);
    }
    return node;
}

vector<pr> encode_map(int N, int K, int &X, vector<pr> E) {
    vector<pr> res;

    for (int i = 1; i <= N; i++)
        adj[i].clear();
    for (pr i : E)
        adj[i.first].push_back(i.second), adj[i.second].push_back(i.first);

    dfs(1, 0), X = get_cent(1, 0, N), dfs(X, 0);

    for (int i = 1; i <= N; i++)
        for (int j = i + 1; j <= N; j++)
            if (K > 0 && D[i] == D[j])
                res.push_back({i, j}), K--;

    return res;
}

vector<pr> decode_map(int N, int K, int X, vector<pr> E) {
    vector<pr> res;
    queue<int> q;

    int Y;

    for (int i = 1; i <= N; i++)
        adj[i].clear(), D[i] = 0;
    for (pr i : E)
        adj[i.first].push_back(i.second), adj[i.second].push_back(i.first);

    q.push(X), D[X] = 1;
    while (!q.empty()) {
        Y = q.front(), q.pop();
        for (int i : adj[Y]) {
            if (D[i] != 0)
                continue;
            D[i] = D[Y] + 1, q.push(i);
            res.push_back({Y, i});
        }
    }

    return res;
}