#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

const int MAX = 100001;

vector<int> adj[MAX], arr[MAX], st[MAX], S[MAX];
map<int, int> dis[MAX];
map<int, vector<int>> A[MAX];

int depth[MAX], dp[MAX],
    C[MAX], D[MAX], G[MAX],
    sz[MAX], parent[MAX], M;
bool vst[MAX];

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

void dis_dfs(int node, int par, int c, int d) {
    dis[node][c] = d, M = max(M, d);
    for (int i : adj[node]) {
        if (i == par || vst[i])
            continue;
        dis_dfs(i, node, c, d + 1);
    }
}

void dnc(int node, int par) {
    int cent = get_cent(node, -1, get_sz(node, -1));
    vst[cent] = true, parent[cent] = par, M = 0;

    if (par != 0)
        A[par][cent] = vector<int>(sz[node] + 1, 0);

    for (int i : adj[cent]) {
        if (vst[i])
            continue;
        dis_dfs(i, cent, cent, 1);
    }

    for (int i = 0; i <= M; i++)
        S[cent].push_back(0);

    for (int i : adj[cent]) {
        if (vst[i])
            continue;
        dnc(i, cent);
    }
}

void dfs(int node, int par) {
    int X, K, V, L, SM = 0, B;

    depth[node] = depth[par] + 1;
    for (int i : arr[node])
        st[max(1ll, depth[node] - D[i])].push_back(i);

    for (int i : adj[node]) {
        if (i == par)
            continue;
        dfs(i, node), SM += dp[i];
    }
    dp[node] = SM;

    while (!st[depth[node]].empty()) {
        X = st[depth[node]].back(), st[depth[node]].pop_back();

        if (D[X] == 0) {
            dp[node] = max(SM + G[X], dp[node]);
            continue;
        }

        K = C[X], B = 0, L = G[X];
        while (K) {
            V = dis[C[X]][K];
            if (D[X] - V + 1 < (int)S[K].size() && D[X] - V + 1 >= 0)
                L += S[K][D[X] - V + 1] - (B != 0 && D[X] - V + 1 < (int)A[K][B].size() ? A[K][B][D[X] - V + 1] : 0);
            B = K, K = parent[K];
        }
        dp[node] = max(dp[node], L);
    }

    K = node, B = 0;
    while (K) {
        if (B != 0)
            A[K][B][dis[node][K]] += dp[node];
        S[K][dis[node][K]] += dp[node], B = K, K = parent[K];
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X, Y, R = 1;

    cin >> N >> M;
    for (int i = 1; i < N; i++) {
        cin >> X >> Y;
        adj[X].push_back(Y), adj[Y].push_back(X);
    }

    for (int i = 1; i <= M; i++) {
        cin >> C[i] >> D[i] >> G[i];
        arr[C[i]].push_back(i);
    }

    for (int i = 1; i <= N; i++)
        if (adj[i].size() == 1)
            R = i;

    dnc(R, 0), dfs(R, 0);
    cout << dp[R] << '\n';

    return 0;
}