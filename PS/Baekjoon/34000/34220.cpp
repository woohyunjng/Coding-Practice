#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;

vector<int> adj[MAX];

int parent[MAX], depth[MAX];

void dfs(int node, int par) {
    parent[node] = par, depth[node] = depth[par] + 1;
    for (int i : adj[node]) {
        if (i == par)
            continue;
        dfs(i, node);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, U, V, R, X = 0;
    vector<int> arr;

    cin >> N;
    for (int i = 1; i < N; i++) {
        cin >> U >> V;
        adj[U].push_back(V), adj[V].push_back(U);
    }

    for (int i = 1; i <= N; i++)
        if (adj[i].size() == 1)
            R = i;
    dfs(R, 0);

    for (int i = 1; i <= N; i++)
        if (depth[i] > depth[X])
            X = i;

    if (depth[X] >= 4) {
        while (arr.size() < 4)
            arr.push_back(X), X = parent[X];

        cout << 3 << '\n';
        cout << arr[0] << ' ' << arr[2] << '\n';
        cout << arr[0] << ' ' << arr[3] << '\n';
        cout << arr[1] << ' ' << arr[3] << '\n';
    } else {
        X = parent[X];
        for (int i : adj[X])
            if (arr.size() < 3)
                arr.push_back(i);

        cout << 3 << '\n';
        cout << arr[0] << ' ' << arr[1] << '\n';
        cout << arr[0] << ' ' << arr[2] << '\n';
        cout << arr[1] << ' ' << arr[2] << '\n';
    }

    return 0;
}