#include <bits/stdc++.h>
using namespace std;

vector<int> ans, tmp, adj[3];
int U[3], V[3], C[3];

void dfs(int node) {
    int X;
    while (!adj[node].empty()) {
        X = adj[node].back();
        if (C[X] > 0)
            C[X]--, dfs(U[X] ^ V[X] ^ node);
        else
            adj[node].pop_back();
    }
    ans.push_back(node);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;

    cin >> N;
    if (N % 5 != 1) {
        cout << "No" << '\n';
        return 0;
    }

    N = (N - 1) / 5;
    U[0] = 0, V[0] = 1, C[0] = N << 1, adj[0].push_back(0), adj[1].push_back(0);
    U[1] = 1, V[1] = 2, C[1] = N << 1, adj[1].push_back(1), adj[2].push_back(1);
    U[2] = 0, V[2] = 2, C[2] = N, adj[0].push_back(2), adj[2].push_back(2);

    dfs(0);

    cout << "Yes" << '\n';
    for (int i : ans)
        cout << i << ' ';
    cout << '\n';

    return 0;
}