#include <bits/stdc++.h>

using namespace std;

const int MAX = 100001;
const int MAX_LOG = 20;

int parent[MAX][MAX_LOG], depth[MAX], group[MAX], sz[MAX];
vector<int> adj[MAX];

int find(int X) { return X == group[X] ? X : group[X] = find(group[X]); }
void uni(int X, int Y) {
    X = find(X), Y = find(Y);
    if (X > Y)
        swap(X, Y);
    sz[X] += sz[Y], group[Y] = X;
}

void dfs(int node, int par) {
    depth[node] = depth[par] + 1;
    parent[node][0] = par;

    for (int i = 1; i < MAX_LOG; i++)
        parent[node][i] = parent[parent[node][i - 1]][i - 1];

    for (int i : adj[node]) {
        if (i == par)
            continue;
        dfs(i, node);
    }
}

int lca(int X, int Y) {
    if (depth[X] < depth[Y])
        swap(X, Y);

    int diff = depth[X] - depth[Y];
    for (int i = 0; diff; i++) {
        if (diff & 1)
            X = parent[X][i];
        diff >>= 1;
    }

    for (int i = MAX_LOG - 1; i >= 0; i--)
        if (parent[X][i] != parent[Y][i])
            X = parent[X][i], Y = parent[Y][i];
    if (X != Y)
        X = parent[X][0];
    return X;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, T, X, Y, R, A, B, C, last_ans = 0;

    cin >> N >> Q;
    for (int i = 1; i <= N; i++)
        group[i] = i, sz[i] = 1;

    while (Q--) {
        cin >> T >> X >> Y;
        X ^= last_ans, Y ^= last_ans;

        if (T == 1) {
            adj[X].push_back(Y), adj[Y].push_back(X);
            if (sz[find(X)] < sz[find(Y)])
                swap(X, Y);
            uni(X, Y), dfs(Y, X);
        } else {
            if (find(X) != find(Y))
                last_ans = 0;
            else {
                R = find(X);
                A = lca(R, X), B = lca(R, Y), C = lca(X, Y);

                if (depth[A] >= depth[B] && depth[A] >= depth[C])
                    last_ans = A;
                else if (depth[B] >= depth[A] && depth[B] >= depth[C])
                    last_ans = B;
                else
                    last_ans = C;
            }
            cout << last_ans << '\n';
        }
    }

    return 0;
}