#include <bits/stdc++.h>
using namespace std;

typedef array<int, 2> pr;

const int MAX = 100001;
const int MAX_LOG = 20;
const int INF = 2e9;

vector<int> adj[MAX], val[MAX];
int ans[MAX], parent[MAX][MAX_LOG], depth[MAX],
    sz[MAX], MR[MAX], cpar[MAX], cdepth[MAX], len[MAX][MAX_LOG];
bool vst[MAX];

void lca_dfs(int node, int par) {
    parent[node][0] = par, depth[node] = depth[par] + 1;
    for (int i = 1; i < MAX_LOG; i++)
        parent[node][i] = parent[parent[node][i - 1]][i - 1];

    for (int i : adj[node]) {
        if (i == par)
            continue;
        lca_dfs(i, node);
    }
}

int lca(int U, int V) {
    if (depth[U] < depth[V])
        swap(U, V);

    int diff = depth[U] - depth[V];
    for (int i = 0; i < MAX_LOG; i++)
        if (diff & (1 << i))
            U = parent[U][i];

    for (int i = MAX_LOG - 1; i >= 0; i--)
        if (parent[U][i] != parent[V][i])
            U = parent[U][i], V = parent[V][i];

    if (U != V)
        U = parent[U][0];
    return U;
}

int dis(int U, int V) { return depth[U] + depth[V] - 2 * depth[lca(U, V)]; }

int move(int U, int V, int D) {
    int L = lca(U, V);
    if (depth[U] - depth[L] < D)
        D = dis(U, V) - D, U = V;
    for (int i = 0; i < MAX_LOG; i++)
        if (D & (1 << i))
            U = parent[U][i];
    return U;
}

int get_sz(int node, int par) {
    sz[node] = 1;
    for (int i : adj[node]) {
        if (i == par || vst[i])
            continue;
        sz[node] += get_sz(i, node);
    }
    return sz[node];
}

int get_cent(int node, int par, int cap) {
    for (int i : adj[node]) {
        if (i == par || vst[i])
            continue;
        if (sz[i] * 2 > cap)
            return get_cent(i, node, cap);
    }
    return node;
}

void dfs(int node, int par, int cent) {
    MR[cent] = max(MR[cent], len[node][cdepth[cent]]);
    for (int i : adj[node]) {
        if (i == par || vst[i])
            continue;
        len[i][cdepth[cent]] = len[node][cdepth[cent]] + 1, dfs(i, node, cent);
    }
}

void cent_dfs(int node, int par) {
    int cent = get_cent(node, 0, get_sz(node, 0));
    vst[cent] = true, cpar[cent] = par;
    cdepth[cent] = cdepth[par] + 1, dfs(cent, 0, cent);
    val[cent].resize(MR[cent] + 1, INF);

    for (int i : adj[cent]) {
        if (vst[i])
            continue;
        cent_dfs(i, cent);
    }
}

void spread(int node, int R, int V) {
    int C = node, D;
    while (C != 0) {
        D = min(MR[C], R - len[node][cdepth[C]]);
        if (D >= 0)
            val[C][D] = min(val[C][D], V);
        C = cpar[C];
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, K, T, U, V, RU, RV, D;

    cin >> N >> M >> K, fill(ans, ans + N + 1, INF);
    for (int i = 1; i < N; i++) {
        cin >> U >> V;
        adj[U].push_back(V), adj[V].push_back(U);
    }

    lca_dfs(1, 0), cent_dfs(1, 0);

    while (M--) {
        cin >> T >> U >> V >> RU >> RV;
        if (RU < RV)
            swap(U, V), swap(RU, RV);
        if (dis(U, V) > RU + RV)
            continue;
        if (dis(U, V) <= RU - RV)
            spread(V, RV, T);
        else {
            D = RU + RV - dis(U, V);
            spread(move(U, V, dis(U, V) - RV + D / 2), D / 2, T), spread(move(U, V, dis(U, V) - RV + (D + 1) / 2), D / 2, T);
        }
    }

    for (int i = 1; i <= N; i++)
        for (int j = MR[i] - 1; j >= 0; j--)
            val[i][j] = min(val[i][j], val[i][j + 1]);

    priority_queue<pr, vector<pr>, greater<pr>> pq;
    pr P;

    for (int i = 1; i <= N; i++) {
        V = i;
        while (V != 0)
            ans[i] = min(ans[i], val[V][len[i][cdepth[V]]]), V = cpar[V];
        if (ans[i] != INF)
            pq.push({ans[i], i});
    }

    while (!pq.empty()) {
        P = pq.top(), pq.pop();
        if (ans[P[1]] < P[0])
            continue;

        for (int i : adj[P[1]])
            if (ans[i] > ans[P[1]] + K)
                pq.push({ans[i] = ans[P[1]] + K, i});
    }

    for (int i = 1; i <= N; i++)
        cout << (ans[i] == INF ? -1 : ans[i]) << '\n';

    return 0;
}