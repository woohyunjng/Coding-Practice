#include <bits/stdc++.h>
#define int long long

#define MAX 100100

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

vector<pr> adj[MAX];
int parent[MAX][20], depth[MAX], len[MAX];

void dfs(int node, int par) {
    parent[node][0] = par;
    for (int i = 1; i < 20; i++)
        parent[node][i] = parent[parent[node][i - 1]][i - 1];

    for (pr i : adj[node]) {
        if (i.first == par)
            continue;
        depth[i.first] = depth[node] + 1;
        len[i.first] = len[node] + i.second;
        dfs(i.first, node);
    }
}

int lca(int A, int B) {
    if (depth[A] < depth[B])
        swap(A, B);

    int diff = depth[A] - depth[B];
    for (int i = 0; diff; i++) {
        if (diff & 1)
            A = parent[A][i];
        diff >>= 1;
    }

    for (int i = 19; i >= 0; i--) {
        if (parent[A][i] != parent[B][i])
            A = parent[A][i], B = parent[B][i];
    }
    if (A != B)
        A = parent[A][0];
    return A;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, A, B, C;
    cin >> N;

    for (int i = 1; i < N; i++) {
        cin >> A >> B >> C;
        adj[A].push_back({B, C}), adj[B].push_back({A, C});
    }

    dfs(1, 0);

    cin >> Q;
    while (Q--) {
        cin >> A >> B, C = lca(A, B);
        cout << len[A] + len[B] - 2 * len[C] << '\n';
    }

    return 0;
}