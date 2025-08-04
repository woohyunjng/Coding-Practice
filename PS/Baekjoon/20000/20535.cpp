#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 500001;
const int MAX_LOG = 21;

int parent[MAX][MAX_LOG], depth[MAX], in[MAX], cnt, S[MAX], ans = 0;
vector<int> adj[MAX], vadj[MAX];

void dfs1(int node) {
    in[node] = cnt++;
    for (int i : adj[node])
        dfs1(i);
}

void dfs2(int node) {
    vector<int> arr;
    int A = S[node] * S[node];

    arr.push_back(S[node]);
    for (int i : vadj[node])
        dfs2(i), A += S[i] * S[i], S[node] += S[i];
    ans += (S[node] * S[node] - A) / 2 * depth[node];
}

int lca(int A, int B) {
    if (depth[A] < depth[B])
        swap(A, B);

    int diff = depth[A] - depth[B];
    for (int i = 0; diff; i++) {
        if (diff & 1)
            A = parent[A][i];
        diff >>= 1;
    }

    for (int i = MAX_LOG - 1; i >= 0; i--)
        if (parent[A][i] != parent[B][i])
            A = parent[A][i], B = parent[B][i];
    if (A != B)
        A = parent[A][0];
    return A;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, X, Y;
    vector<int> arr;

    cin >> N >> Q;
    for (int i = 2; i <= N; i++) {
        cin >> X, adj[X].push_back(i);
        depth[i] = depth[X] + 1, parent[i][0] = X;
        for (int j = 1; j < MAX_LOG; j++)
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
    }
    dfs1(1);

    while (Q--) {
        cin >> X;
        while (X--)
            cin >> Y, arr.push_back(Y), S[Y] = 1;
        sort(arr.begin(), arr.end(), [](int x, int y) { return in[x] < in[y]; }), X = arr.size();

        for (int i = 1; i < X; i++)
            arr.push_back(lca(arr[i - 1], arr[i]));
        sort(arr.begin(), arr.end(), [](int x, int y) { return in[x] < in[y]; });
        arr.erase(unique(arr.begin(), arr.end()), arr.end()), X = arr.size();
        for (int i = 1; i < X; i++)
            vadj[lca(arr[i - 1], arr[i])].push_back(arr[i]);

        ans = 0, dfs2(arr[0]);
        cout << ans << '\n';

        for (int i : arr)
            S[i] = 0, vadj[i].clear();
        arr.clear();
    }

    return 0;
}