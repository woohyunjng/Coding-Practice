#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

const int MAX = 200001;
const int MAX_LOG = 20;

vector<pr> adj[MAX];
int sz[MAX], parent[MAX], depth[MAX], S[MAX], C[MAX_LOG][MAX];
bool vst[MAX];

int get_sz(int node, int par) {
    sz[node] = 1;
    for (pr i : adj[node]) {
        if (i[0] == par || vst[i[0]])
            continue;
        sz[node] += get_sz(i[0], node);
    }
    return sz[node];
}

int get_cent(int node, int par, int cap) {
    for (pr i : adj[node]) {
        if (i[0] == par || vst[i[0]])
            continue;
        if (sz[i[0]] * 2 > cap)
            return get_cent(i[0], node, cap);
    }
    return node;
}

void dfs(int node, int par, int dep, int len, int sm) {
    C[dep][node] = len == sm ? 1 : (sm == 0 ? 0 : -1);
    for (pr i : adj[node]) {
        if (i[0] == par || vst[i[0]])
            continue;
        dfs(i[0], node, dep, len + 1, sm + i[1]);
    }
}

void dnc(int node, int par) {
    int cent = get_cent(node, -1, get_sz(node, -1));
    vst[cent] = true, parent[cent] = par, depth[cent] = depth[par] + 1;

    for (pr i : adj[cent]) {
        if (vst[i[0]])
            continue;
        dfs(i[0], cent, depth[cent], 1, i[1]);
    }

    for (pr i : adj[cent]) {
        if (vst[i[0]])
            continue;
        dnc(i[0], cent);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, U, V, M, Q, T, K, ans;

    cin >> N;
    for (int i = 1; i < N; i++) {
        cin >> U >> V;
        adj[U].push_back({V, 1}), adj[V].push_back({U, 0});
    }

    dnc(1, 0);

    cin >> M >> Q, Q += M;
    while (Q--) {
        cin >> T;
        if (T == 1) {
            cin >> U >> V, K = U, S[U] += V;
            while (parent[K] != 0) {
                K = parent[K];
                if (C[depth[K]][U] == 1)
                    S[K] += V;
            }
        } else {
            cin >> U, K = U, ans = S[U];
            while (parent[K] != 0) {
                K = parent[K];
                if (C[depth[K]][U] == 0)
                    ans += S[K];
            }
            cout << ans << '\n';
        }
    }

    return 0;
}