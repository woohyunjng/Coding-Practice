#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 100000;
const int INF = 0x3f3f3f3f3f3f3f3f;

vector<int> adj[MAX];
int N, K, C[MAX], W[MAX], L[MAX], R[MAX],
    dp[MAX][2][2][2], cnt;

void dfs(int node) {
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                dp[node][i][j][k] = INF;

    L[node] = INF;
    if (adj[node].empty()) {
        L[node] = R[node] = cnt++;
        for (int i = 0; i < 2; i++)
            dp[node][i][i][i] = 0;
        return;
    }

    array<array<array<int, 2>, 2>, 2> tmp;

    for (int i : adj[node]) {
        dfs(i);
        if (L[node] == INF) {
            for (int j = 0; j < 2; j++)
                for (int k = 0; k < 2; k++)
                    for (int l = 0; l < 2; l++)
                        for (int r = 0; r < 2; r++)
                            dp[node][j][l][r] = min(dp[node][j][l][r], dp[i][k][l][r] + (j == k ? C[i] : 0));
        } else {
            for (int j = 0; j < 2; j++)
                for (int l = 0; l < 2; l++)
                    for (int r = 0; r < 2; r++)
                        tmp[j][l][r] = dp[node][j][l][r], dp[node][j][l][r] = INF;
            for (int j = 0; j < 2; j++)
                for (int k = 0; k < 2; k++)
                    for (int l = 0; l < 2; l++)
                        for (int xr = 0; xr < 2; xr++)
                            for (int xl = 0; xl < 2; xl++)
                                for (int r = 0; r < 2; r++)
                                    dp[node][j][l][r] = min(dp[node][j][l][r], tmp[j][l][xr] + dp[i][k][xl][r] + (j == k ? C[i] : 0ll) + (xr == xl ? W[R[node]] : 0ll));
        }
        L[node] = min(L[node], L[i]), R[node] = max(R[node], R[i]);
    }
}

int place_police(vector<signed> P, vector<int> _C, vector<int> _W) {
    int ans = INF;

    N = P.size() + 1, K = _W.size();
    for (int i = 0; i + 1 < N; i++)
        adj[P[i]].push_back(i + 1), C[i + 1] = _C[i];
    for (int i = 0; i < K; i++)
        W[i] = _W[i];

    dfs(0);
    for (int i = 0; i < 2; i++)
        for (int l = 0; l < 2; l++)
            for (int r = 0; r < 2; r++)
                ans = min(ans, dp[0][i][l][r] + (l == r ? W[K - 1] : 0));
    return ans;
}