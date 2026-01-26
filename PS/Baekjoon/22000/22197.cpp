#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

const int MAX = 100001;
const int MAX_LOG = 20;

vector<pr> adj[MAX];
int parent[MAX][MAX_LOG], depth[MAX], S[MAX], NM[MAX], in[MAX], cnt;

void dfs1(int node, int par) {
    parent[node][0] = par, depth[node] = depth[par] + 1, in[node] = ++cnt;
    for (int i = 1; i < MAX_LOG; i++)
        parent[node][i] = parent[parent[node][i - 1]][i - 1];

    for (pr i : adj[node]) {
        if (i[0] == par)
            continue;
        NM[i[0]] = i[1], dfs1(i[0], node);
    }
}

void dfs2(int node, int par) {
    for (pr i : adj[node]) {
        if (i[0] == par)
            continue;
        dfs2(i[0], node), S[node] += S[i[0]];
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

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, K, U, V, X, Y;
    vector<int> ans, arr;

    cin >> N >> M >> K;
    for (int i = 1; i < N; i++) {
        cin >> U >> V;
        adj[U].push_back({V, i}), adj[V].push_back({U, i});
    }

    dfs1(1, 0);

    while (M--) {
        cin >> V, arr.clear();
        for (int i = 0; i < V; i++)
            cin >> X, arr.push_back(X);

        sort(arr.begin(), arr.end(), [&](int x, int y) { return in[x] < in[y]; });
        for (int i = 0; i + 1 < V; i++)
            arr.push_back(lca(arr[i], arr[i + 1]));
        sort(arr.begin(), arr.end(), [&](int x, int y) { return in[x] < in[y]; });
        arr.erase(unique(arr.begin(), arr.end()), arr.end());

        S[arr[0]]--;
        for (int i = 0; i < arr.size(); i++) {
            S[arr[i]]++;
            if (i > 0)
                S[lca(arr[i - 1], arr[i])]--;
        }
    }

    dfs2(1, 0);

    for (int i = 2; i <= N; i++)
        if (S[i] >= K)
            ans.push_back(NM[i]);
    sort(ans.begin(), ans.end());

    cout << ans.size() << '\n';
    for (int i : ans)
        cout << i << ' ';
    cout << '\n';

    return 0;
}