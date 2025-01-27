#include <bits/stdc++.h>
#define int long long

#define MAX 500000
#define MAX_LOG 23
using namespace std;

typedef array<int, 2> pr;

int W[MAX], parent[MAX][MAX_LOG], depth[MAX], mx[MAX], in[MAX], out[MAX], cnt;
pr tree[MAX * 4];
vector<int> adj[MAX], arr[MAX], tmp;

void dfs(int node, int par) {
    parent[node][0] = par, depth[node] = depth[par] + 1;
    in[node] = ++cnt;
    for (int i = 1; i < MAX_LOG; i++)
        parent[node][i] = parent[parent[node][i - 1]][i - 1];

    for (int i : adj[node]) {
        if (i == par)
            continue;
        dfs(i, node);
    }

    out[node] = cnt;
}

int lca(int x, int y) {
    if (depth[x] < depth[y])
        swap(x, y);
    int diff = depth[x] - depth[y];
    for (int i = 0; diff; i++) {
        if (diff & 1)
            x = parent[x][i];
        diff >>= 1;
    }

    for (int i = MAX_LOG - 1; i >= 0; i--) {
        if (parent[x][i] != parent[y][i])
            x = parent[x][i], y = parent[y][i];
    }
    if (x != y)
        x = parent[x][0];

    return x;
}

pr merge(pr A, pr B) {
    tmp.clear();
    for (int i : A)
        tmp.push_back(i);
    for (int i : B)
        tmp.push_back(i);
    sort(tmp.begin(), tmp.end()), tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    if (tmp.size() == 0)
        return {0, 0};
    else if (tmp.size() == 1)
        return {tmp[0], 0};
    else
        return {tmp[tmp.size() - 1], tmp[tmp.size() - 2]};
}

void init(int n, int s, int e) {
    if (s == e)
        tree[n] = {W[in[s]], 0};
    else {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
        tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
    }
}

pr query(int n, int s, int e, int l, int r) {
    if (r < s || e < l)
        return {0, 0};
    if (l <= s && e <= r)
        return tree[n];
    int m = s + e >> 1;
    return merge(query(n << 1, s, m, l, r), query(n << 1 | 1, m + 1, e, l, r));
}

void solve() {
    int N, X = 0, Y, res = 0;
    vector<int> val, ans;
    pr A, B;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> W[i], arr[W[i]].push_back(i);

    for (int i = 1; i < N; i++) {
        cin >> X >> Y;
        adj[X].push_back(Y), adj[Y].push_back(X);
    }

    cnt = 0, dfs(1, 0);
    init(1, 1, N);

    for (int i = 1; i <= N; i++) {
        if (arr[i].size() == 0)
            continue;
        mx[i] = arr[i][0];
        for (int j = 1; j < arr[i].size(); j++)
            mx[i] = lca(mx[i], arr[i][j]);
    }

    X = 0;
    for (int i = N; i >= 1; i--) {
        if (arr[i].size() == 0)
            continue;
        if (X == 0) {
            X = mx[i];
            continue;
        }

        val.clear();
        for (int j : arr[i])
            if (lca(X, j) != j && res == 0)
                val.push_back(j);
        if (!val.empty() && ans.empty())
            ans = val;
        X = lca(X, mx[i]);
    }

    for (int i = 1; i <= N; i++) {
        A = query(1, 1, N, 1, in[i] - 1), B = query(1, 1, N, out[i] + 1, N);
        A = merge(A, B);

        if (A[0] > W[i] && W[i] >= A[1])
            ans.push_back(i);
    }

    sort(ans.begin(), ans.end()), ans.erase(unique(ans.begin(), ans.end()), ans.end());
    cout << ans.size() << ' ';
    for (int i : ans)
        cout << i << ' ';
    cout << '\n';

    for (int i = 1; i <= N; i++) {
        adj[i].clear(), arr[i].clear(), mx[i] = 0, depth[i] = 0;
        for (int j = 0; j < MAX_LOG; j++)
            parent[i][j] = 0;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;

    while (T--)
        solve();

    return 0;
}