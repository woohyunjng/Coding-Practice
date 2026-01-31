#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;

vector<int> adj[MAX];
int V[MAX], P[MAX], R[MAX][2];

void dfs(int node, int val) {
    if (node)
        V[val]++, V[P[node]]--;
    for (int i : adj[node])
        dfs(i, min(val, P[i]));
}

int solve(int N, int M, vector<int> F, vector<vector<int>> S) {
    for (int i = 1; i < N; i++)
        adj[F[i]].push_back(i), R[i][0] = N, R[i][1] = -1;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N - 1; j++) {
            P[S[i][j]] = j;
            R[S[i][j]][0] = min(R[S[i][j]][0], j), R[S[i][j]][1] = max(R[S[i][j]][1], j);
        }
        dfs(0, MAX);
    }

    for (int i = 1; i < N; i++)
        V[R[i][0]]++, V[R[i][1]]--;

    int ans = 0;
    for (int i = 0; i + 2 < N; i++)
        ans += V[i] == 0, V[i + 1] += V[i];

    for (int i = 0; i < N; i++)
        adj[i].clear(), V[i] = 0;

    return ans + 1;
}