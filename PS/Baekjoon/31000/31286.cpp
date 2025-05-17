#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef array<int, 2> pr;
typedef array<int, 3> tp;

const int MAX = 500001;
const int MOD = 1000000007;

vector<pr> adj[MAX];
int par[MAX], sz[MAX], depth[2][MAX];

int find(int X) { return par[X] == X ? X : par[X] = find(par[X]); }
void uni(int X, int Y) {
    X = find(X), Y = find(Y);
    if (X > Y)
        swap(X, Y);
    par[Y] = X, sz[X] += sz[Y], sz[Y] = 0;
}

void dfs(int node, int par, int t) {
    for (pr i : adj[node]) {
        if (i[0] == par)
            continue;
        depth[t][i[0]] = depth[t][node] + i[1], dfs(i[0], node, t);
    }
}

signed travel(vector<signed> U, vector<signed> V, vector<signed> W) {
    int N = U.size() + 1, X, Y, ans = 0;

    for (int i = 0; i < N - 1; i++) {
        adj[U[i]].push_back({V[i], W[i]});
        adj[V[i]].push_back({U[i], W[i]});
    }

    depth[0][0] = 0, dfs(0, -1, 0), X = max_element(depth[0], depth[0] + N) - depth[0];
    depth[0][X] = 0, dfs(X, -1, 0), Y = max_element(depth[0], depth[0] + N) - depth[0];
    dfs(Y, -1, 1);

    vector<tp> arr;

    arr.push_back({depth[1][Y], X, Y});
    for (int i = 0; i < N; i++) {
        par[i] = i, sz[i] = 1;
        if (i == X || i == Y)
            continue;
        if (depth[0][i] > depth[1][i])
            arr.push_back({depth[0][i], i, X});
        else
            arr.push_back({depth[1][i], i, Y});
    }

    sort(arr.begin(), arr.end(), greater<tp>());

    for (tp i : arr) {
        ans = (ans + i[0] * sz[find(i[1])] % MOD * sz[find(i[2])] % MOD * 2) % MOD;
        uni(i[1], i[2]);
    }

    return ans;
}
