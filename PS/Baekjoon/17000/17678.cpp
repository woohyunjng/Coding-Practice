#include <bits/stdc++.h>
using namespace std;

const int MAX = 500001;
const int MAX_LOG = 20;

int S[MAX], uf[MAX],
    parent[MAX][MAX_LOG], depth[MAX], in[MAX], cnt,
    C[MAX];
vector<int> arr[MAX], adj[MAX], gadj[MAX];

int find(int X) { return X == uf[X] ? X : uf[X] = find(uf[X]); }
void uni(int X, int Y) {
    X = find(X), Y = find(Y);
    if (X == Y)
        return;
    uf[max(X, Y)] = min(X, Y);
}

void dfs1(int node, int par) {
    in[node] = ++cnt, depth[node] = depth[par] + 1;
    parent[node][0] = par;
    for (int i = 1; i < MAX_LOG; i++)
        parent[node][i] = parent[parent[node][i - 1]][i - 1];

    for (int i : adj[node]) {
        if (i == par)
            continue;
        dfs1(i, node);
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

void dfs2(int node, int par) {
    for (int i : adj[node]) {
        if (i == par)
            continue;
        dfs2(i, node), C[node] += C[i];
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, U, V, ans = 0;

    cin >> N >> K;
    for (int i = 1; i < N; i++) {
        cin >> U >> V;
        adj[U].push_back(V), adj[V].push_back(U);
    }

    dfs1(1, 0);

    for (int i = 1; i <= N; i++) {
        uf[i] = i;
        cin >> S[i], arr[S[i]].push_back(i);
    }

    for (int i = 1; i <= K; i++) {
        sort(arr[i].begin(), arr[i].end(), [&](int x, int y) { return in[x] < in[y]; }), V = arr[i].size();
        for (int j = 0; j + 1 < V; j++)
            arr[i].push_back(lca(arr[i][j], arr[i][j + 1]));
        sort(arr[i].begin(), arr[i].end(), [&](int x, int y) { return in[x] < in[y]; }), arr[i].erase(unique(arr[i].begin(), arr[i].end()), arr[i].end());

        for (int j = 0; j + 1 < arr[i].size(); j++) {
            V = lca(arr[i][j], arr[i][j + 1]);
            C[arr[i][j + 1]]++, C[V]--;
        }
        arr[i].clear();
    }

    dfs2(1, 0);
    for (int i = 2; i <= N; i++)
        if (C[i] > 0)
            uni(parent[i][0], i);

    for (int i = 1; i <= N; i++)
        arr[find(i)].push_back(i);
    for (int i = 1; i <= N; i++)
        for (int j : arr[i])
            for (int k : adj[j])
                if (i != find(k))
                    gadj[i].push_back(find(k));

    for (int i = 1; i <= N; i++)
        if (find(i) == i)
            ans += gadj[i].size() == 1;

    cout << (ans + 1) / 2 << '\n';

    return 0;
}