#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000001;

int A[MAX], U[MAX], V[MAX], _ans[MAX];
vector<int> adj[MAX];

int ans(int val) {
    if (_ans[val])
        return _ans[val];

    int X = -1;
    if (adj[V[val]][0] != (val ^ 1))
        X = adj[V[val]][0];
    else if (adj[V[val]].size() > 1)
        X = adj[V[val]][1];
    return _ans[val] = X == -1 ? V[val] : ans(X);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, Y;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    for (int i = 0; i + 1 < N; i++) {
        cin >> X >> Y;
        adj[X].push_back(i << 1), U[i << 1] = X, V[i << 1] = Y;
        adj[Y].push_back((i << 1) | 1), U[(i << 1) | 1] = Y, V[(i << 1) | 1] = X;
    }

    for (int i = 1; i <= N; i++)
        sort(adj[i].begin(), adj[i].end(), [&](int x, int y) { return A[V[x]] > A[V[y]]; });

    for (int i = 1; i <= N; i++)
        cout << ans(adj[i][0]) << '\n';

    return 0;
}