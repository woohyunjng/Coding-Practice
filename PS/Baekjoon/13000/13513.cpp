#include <bits/stdc++.h>
#define int long long

#define MAX 100100

using namespace std;
typedef pair<int, int> pr;

vector<pr> adj[MAX];
multiset<int> ans_sub, sub[MAX];
map<int, multiset<int>> cent[MAX];
map<int, int> dist[MAX];

int sz[MAX], parent[MAX], C[MAX], ans[MAX];
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

void get_dis(int node, int par, int cent, int dis) {
    dist[node][cent] = dis;
    for (pr i : adj[node]) {
        if (i.first == par || vst[i.first])
            continue;
        get_dis(i.first, node, cent, dis + i.second);
    }
}

void dfs(int node, int par) {
    int cent = get_centroid(node, -1, get_size(node, -1));
    vst[cent] = true, parent[cent] = par, get_dis(cent, -1, cent, 0);

    for (pr i : adj[cent]) {
        if (vst[i.first])
            continue;
        dfs(i.first, cent);
    }
}

void upd_ans(int node) {
    int K;

    if (ans[node] != -1)
        ans_sub.erase(ans_sub.find(ans[node])), ans[node] = -1;
    if (sub[node].size() > 1) {
        K = *prev(sub[node].end()) + *prev(prev(sub[node].end()));
        ans[node] = K, ans_sub.insert(K);
    }
}

int update(int node) {
    int U = node, V = node, K, X;
    C[node] ^= 1;

    while (U) {
        K = dist[node][U];
        if (C[node] == 1) {
            if (!cent[U][V].empty() && *prev(cent[U][V].end()) < K)
                sub[U].erase(sub[U].find(*prev(cent[U][V].end()))), sub[U].insert(K);
            else if (cent[U][V].empty())
                sub[U].insert(K);
            cent[U][V].insert(K);
        } else {
            X = *prev(cent[U][V].end());
            cent[U][V].erase(cent[U][V].find(K));

            if (!cent[U][V].empty() && *prev(cent[U][V].end()) < X)
                sub[U].erase(sub[U].find(X)), sub[U].insert(*prev(cent[U][V].end()));
            else if (cent[U][V].empty())
                sub[U].erase(sub[U].find(X));
        }

        upd_ans(U);
        V = U, U = parent[U];
    }

    return C[node] == 1 ? 1 : -1;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, U, V, W, X, res, cnt = 0;

    cin >> N;
    for (int i = 1; i < N; i++) {
        cin >> U >> V >> W;
        adj[U].push_back({V, W}), adj[V].push_back({U, W});
    }

    dfs(1, 0), fill(ans, ans + N + 1, -1);
    for (int i = 1; i <= N; i++)
        cent[i][i] = multiset<int>(), cent[parent[i]][i] = multiset<int>();
    for (int i = 1; i <= N; i++)
        cnt += update(i);

    cin >> M;

    while (M--) {
        cin >> X;
        if (X == 1)
            cin >> U, cnt += update(U);
        else {
            if (!cnt)
                res = -1;
            else if (cnt == 1 || ans_sub.empty())
                res = 0;
            else
                res = *prev(ans_sub.end());
            cout << res << '\n';
        }
    }

    return 0;
}