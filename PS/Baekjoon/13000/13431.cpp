#include <bits/stdc++.h>
#define int long long

#define MAX 100100
using namespace std;
typedef pair<int, int> pr;

vector<pr> adj[MAX];
map<int, int> sum[MAX], cnt[MAX];

int sz[MAX], parent[MAX], lca_parent[20][MAX], full_sum[MAX], full_cnt[MAX], depth[MAX], length[MAX], C[MAX];
bool vst[MAX];

int get_size(int node, int par) {
    int res = 1;
    for (pr i : adj[node]) {
        if (i.first == par || vst[i.first])
            continue;
        res += get_size(i.first, node);
    }
    return sz[node] = res;
}

int get_centroid(int node, int par, int cap) {
    for (pr i : adj[node]) {
        if (i.first == par || vst[i.first])
            continue;
        if (sz[i.first] * 2 > cap)
            return get_centroid(i.first, node, cap);
    }
    return node;
}

void dfs(int node, int par) {
    int cent = get_centroid(node, -1, get_size(node, -1));
    parent[cent] = par, vst[cent] = true;

    for (pr i : adj[cent]) {
        if (vst[i.first])
            continue;
        dfs(i.first, cent);
    }
}

void lca_dfs(int node, int par) {
    lca_parent[0][node] = par;
    depth[node] = depth[par] + 1;

    for (int i = 1; i < 20; i++)
        lca_parent[i][node] = lca_parent[i - 1][lca_parent[i - 1][node]];

    for (pr i : adj[node]) {
        if (i.first == par)
            continue;
        length[i.first] = length[node] + i.second;
        lca_dfs(i.first, node);
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

int dis(int A, int B) { return length[A] + length[B] - 2 * length[lca(A, B)]; }

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, X, Y, K, res;
    cin >> N >> Q;

    for (int i = 2; i <= N; i++) {
        cin >> X >> Y >> K, X++, Y++;
        adj[X].push_back({Y, K}), adj[Y].push_back({X, K});
    }

    dfs(1, 0);
    lca_dfs(1, 0);

    while (Q--) {
        cin >> X >> Y, Y++;
        if (X == 1) {
            if (C[Y])
                continue;
            C[Y] = 1;
            K = Y;
            while (K) {
                full_sum[K] += dis(K, Y), full_cnt[K]++;
                if (parent[K])
                    sum[parent[K]][K] += dis(parent[K], Y), cnt[parent[K]][K]++;
                K = parent[K];
            }
        } else {
            K = Y;
            res = full_sum[K];

            while (K) {
                res += full_sum[parent[K]] - sum[parent[K]][K] + (full_cnt[parent[K]] - cnt[parent[K]][K]) * dis(parent[K], Y);
                K = parent[K];
            }

            cout << res << '\n';
        }
    }

    return 0;
}