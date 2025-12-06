#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;
typedef array<int, 3> tp;

const int MAX = 200001;
const int INF = 0x3f3f3f3f3f3f3f3f;

int uf[MAX], cnt,
    tree[MAX * 4],
    sz[MAX], depth[MAX], parent[MAX], in[MAX], top[MAX], L[MAX];
vector<pr> adj[MAX];

int find(int X) { return X == uf[X] ? X : uf[X] = find(uf[X]); }

void dfs1(int node, int par) {
    sz[node] = 1, parent[node] = par, depth[node] = depth[par] + 1;
    for (pr &i : adj[node]) {
        if (i[0] == par)
            continue;
        dfs1(i[0], node), sz[node] += sz[i[0]];
        if (adj[node][0][0] == par || sz[adj[node][0][0]] < sz[i[0]])
            swap(adj[node][0], i);
    }
}

void dfs2(int node, int par) {
    in[node] = ++cnt;
    for (pr &i : adj[node]) {
        if (i[0] == par)
            continue;
        top[i[0]] = (i == adj[node][0] ? top[node] : i[0]);
        dfs2(i[0], node), L[in[i[0]]] = i[1];
    }
}

void init(int n, int s, int e) {
    if (s == e)
        tree[n] = L[s];
    else {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
        tree[n] = max(tree[n << 1], tree[n << 1 | 1]);
    }
}

int query(int n, int s, int e, int l, int r) {
    if (r < s || e < l)
        return -INF;
    else if (l <= s && e <= r)
        return tree[n];
    else {
        int m = s + e >> 1;
        return max(query(n << 1, s, m, l, r), query(n << 1 | 1, m + 1, e, l, r));
    }
}

void solve() {
    int N, M, ans = INF, S = 0, U, V, W, val;
    bool flag = true;

    vector<tp> arr;
    vector<pr> lst;

    cin >> N >> M, cnt = 0;
    for (int i = 1; i <= N; i++)
        uf[i] = i, adj[i].clear();

    for (int i = 0; i < M; i++) {
        cin >> U >> V >> W;
        arr.push_back({W, U, V});
    }

    sort(arr.begin(), arr.end());
    for (int i = 0; i < N - 1; i++) {
        U = arr[i][1], V = arr[i][2], W = arr[i][0];
        S += W;

        if (find(U) != find(V)) {
            adj[U].push_back({V, W}), adj[V].push_back({U, W});
            uf[find(U)] = find(V);
        } else
            flag = false;
    }

    if (!flag) {
        cout << S << '\n';
        return;
    }

    dfs1(1, 0), top[1] = 1, dfs2(1, 0);
    init(1, 1, N);

    for (int i = N - 1; i < M; i++) {
        U = arr[i][1], V = arr[i][2], W = arr[i][0];
        val = -INF, lst.clear();

        while (top[U] ^ top[V]) {
            if (depth[top[U]] < depth[top[V]])
                swap(U, V);
            lst.push_back({in[top[U]], in[U]}), U = parent[top[U]];
        }
        if (depth[U] > depth[V])
            swap(U, V);
        if (in[U] + 1 <= in[V])
            lst.push_back({in[U] + 1, in[V]});

        lst.push_back({0, 0}), lst.push_back({N + 1, N + 1});
        sort(lst.begin(), lst.end());

        for (int j = 1; j < (int)lst.size(); j++)
            val = max(val, query(1, 1, N, lst[j - 1][1] + 1, lst[j][0] - 1));

        ans = min(ans, S + W - val);
    }

    if (M > N && N > 2)
        ans = min(ans, S - arr[N - 3][0] - arr[N - 2][0] + arr[N - 1][0] + arr[N][0]);

    cout << (ans == INF ? -1 : ans) << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T, L[1] = -INF;

    while (T--)
        solve();

    return 0;
}