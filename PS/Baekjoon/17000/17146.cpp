#include <bits/stdc++.h>
using namespace std;

const int MAX = 3001;

typedef array<int, 2> pr;

int A[MAX][MAX], uf[MAX];
vector<int> adj[MAX];

int find(int X) { return X == uf[X] ? X : uf[X] = find(uf[X]); }

bool uni(int X, int Y) {
    X = find(X), Y = find(Y);
    if (X == Y)
        return false;
    else {
        uf[X] = Y;
        return true;
    }
}

void dfs(int node, int par, int X, int Y) {
    if (A[X][node] == A[Y][node]) {
        uni(X, node);
        return;
    }

    for (int i : adj[node]) {
        if (i == par)
            continue;
        dfs(i, node, X, Y);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int _T, N, X, Y;
    vector<pr> ans;

    cin >> _T >> N;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> A[i][j];

    for (int i = 1; i <= N; i++)
        uf[i] = i;

    for (int i = 1; i <= N; i++)
        for (int j = i + 1; j <= N; j++) {
            X = find(i), Y = find(j);
            if (A[i][j] != 1 || !uni(X, Y))
                continue;
            ans.push_back({X, Y});
            adj[X].push_back(Y), adj[Y].push_back(X);
        }

    for (int i = 1; i <= N; i++)
        for (int j = i + 1; j <= N; j++) {
            X = find(i), Y = find(j);
            if (A[i][j] != 2 || !uni(X, Y))
                continue;
            ans.push_back({i, j});
            adj[i].push_back(j), adj[j].push_back(i);
        }

    for (int i = 1; i <= N; i++)
        uf[i] = i;

    for (int i = 1; i <= N; i++)
        for (int j : adj[i])
            dfs(j, i, i, j);

    for (int i = 1; i <= N; i++)
        cout << find(i) << ' ';
    cout << '\n';
    for (pr i : ans)
        cout << i[0] << ' ' << i[1] << '\n';
}