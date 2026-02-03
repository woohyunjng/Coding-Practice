#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

typedef array<int, 2> pr;

const int MAX = 600001;
const int MAX_LOG = 20;

vector<int> adj[MAX], arr[MAX],
    dw[MAX];
set<int> st[MAX];
set<pr> fk[MAX];

int N, K, C[MAX], D[MAX], R[MAX], ans,
    parent[MAX][MAX_LOG], depth[MAX], in[MAX], cnt,
    uf[MAX], B[MAX];

int find(int X) { return X == uf[X] ? X : uf[X] = find(uf[X]); }
void uni(int X, int Y) {
    X = find(X), Y = find(Y);
    if (X == Y)
        return;
    else if (depth[X] > depth[Y])
        swap(X, Y);

    uf[Y] = X, B[X] = min(B[X], B[Y]);
    if (st[Y].size() > st[X].size())
        swap(st[X], st[Y]);
    while (!st[Y].empty())
        st[X].insert(*st[Y].begin()), st[Y].erase(st[Y].begin());
    if (dw[Y].size() > dw[X].size())
        swap(dw[X], dw[Y]);
    while (!dw[Y].empty())
        dw[X].push_back(dw[Y].back()), dw[Y].pop_back();
    if (fk[Y].size() > fk[X].size())
        swap(fk[X], fk[Y]);
    while (!fk[Y].empty())
        fk[X].insert(*fk[Y].begin()), fk[Y].erase(fk[Y].begin());
}

void lca_dfs(int node, int par) {
    parent[node][0] = par, depth[node] = depth[par] + 1, in[node] = ++cnt;
    for (int i = 1; i < MAX_LOG; i++)
        parent[node][i] = parent[parent[node][i - 1]][i - 1];

    for (int i : adj[node]) {
        if (i == par)
            continue;
        lca_dfs(i, node);
    }
}

int lca(int X, int Y) {
    if (depth[X] < depth[Y])
        swap(X, Y);
    int diff = depth[X] - depth[Y];
    for (int i = 0; i < MAX_LOG; i++)
        if (diff & (1 << i))
            X = parent[X][i];
    for (int i = MAX_LOG - 1; i >= 0; i--)
        if (parent[X][i] ^ parent[Y][i])
            X = parent[X][i], Y = parent[Y][i];
    if (X ^ Y)
        X = parent[X][0];
    return X;
}

void dfs(int node, int par) {
    int X;
    pr Y;

    for (int i : adj[node]) {
        if (i == par)
            continue;
        dfs(i, node);
    }

    while (!dw[node].empty() || (!fk[node].empty() && (*fk[node].rbegin())[0] >= depth[node])) {
        while (!dw[node].empty()) {
            X = find(dw[node].back()), dw[node].pop_back();
            if (X > N)
                uni(X, R[X]), X = find(X);
            if (X == node)
                continue;
            while (X ^ node)
                uni(X, node), X = find(parent[X][0]);
        }
        while (!fk[node].empty() && (*fk[node].rbegin())[0] >= depth[node]) {
            Y = *fk[node].rbegin(), fk[node].erase(prev(fk[node].end()));
            uni(Y[1], node);
        }
    }

    if (B[node] == depth[node])
        ans = min(ans, (int)st[node].size());
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int U, V, cnt;
    vector<int> val;

    cin >> N >> K, cnt = N, ans = K;
    for (int i = 1; i < N; i++) {
        cin >> U >> V;
        adj[U].push_back(V), adj[V].push_back(U);
    }
    for (int i = 1; i <= N; i++)
        cin >> C[i], arr[C[i]].push_back(i);

    lca_dfs(1, 0);
    for (int i = 1; i <= N; i++) {
        B[i] = depth[i], uf[i] = R[i] = i;
        st[i].insert({C[i]});
    }

    for (int i = 1; i <= K; i++) {
        sort(arr[i].begin(), arr[i].end(), [&](int x, int y) { return in[x] < in[y]; });
        for (int j : arr[i])
            val.push_back(j);
        for (int j = 0; j + 1 < arr[i].size(); j++)
            val.push_back(lca(arr[i][j], arr[i][j + 1]));
        sort(val.begin(), val.end(), [&](int x, int y) { return in[x] < in[y]; }), val.erase(unique(val.begin(), val.end()), val.end());

        for (int j : val)
            if (C[j] != i) {
                D[j] = ++cnt, R[D[j]] = j;
                uf[D[j]] = D[j], depth[D[j]] = N + 1, B[D[j]] = B[j];
            }

        for (int j = 1; j < val.size(); j++) {
            V = lca(val[j - 1], val[j]);
            U = C[val[j]] == i ? val[j] : D[val[j]];
            B[U] = min(B[U], depth[V]);
            if (C[V] == i)
                dw[V].push_back(U);
            else
                dw[D[V]].push_back(U), fk[U].insert({depth[V], D[V]});
        }
        for (int j : val)
            D[j] = 0;
        val.clear();
    }

    dfs(1, 0), cout << ans - 1 << '\n';

    return 0;
}