#include <bits/stdc++.h>
using namespace std;

const int MAX = 200001;
const int MAX_LOG = 20;

int N, parent[MAX][MAX_LOG], depth[MAX];
vector<int> adj[MAX], arr[MAX];

void dfs(int node, int par) {
    depth[node] = depth[par] + 1, parent[node][0] = par;
    for (int i = 1; i < MAX_LOG; i++)
        parent[node][i] = parent[parent[node][i - 1]][i - 1];

    for (int i : adj[node])
        dfs(i, node);
}

int LCA(int A, int B) {
    if (depth[A] < depth[B])
        swap(A, B);

    int diff = depth[A] - depth[B];
    for (int i = 0; diff; i++) {
        if (diff & 1)
            A = parent[A][i];
        diff >>= 1;
    }

    for (int i = MAX_LOG - 1; i >= 0; i--)
        if (parent[A][i] != parent[B][i])
            A = parent[A][i], B = parent[B][i];
    if (A != B)
        A = parent[A][0];
    return A;
}

int get_dis(int A, int B) {
    int X = LCA(A, B);
    return depth[A] + depth[B] - 2 * depth[X];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, X, Y, R;

    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> X >> Y;
        adj[Y].push_back(i), arr[X].push_back(i);
        if (Y == 0)
            R = i;
    }

    dfs(R, 0);

    for (int i = 1; i <= K; i++) {
        X = Y = 0;
        for (int j : arr[i])
            if (depth[j] > depth[X])
                X = j;
        for (int j : arr[i])
            Y = max(Y, get_dis(X, j));
        cout << Y << '\n';
    }

    return 0;
}