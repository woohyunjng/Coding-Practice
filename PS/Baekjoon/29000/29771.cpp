#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 100001;
const int MAX_LOG = 20;

int parent[MAX][MAX_LOG], in[MAX], depth[MAX], len[MAX], cnt;
vector<int> adj[MAX];

void dfs1(int node, int par) {
    in[node] = ++cnt, parent[node][0] = par;
    depth[node] = depth[par] + 1, len[node] = len[par] + node - 1;
    for (int i = 1; i < MAX_LOG; i++)
        parent[node][i] = parent[parent[node][i - 1]][i - 1];

    for (int i : adj[node]) {
        if (i == par)
            continue;
        dfs1(i, node);
    }
}

int lca(int U, int V) {
    if (depth[U] < depth[V])
        swap(U, V);

    int diff = depth[U] - depth[V];
    for (int i = 0; i < MAX_LOG; i++)
        if (diff & (1 << i))
            U = parent[U][i];

    for (int i = MAX_LOG - 1; i >= 0; i--)
        if (parent[U][i] != parent[V][i])
            U = parent[U][i], V = parent[V][i];

    if (U ^ V)
        U = parent[U][0];
    return U;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, U, V, ans, ans_s;
    vector<int> arr;

    cin >> N;
    for (int i = 1; i < N; i++) {
        cin >> U >> V, U++, V++;
        adj[U].push_back(V), adj[V].push_back(U);
    }

    dfs1(1, 0);

    cin >> Q;
    while (Q--) {
        cin >> U, ans = ans_s = 0;
        for (int i = 0; i < U; i++)
            cin >> V, arr.push_back(V + 1);

        sort(arr.begin(), arr.end(), [](int x, int y) { return in[x] < in[y]; });
        for (int i = 1; i < U; i++)
            arr.push_back(lca(arr[i - 1], arr[i]));

        sort(arr.begin(), arr.end(), [](int x, int y) { return in[x] < in[y]; });
        arr.erase(unique(arr.begin(), arr.end()), arr.end());

        ans++, ans_s += arr[0] - 1;
        for (int i = 1; i < arr.size(); i++) {
            ans += depth[arr[i]] - depth[lca(arr[i - 1], arr[i])];
            ans_s += len[arr[i]] - len[lca(arr[i - 1], arr[i])];
        }

        cout << ans << ' ' << ans_s << '\n';
        arr.clear();
    }

    return 0;
}