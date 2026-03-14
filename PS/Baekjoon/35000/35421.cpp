#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;
typedef array<int, 3> tp;

const int MAX = 100001;
const int MAX_LOG = 20;
const int MAX_N = 103;
const int INF = 0x3f3f3f3f3f3f3f3f;

vector<pr> adj[MAX], gadj[MAX];
int uf[MAX], depth[MAX], len[MAX],
    parent[MAX_LOG][MAX], D[MAX_N][MAX];

int find(int X) { return X == uf[X] ? X : uf[X] = find(uf[X]); }

void dfs(int node, int par) {
    depth[node] = depth[par] + 1, parent[0][node] = par;
    for (int i = 1; i < MAX_LOG; i++)
        parent[i][node] = parent[i - 1][parent[i - 1][node]];

    for (pr i : adj[node]) {
        if (i[0] == par)
            continue;
        len[i[0]] = len[node] + i[1], dfs(i[0], node);
    }
}

int lca(int X, int Y) {
    if (depth[X] < depth[Y])
        swap(X, Y);

    int diff = depth[X] - depth[Y];
    for (int i = 0; i < MAX_LOG; i++)
        if (diff & (1 << i))
            X = parent[i][X];

    for (int i = MAX_LOG - 1; i >= 0; i--)
        if (parent[i][X] ^ parent[i][Y])
            X = parent[i][X], Y = parent[i][Y];
    if (X ^ Y)
        X = parent[0][X];
    return X;
}

int dis(int X, int Y) { return len[X] + len[Y] - len[lca(X, Y)] * 2; }

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, Q, U, V, W, S, ans;
    vector<tp> arr;
    vector<int> comp;

    priority_queue<pr, vector<pr>, greater<pr>> pq;
    pr K;

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        uf[i] = i;

    while (M--) {
        cin >> U >> V >> W;
        gadj[U].push_back({V, W}), gadj[V].push_back({U, W});
        if (find(U) == find(V))
            comp.push_back(U), comp.push_back(V);
        else {
            adj[U].push_back({V, W}), adj[V].push_back({U, W});
            uf[find(U)] = find(V);
        }
    }

    dfs(1, 0);

    sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end()), S = comp.size();
    for (int i = 0; i < S; i++) {
        fill(D[i], D[i] + N + 1, INF);
        U = comp[i], D[i][U] = 0, pq.push({0, U});
        while (!pq.empty()) {
            K = pq.top(), pq.pop();
            if (D[i][K[1]] ^ K[0])
                continue;

            for (pr j : gadj[K[1]]) {
                if (K[0] + j[1] < D[i][j[0]])
                    D[i][j[0]] = K[0] + j[1], pq.push({D[i][j[0]], j[0]});
            }
        }
    }

    cin >> Q;
    while (Q--) {
        cin >> U >> V, ans = dis(U, V);
        for (int i = 0; i < S; i++)
            ans = min(ans, D[i][U] + D[i][V]);
        cout << ans << '\n';
    }

    return 0;
}