#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef array<int, 2> pr;

const int MAX = 200001;
const int MOD = 998'244'353;

int fpow(int N, int K) {
    int res = 1;
    while (K) {
        if (K & 1)
            res = res * N % MOD;
        K >>= 1, N = N * N % MOD;
    }
    return res;
}

vector<pr> adj[MAX];
map<int, int> dis[MAX];

ordered_set V[MAX];
map<int, ordered_set> SV[MAX];

int sz[MAX], depth[MAX], parent[MAX];
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

void dfs(int node, int par) {
    for (pr i : adj[node]) {
        if (i[0] == par)
            continue;
        depth[i[0]] = depth[node] + i[1], dfs(i[0], node);
    }
}

void dis_dfs(int node, int par, int len, int c) {
    dis[node][c] = len;
    for (pr i : adj[node]) {
        if (i[0] == par || vst[i[0]])
            continue;
        dis_dfs(i[0], node, len + i[1], c);
    }
}

void dnc(int node, int par) {
    int cent = get_cent(node, 0, get_sz(node, 0));
    vst[cent] = true, parent[cent] = par;

    V[cent] = ordered_set();
    if (par != 0)
        SV[par][cent] = ordered_set();

    dis_dfs(cent, 0, 0, cent);

    for (pr i : adj[cent]) {
        if (vst[i[0]])
            continue;
        dnc(i[0], cent);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, L, A, B, C, D, BASE, ans = 0;
    vector<int> arr;

    cin >> N >> K >> L, L <<= 1;
    BASE = fpow(fpow(N, K), MOD - 2);

    for (int i = 1; i < N; i++)
        cin >> A >> B >> C, adj[A].push_back({B, C}), adj[B].push_back({A, C});

    dfs(1, 0), dnc(1, 0);
    for (int i = 1; i <= N; i++)
        arr.push_back(i);

    sort(arr.begin(), arr.end(), [](int x, int y) { return depth[x] < depth[y]; });
    for (int i : arr) {
        A = 0, B = i, C = 0;
        while (B) {
            D = dis[i][B], V[B].insert(D);
            if (C != 0)
                SV[B][C].insert(D);

            A += V[B].order_of_key(L - D + 1);
            A -= C == 0 ? 0 : SV[B][C].order_of_key(L - D + 1);

            C = B, B = parent[B];
        }
        ans += (fpow(A, K) - fpow(A - 1, K) + MOD) % MOD, ans %= MOD;
    }

    ans *= BASE, ans %= MOD;
    cout << ans << '\n';

    return 0;
}