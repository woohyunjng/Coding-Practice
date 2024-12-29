#include <bits/stdc++.h>
#define int long long

#define MAX 100010

using namespace std;
typedef pair<int, int> pr;

pr go[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
vector<int> adj[MAX];
int depth[MAX], sm[MAX], parent[MAX][20];

void dfs(int node, int par) {
    depth[node] = depth[par] + 1;
    parent[node][0] = par;

    for (int i = 1; i < 20; i++)
        parent[node][i] = parent[parent[node][i - 1]][i - 1];

    for (int i : adj[node])
        if (i != par)
            dfs(i, node);
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

int dis(int A, int B) {
    int X = lca(A, B);
    return depth[A] + depth[B] - 2 * depth[X];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, T, K, X, S, E, a, b, c, d, V;
    cin >> N >> M >> T;

    vector<vector<int>> A(N - 1, vector<int>(M, 0)), B(N, vector<int>(M - 1, 0));
    for (int i = 0; i < N - 1; i++)
        for (int j = 0; j < M; j++)
            cin >> A[i][j];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M - 1; j++)
            cin >> B[i][j];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            X = i * M + j + 1;
            if (j > 0 && !B[i][j - 1])
                adj[X].push_back(X - 1);
            if (j < M - 1 && !B[i][j])
                adj[X].push_back(X + 1);
            if (i > 0 && !A[i - 1][j])
                adj[X].push_back(X - M);
            if (i < N - 1 && !A[i][j])
                adj[X].push_back(X + M);
        }

    dfs(1, 0);

    cin >> K;
    while (K--) {
        cin >> S >> E >> a >> b >> c >> d >> V;
        X = (dis(a * M + b + 1, c * M + d + 1) + 1) * V;
        sm[S] += X, sm[E + 1] -= X;
    }

    for (int i = 1; i <= T; i++) {
        sm[i] += sm[i - 1];
        cout << sm[i] << '\n';
    }

    return 0;
}