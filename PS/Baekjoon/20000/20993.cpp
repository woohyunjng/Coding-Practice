#include <bits/stdc++.h>
using namespace std;

typedef array<int, 2> pr;

const int MAX = 1000001;

int N, M, cnt[MAX], C[MAX], V[MAX];
bool chk[MAX];
pr go[2] = {{1, 0}, {0, 1}};

vector<int> fadj[MAX], frev[MAX], adj[MAX], rev[MAX],
    arr;

void dfs1(int node) {
    chk[node] = true, V[node]++;
    for (int i : frev[node])
        if (!chk[i])
            dfs1(i);
}

void dfs2(int node) {
    chk[node] = true, V[node]++;
    for (int i : fadj[node])
        if (!chk[i])
            dfs2(i);
}

void remove(int node) {
    arr.push_back(node);
    for (int i : adj[node]) {
        rev[i].erase(find(rev[i].begin(), rev[i].end(), node));
        if (rev[i].empty())
            remove(i);
    }
}

void removeb(int node) {
    arr.push_back(node);
    for (int i : rev[node]) {
        adj[i].erase(find(adj[i].begin(), adj[i].end(), node));
        if (adj[i].empty())
            removeb(i);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int Q, X, Y, A, B;

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> C[i * M + j];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            A = i * M + j;
            if (C[A])
                continue;

            for (pr k : go) {
                X = i + k[0], Y = j + k[1], B = X * M + Y;
                if (X >= N || Y >= M || C[B])
                    continue;
                fadj[A].push_back(B), frev[B].push_back(A);
            }
        }

    for (int i = 0; i < N * M; i++)
        C[i] = 1;

    fill(chk, chk + N * M, false), dfs1(N * M - 1);
    fill(chk, chk + N * M, false), dfs2(0);

    for (int i = 0; i < N * M; i++) {
        if (V[i] != 2)
            C[i] = 1;
        else
            C[i] = 0, cnt[i % M + i / M]++;
    }

    for (int i = 0; i < N * M; i++) {
        if (C[i])
            continue;
        for (int j : fadj[i])
            if (!C[j])
                adj[i].push_back(j);
        for (int j : frev[i])
            if (!C[j])
                rev[i].push_back(j);
    }

    cin >> Q;
    while (Q--) {
        cin >> X >> Y, X--, Y--;
        X = X * M + Y;

        if (C[X]) {
            cout << 1 << '\n';
            continue;
        }

        if (cnt[X % M + X / M] == 1) {
            cout << 0 << '\n';
            continue;
        }

        cout << 1 << '\n', arr.clear();
        remove(X), removeb(X);

        sort(arr.begin(), arr.end()), arr.erase(unique(arr.begin(), arr.end()), arr.end());
        for (int i : arr)
            C[i] = 1, cnt[i % M + i / M]--, adj[i].clear(), rev[i].clear();
        arr.clear();
    }

    return 0;
}