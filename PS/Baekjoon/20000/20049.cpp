#include <bits/stdc++.h>
using namespace std;

typedef array<int, 2> pr;

const int MAX = 500001;

int D[MAX], depth[MAX], parent[MAX];
bool chk[MAX];

vector<int> adj[MAX];

void dfs1(int node, int par) {
    depth[node] = depth[par] + 1, parent[node] = par;
    for (int i : adj[node]) {
        if (i == par)
            continue;
        dfs1(i, node);
    }
}

void dfs2(int node) {
    chk[node] = true;
    for (int i : adj[node])
        if (D[i] + 1 == D[node] && D[node] > 0 && !chk[i])
            dfs2(i);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, U, V, X;
    vector<int> arr, ans;
    queue<int> q;

    cin >> N >> K, fill(D + 1, D + N + 1, MAX);
    for (int i = 1; i < N; i++) {
        cin >> U >> V;
        adj[U].push_back(V), adj[V].push_back(U);
    }
    dfs1(1, 0);

    for (int i = 1; i <= K; i++) {
        cin >> U, D[U] = 0, q.push(U);
        arr.push_back(U);
    }
    sort(arr.begin(), arr.end(), [&](int x, int y) { return depth[x] > depth[y]; });

    while (!q.empty()) {
        U = q.front(), q.pop();
        for (int i : adj[U]) {
            if (D[i] != MAX)
                continue;
            D[i] = D[U] + 1, q.push(i);
        }
    }

    for (int i : arr) {
        if (chk[i])
            continue;
        X = i;
        while (parent[X] != 0 && (D[parent[X]] + depth[parent[X]] == depth[i]))
            X = parent[X];
        dfs2(X), ans.push_back(X);
    }

    cout << ans.size() << '\n';
    for (int i : ans)
        cout << i << ' ';
    cout << '\n';
}