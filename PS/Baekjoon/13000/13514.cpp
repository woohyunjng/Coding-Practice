#include <bits/stdc++.h>
#define int long long

#define MAX 100100
using namespace std;
typedef pair<int, int> pr;

vector<int> adj[MAX];
priority_queue<pr, vector<pr>, greater<pr>> pq[MAX];

int parent[MAX], sz[MAX], C[MAX], lca_parent[20][MAX], depth[MAX];
bool vst[MAX];

int get_size(int node, int par) {
    int res = 1;
    for (int i : adj[node]) {
        if (i == par || vst[i])
            continue;
        res += get_size(i, node);
    }
    return sz[node] = res;
}

int get_centroid(int node, int par, int cap) {
    for (int i : adj[node]) {
        if (i == par || vst[i])
            continue;
        if (sz[i] * 2 > cap)
            return get_centroid(i, node, cap);
    }
    return node;
}

void dfs(int node, int par) {
    int cent = get_centroid(node, -1, get_size(node, -1));
    parent[cent] = par, vst[cent] = true;

    for (int i : adj[cent]) {
        if (vst[i])
            continue;
        dfs(i, cent);
    }
}

void lca_dfs(int node, int par) {
    lca_parent[0][node] = par, depth[node] = depth[par] + 1;
    for (int i = 1; i < 20; i++)
        lca_parent[i][node] = lca_parent[i - 1][lca_parent[i - 1][node]];

    for (int i : adj[node]) {
        if (i == par)
            continue;
        lca_dfs(i, node);
    }
}

int lca(int A, int B) {
    if (depth[A] < depth[B])
        swap(A, B);

    int diff = depth[A] - depth[B];
    for (int i = 0; diff; i++) {
        if (diff & 1)
            A = lca_parent[i][A];
        diff >>= 1;
    }

    for (int i = 19; i >= 0; i--)
        if (lca_parent[i][A] != lca_parent[i][B])
            A = lca_parent[i][A], B = lca_parent[i][B];

    if (A != B)
        A = lca_parent[0][A];
    return A;
}

int get_dis(int A, int B) {
    int X = lca(A, B);
    return depth[A] + depth[B] - 2 * depth[X];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X, Y, res, K;
    cin >> N;

    for (int i = 1; i < N; i++) {
        cin >> X >> Y;
        adj[X].push_back(Y), adj[Y].push_back(X);
    }

    dfs(1, 0), lca_dfs(1, 0);

    cin >> M;
    while (M--) {
        cin >> X >> Y;
        if (X == 1) {
            C[Y] ^= 1;
            if (C[Y] == 0)
                continue;
            K = Y;
            while (K) {
                pq[K].push({get_dis(Y, K), Y});
                K = parent[K];
            }
        } else if (X == 2) {
            K = Y, res = N;
            while (K) {
                while (!pq[K].empty() && !C[pq[K].top().second])
                    pq[K].pop();
                if (!pq[K].empty())
                    res = min(res, get_dis(Y, K) + pq[K].top().first);
                K = parent[K];
            }

            if (res == N)
                res = -1;
            cout << res << '\n';
        }
    }

    return 0;
}