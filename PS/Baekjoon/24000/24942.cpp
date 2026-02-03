#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")

using namespace std;

const int MAX = 120001;
const int MAX_C = 10000001;
const int MAX_LOG = 20;

vector<int> tree_adj[MAX], adj[MAX_C];
int A[MAX], B[MAX], VA[MAX], VB[MAX],
    parent[MAX][MAX_LOG], depth[MAX], D[MAX],
    sz[MAX], cent_par[MAX], cent_in[MAX][MAX_LOG], cent_out[MAX][MAX_LOG],
    deg[MAX_C], C = 0;
bool ans, vst[MAX];

void lca_dfs(int node, int par) {
    depth[node] = depth[par] + 1, parent[node][0] = par;
    for (int i = 1; i < MAX_LOG; i++)
        parent[node][i] = parent[parent[node][i - 1]][i - 1];

    for (int i : tree_adj[node]) {
        if (i == par)
            continue;
        lca_dfs(i, node);
    }
}

int climb(int X, int Y) {
    for (int i = 0; i < MAX_LOG; i++)
        if (Y & (1 << i))
            X = parent[X][i];
    return X;
}

int lca(int X, int Y) {
    if (depth[X] < depth[Y])
        swap(X, Y);
    X = climb(X, depth[X] - depth[Y]);
    for (int i = MAX_LOG - 1; i >= 0; i--)
        if (parent[X][i] ^ parent[Y][i])
            X = parent[X][i], Y = parent[Y][i];
    if (X ^ Y)
        X = parent[X][0];
    return X;
}

int get_sz(int node, int par) {
    sz[node] = 1;
    for (int i : tree_adj[node]) {
        if (vst[i] || i == par)
            continue;
        sz[node] += get_sz(i, node);
    }
    return sz[node];
}

int get_cent(int node, int par, int cap) {
    for (int i : tree_adj[node]) {
        if (vst[i] || i == par)
            continue;
        if (sz[i] * 2 >= cap)
            return get_cent(i, node, cap);
    }
    return node;
}

void dfs(int node, int par, int par_in, int par_out, int dp) {
    int in = ++C, out = ++C;
    cent_in[node][dp] = in, cent_out[node][dp] = out;
    if (par_in != 0)
        adj[in].push_back(par_in), adj[par_out].push_back(out);

    if (VA[node] != 0)
        adj[in].push_back(VA[node]);
    if (VB[node] != 0)
        adj[VB[node]].push_back(out);

    for (int i : tree_adj[node]) {
        if (vst[i] || i == par)
            continue;
        dfs(i, node, in, out, dp);
    }
}

void dnc(int node, int par) {
    int cent = get_cent(node, 0, get_sz(node, 0));
    cent_par[cent] = par, D[cent] = D[par] + 1, vst[cent] = true;

    for (int i : tree_adj[cent]) {
        if (vst[i])
            continue;
        dfs(i, cent, 0, 0, D[cent]);
    }

    for (int i : tree_adj[cent])
        if (!vst[i])
            dnc(i, cent);
}

int path_cent(int U, int V) {
    while (U ^ V) {
        if (D[U] < D[V])
            swap(U, V);
        U = cent_par[U];
        if (D[U] == 0)
            return 0;
    }
    return U;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, M, U, V, L;
    queue<int> q;
    bool chk_A, chk_B;

    cin >> T;
    while (T--) {
        cin >> N, ans = true;
        for (int i = 1; i < N; i++) {
            cin >> U >> V;
            tree_adj[U].push_back(V), tree_adj[V].push_back(U);
        }

        cin >> M, C = M;
        for (int i = 1; i <= M; i++) {
            cin >> A[i] >> B[i];
            VA[A[i]] = i, VB[B[i]] = i;
        }
        lca_dfs(1, 0), dnc(1, 0);

        for (int i = 1; i <= M; i++) {
            U = A[i], V = B[i], L = lca(U, V);
            U = U == L ? climb(V, depth[V] - depth[U] - 1) : parent[U][0];
            L = path_cent(U, V);
            if (L != U)
                adj[i].push_back(cent_in[U][D[L]]);
            if (L != V)
                adj[i].push_back(cent_in[V][D[L]]);
            if (VA[L] != 0)
                adj[i].push_back(VA[L]);

            U = A[i], V = B[i], L = lca(U, V);
            V = V == L ? climb(U, depth[U] - depth[V] - 1) : parent[V][0];
            L = path_cent(U, V);
            if (L != U)
                adj[cent_out[U][D[L]]].push_back(i);
            if (L != V)
                adj[cent_out[V][D[L]]].push_back(i);
            if (VB[L] != 0)
                adj[VB[L]].push_back(i);
        }

        for (int i = 1; i <= C; i++)
            for (int j : adj[i])
                deg[j]++;

        V = 0;
        for (int i = 1; i <= C; i++)
            if (!deg[i])
                q.push(i);
        while (!q.empty()) {
            U = q.front(), q.pop(), V++;
            for (int i : adj[U])
                if (!--deg[i])
                    q.push(i);
        }

        ans &= V == C;
        cout << (ans ? "Yes" : "No") << '\n';

        for (int i = 1; i <= N; i++) {
            VA[i] = VB[i] = D[i] = cent_par[i] = 0, vst[i] = false;
            tree_adj[i].clear(), fill(parent[i], parent[i] + MAX_LOG, 0);
            for (int j = 0; j < MAX_LOG; j++)
                cent_in[i][j] = cent_out[i][j] = 0;
        }
        for (int i = 1; i <= C; i++)
            adj[i].clear(), deg[i] = 0;
    }

    return 0;
}