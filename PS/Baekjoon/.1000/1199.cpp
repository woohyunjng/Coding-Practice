#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000001;

int N, U[MAX], V[MAX], C[MAX], in[MAX];
vector<int> adj[MAX], ans;

void dfs(int node) {
    int X;
    while (!adj[node].empty()) {
        X = adj[node].back(), adj[node].pop_back();
        while (C[X] > 0)
            C[X]--, dfs(U[X] ^ V[X] ^ node);
    }
    ans.push_back(node);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int X, K = 0;
    bool flag = true;

    cin >> N;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++) {
            cin >> X;
            if (i >= j || X == 0)
                continue;
            U[++K] = i, V[K] = j, C[K] = X;
            adj[i].push_back(K), adj[j].push_back(K);
            in[i] += X, in[j] += X;
        }

    for (int i = 1; i <= N; i++)
        flag &= in[i] % 2 == 0;
    if (!flag) {
        cout << -1 << '\n';
        return 0;
    }

    dfs(1);
    for (int i : ans)
        cout << i << ' ';
    cout << '\n';

    return 0;
}