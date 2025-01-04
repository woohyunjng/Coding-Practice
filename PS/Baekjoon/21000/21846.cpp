#include <bits/stdc++.h>
#define int long long

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define MAX 250100

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

vector<pr> adj[MAX], arr;
vector<int> node_q[MAX];
unordered_map<int, int> mp[MAX][2], parent_ln[MAX];
int Q, sz[MAX], parent[MAX], ans[MAX], tree[MAX];
bool vst[MAX], chk[MAX];

int query(int n) {
    int res = 0;
    n++;
    while (n) {
        res += tree[n];
        n -= n & -n;
    }
    return res;
}

int query(int l, int r) { return query(r) - query(l - 1); }

void update(int n, int val) {
    n++;
    while (n <= Q) {
        tree[n] += val;
        n += n & -n;
    }
}

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

void dfs(int node, int par, int cent, int time, int first, int type) {
    if (type == 0)
        arr.push_back({time, first});
    if (type == 1) {
        for (int i : node_q[node])
            arr.push_back({i, -node});
    }
    mp[cent][type][node] = first;

    for (pr i : adj[node]) {
        if (i.first == par || vst[i.first])
            continue;
        if ((i.second > time) ^ type) // type -> 0 이면 cent에서 내려감 1이면 올라감
            dfs(i.first, node, cent, i.second, first, type);
    }
}

void upd_dfs(int node, int par, int cent, int time) {
    parent_ln[node][cent] = time;
    for (pr i : adj[node]) {
        if (i.first == par || vst[i.first])
            continue;
        upd_dfs(i.first, node, cent, i.second);
    }
}

void build_tree(int node, int par) {
    int cent = get_centroid(node, -1, get_size(node, -1));
    vst[cent] = true, parent[cent] = par;

    mp[cent][0][cent] = Q, mp[cent][1][cent] = -1, parent_ln[cent][cent] = -1;
    arr.push_back({-1, Q - 1});
    for (int i : node_q[cent])
        arr.push_back({i, -cent});

    for (pr i : adj[cent]) {
        if (vst[i.first])
            continue;
        dfs(i.first, cent, cent, i.second, i.second, 0);
        dfs(i.first, cent, cent, i.second, i.second, 1);
        upd_dfs(i.first, cent, cent, i.second);
    }

    sort(arr.begin(), arr.end());
    for (pr i : arr) {
        if (i.second >= 0)
            update(i.second, 1);
        else {
            if (mp[cent][1][-i.second] <= i.first)
                ans[i.first] += query(-i.second == cent ? 0 : (mp[cent][1][-i.second] + 1), Q - 1);
        }
    }
    for (pr i : arr)
        if (i.second >= 0)
            update(i.second, -1);
    arr.clear();

    for (pr i : adj[cent]) {
        if (vst[i.first])
            continue;
        build_tree(i.first, cent);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, A, B, X, res;
    vector<pr> queries;
    char C;

    cin >> N >> K;

    for (int i = 0; i < N + K - 1; i++) {
        cin >> C;
        if (C == 'S') {
            cin >> A >> B;
            adj[A].push_back({B, i}), adj[B].push_back({A, i});
            queries.push_back({-1, -1});
        } else if (C == 'Q') {
            cin >> A >> B;
            queries.push_back({A, B});
        } else {
            cin >> A;
            queries.push_back({A, 0}), node_q[A].push_back(i);
        }
    }
    Q = N + K;

    build_tree(1, -1);

    for (int i = 0; i < N + K - 1; i++) {
        A = queries[i].first, B = queries[i].second;
        if (B == -1)
            continue;
        if (B != 0) {
            X = A, res = 0;
            while (X != -1) {
                if (mp[X][1].find(B) != mp[X][1].end() && mp[X][0].find(A) != mp[X][0].end()) {
                    if (A != X)
                        res |= mp[X][1][B] < mp[X][0][A] && parent_ln[A][X] <= i;
                    else
                        res |= mp[X][1][B] <= i;
                }
                X = parent[X];
            }
            cout << (res ? "yes" : "no") << '\n';
        } else
            cout << ans[i] << '\n';
    }

    return 0;
}