#include <bits/stdc++.h>
#define int long long

#define MAX 110

using namespace std;
typedef array<int, 2> pr;

int parent[MAX], sz[MAX], W[MAX][MAX];
vector<int> adj[MAX];

int find(int X) { return parent[X] == X ? X : parent[X] = find(parent[X]); }
void uni(int X, int Y) { parent[max(X, Y)] = min(X, Y); }

int get_size(int node, int par) {
    int res = 1;
    for (int i : adj[node]) {
        if (i == par)
            continue;
        res += get_size(i, node);
    }
    return sz[node] = res;
}

int get_centroid(int node, int par, int cap) {
    for (int i : adj[node]) {
        if (i == par)
            continue;
        if (sz[i] * 2 > cap)
            return get_centroid(i, node, cap);
    }
    return node;
}

vector<int> dfs(int node, int par) {
    vector<int> res = {node};
    for (int i : adj[node]) {
        if (i == par)
            continue;
        vector<int> tmp = dfs(i, node);
        res.insert(res.end(), tmp.begin(), tmp.end());
    }
    return res;
}

signed main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0), cout.tie(0);

    int N, X, A, B, ans = 0, cent, cnt;
    vector<pr> arr;
    vector<int> res;
    vector<vector<int>> children;

    cin >> N;
    for (int i = 1; i <= N; i++)
        parent[i] = i;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++) {
            cin >> W[i][j];
            if (i != j)
                arr.push_back({i, j});
        }

    sort(arr.begin(), arr.end(), [&](pr A, pr B) { return W[A[0]][A[1]] < W[B[0]][B[1]]; });
    for (pr i : arr) {
        A = i[0], B = i[1];
        A = find(A), B = find(B);
        if (A == B)
            continue;
        uni(A, B), adj[i[1]].push_back(i[0]), adj[i[0]].push_back(i[1]);
    }

    cent = get_centroid(1, 0, get_size(1, 0)), get_size(cent, 0), A = N - 1;
    res.push_back(cent);

    for (int i = 1; i <= N; i++)
        ans += W[cent][i];

    for (int i : adj[cent])
        children.push_back(dfs(i, cent));

    cnt = N - 1, X = -1;
    while (cnt--) {
        A = -1, B = -1;
        for (int i = 0; i < children.size(); i++) {
            if ((int)children[i].size() > B && i != X)
                A = i, B = children[i].size();
        }
        X = A, A = -1, B = -1;
        res.push_back(children[X].back()), children[X].pop_back();
    }

    res.push_back(cent);

    cout << ans * 2 << '\n';
    for (int i : res)
        cout << i << ' ';

    return 0;
}