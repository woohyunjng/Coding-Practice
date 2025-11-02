#include <bits/stdc++.h>
using namespace std;

const int MAX = 10000;

vector<int> adj[MAX];
int C[MAX], D, depth[MAX];

void dfs(int node, int par) {
    depth[node] = depth[par] + 1;
    vector<int> arr;

    for (int i : adj[node]) {
        if (depth[i] != 0 && depth[i] < depth[node])
            continue;
        if (depth[i] == 0)
            dfs(i, node);
        arr.push_back(C[i]);
    }

    sort(arr.begin(), arr.end()), arr.erase(unique(arr.begin(), arr.end()), arr.end());
    for (int i = 1; i <= D; i++) {
        if (arr.size() < i || arr[i - 1] != i) {
            C[node] = i;
            break;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, U, V;
    cin >> N >> M;

    while (M--) {
        cin >> U >> V;
        adj[U].push_back(V), adj[V].push_back(U);
    }

    for (int i = 1; i <= N; i++) {
        D = max(D, (int)adj[i].size() + 1 - (int)adj[i].size() % 2);
        if (adj[i].size() < D)
            V = i;
    }

    dfs(V, 0);

    cout << D << '\n';
    for (int i = 1; i <= N; i++)
        cout << C[i] << '\n';

    return 0;
}