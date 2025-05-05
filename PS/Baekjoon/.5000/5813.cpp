#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;

const int MAX = 100001;
const int MOD = 1000000000;

int N, ans, X[MAX], Y[MAX], parent[MAX][2], sz[MAX][2];
map<pr, int> idx;

vector<int> adj[MAX][2];

int find(int X, int T) { return parent[X][T] == X ? X : parent[X][T] = find(parent[X][T], T); }
void uni(int X, int Y, int T) {
    X = find(X, T), Y = find(Y, T);
    if (X == Y)
        return;
    if (X > Y)
        swap(X, Y);
    parent[Y][T] = X, sz[X][T] += sz[Y][T], sz[Y][T] = 0;
}

int dfs(int node, int par, int type) {
    int K, V = sz[node][type];
    for (int i : adj[node][type]) {
        if (i == par)
            continue;
        K = dfs(i, node, type), V += K;
        ans += K * (N - K), ans %= MOD; 
    }
    return V;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int K;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i], idx[{X[i], Y[i]}] = i;
        parent[i][0] = parent[i][1] = i;
        sz[i][0] = sz[i][1] = 1;
    }

    for (int i = 0; i < N; i++) {
        if (idx.find({X[i] + 1, Y[i]}) != idx.end())
            K = idx[{X[i] + 1, Y[i]}], uni(i, K, 0);
        if (idx.find({X[i], Y[i] + 1}) != idx.end())
            K = idx[{X[i], Y[i] + 1}], uni(i, K, 1);
    }

    for (int i = 0; i < N; i++) {
        if (idx.find({X[i], Y[i] + 1}) != idx.end())
            K = find(idx[{X[i], Y[i] + 1}], 0), adj[find(i, 0)][0].push_back(K), adj[K][0].push_back(find(i, 0));
        if (idx.find({X[i] + 1, Y[i]}) != idx.end())
            K = find(idx[{X[i] + 1, Y[i]}], 1), adj[find(i, 1)][1].push_back(K), adj[K][1].push_back(find(i, 1));
    }

    for (int i = 0; i < N; i++) {
        if (find(i, 0) == i)
            sort(adj[i][0].begin(), adj[i][0].end()), adj[i][0].erase(unique(adj[i][0].begin(), adj[i][0].end()), adj[i][0].end());
        if (find(i, 1) == i)
            sort(adj[i][1].begin(), adj[i][1].end()), adj[i][1].erase(unique(adj[i][1].begin(), adj[i][1].end()), adj[i][1].end());
    }

    dfs(0, -1, 0), dfs(0, -1, 1);

    cout << ans << '\n';

    return 0;
}