#include "island.h"
#include <bits/stdc++.h>
using namespace std;

typedef array<int, 2> pr;

const int MAX = 200100;

int cnt[MAX];
bool vst[MAX];
vector<int> adj[MAX];

void construct_two_trees(int N, vector<int> U, vector<int> V) {
    vector<pr> tree[2];

    for (int i = 0; i < N - 3; i++)
        adj[U[i]].push_back(V[i]), adj[V[i]].push_back(U[i]);
    for (int i = 0; i < N; i++)
        adj[i].push_back((i + 1) % N), adj[(i + 1) % N].push_back(i);

    for (int i = 0; i < N; i++)
        cnt[i] = adj[i].size();

    queue<int> q;
    int X, Y, Z;

    for (int i = 0; i < N; i++)
        if (cnt[i] == 2)
            q.push(i), vst[i] = true;

    for (int i = 0; i < N - 3; i++) {
        X = q.front(), q.pop(), Y = 0;
        for (int j : adj[X]) {
            if (vst[j])
                continue;
            tree[Y++].push_back({X, j});
            if (--cnt[j] == 2)
                q.push(j), vst[j] = true;
        }
    }

    X = q.front(), q.pop(), Y = q.front(), q.pop(), Z = q.front(), q.pop();
    add_vertex(X, Y, Z);

    tree[0].push_back({N, X}), tree[0].push_back({N, Y}), tree[0].push_back({Y, Z});
    tree[1].push_back({N, Z}), tree[1].push_back({X, Y}), tree[1].push_back({X, Z});

    report(tree[0]), report(tree[1]);
}
