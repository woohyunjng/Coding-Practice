#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;

vector<int> adj[MAX], dir[MAX];
int ans[MAX], in[MAX];

void dfs(int node, int par, int val) {
    vector<int> arr;

    if (val)
        dir[par].push_back(node), in[node]++;
    else
        dir[node].push_back(par), in[par]++;

    for (int i : adj[node])
        if (i != par)
            arr.push_back(i);

    for (int i = 0; i < (arr.size() + val) / 2; i++)
        dfs(arr[i], node, 1);
    for (int i = (arr.size() + val) / 2; i < arr.size(); i++)
        dfs(arr[i], node, 0);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, U, V;
    queue<int> q;

    cin >> N;
    for (int i = 1; i < N; i++) {
        cin >> U >> V;
        adj[U].push_back(V), adj[V].push_back(U);
    }

    for (int i = 0; i < adj[1].size() / 2; i++)
        dfs(adj[1][i], 1, 1);
    for (int i = adj[1].size() / 2; i < adj[1].size(); i++)
        dfs(adj[1][i], 1, 0);

    for (int i = 1; i <= N; i++)
        if (!in[i])
            q.push(i);

    V = 0;
    while (!q.empty()) {
        U = q.front(), q.pop(), ans[U] = ++V;
        for (int i : adj[U])
            if (!--in[i])
                q.push(i);
    }

    for (int i = 1; i <= N; i++)
        cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}