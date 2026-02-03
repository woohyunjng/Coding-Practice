#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

const int MAX = 500001;
const int MAX_LOG = 20;
const int INF = 0x3f3f3f3f3f3f3f3f;

vector<int> adj[MAX];
vector<pr> ch[MAX];
int A[MAX_LOG], B[MAX_LOG], S[MAX], F[MAX],
    parent[MAX][MAX_LOG], sz[MAX], P[MAX], depth[MAX], in[MAX], cnt;
bool chk[MAX];

void dfs1(int node, int par) {
    sz[node] = 1, parent[node][0] = par;
    depth[node] = depth[par] + 1, in[node] = ++cnt;
    for (int i = 1; i < MAX_LOG; i++)
        parent[node][i] = parent[parent[node][i - 1]][i - 1];

    for (int i : adj[node]) {
        if (i == par)
            continue;
        dfs1(i, node), sz[node] += sz[i];
    }
}

int climb(int X, int K) {
    for (int i = 0; i < MAX_LOG; i++)
        if (K & (1 << i))
            X = parent[X][i];
    return X;
}

int lca(int X, int Y) {
    if (depth[X] < depth[Y])
        swap(X, Y);
    X = climb(X, depth[X] - depth[Y]);
    for (int i = MAX_LOG - 1; i >= 0; i--)
        if (parent[X][i] ^ parent[Y][i])
            X = parent[X][i], Y = parent[Y][i];
    if (X ^ Y)
        X = parent[X][0];
    return X;
}

int dfs2(int node) {
    vector<int> arr;
    int X = 0, ans = 0;

    for (pr i : ch[node]) {
        ans += dfs2(i[0]), arr.push_back(i[0]);
        S[node] += S[i[0]], ans += S[i[0]] * i[1];
        if (S[i[0]] < 0)
            ans += ((sz[P[i[0]]] << 1) - (sz[i[0]] << 1) - ((i[1] - 1) << 1)) * S[i[0]];
    }
    sz[0] = F[node], arr.push_back(0);

    sort(arr.begin(), arr.end(), [&](int x, int y) { return S[x] * sz[P[y]] > S[y] * sz[P[x]]; });
    for (int i : arr)
        ans += X * S[i], X += sz[P[i]] << 1;
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, U, V, ans = INF;
    vector<int> arr;

    cin >> N >> K;
    for (int i = 1; i < N; i++) {
        cin >> U >> V;
        adj[U].push_back(V), adj[V].push_back(U);
    }

    dfs1(1, 0);
    for (int i = 0; i < K; i++) {
        cin >> A[i] >> B[i], A[i] = climb(B[i], depth[B[i]] - depth[A[i]] - 1);
        arr.push_back(A[i]), arr.push_back(B[i]);
    }
    arr.push_back(1);

    sort(arr.begin(), arr.end(), [&](int x, int y) { return in[x] < in[y]; }), V = arr.size();
    for (int i = 1; i < V; i++)
        arr.push_back(lca(arr[i - 1], arr[i]));
    sort(arr.begin(), arr.end(), [&](int x, int y) { return in[x] < in[y]; }), arr.erase(unique(arr.begin(), arr.end()), arr.end());
    for (int i = 1; i < arr.size(); i++) {
        V = lca(arr[i - 1], arr[i]), ch[V].push_back({arr[i], depth[arr[i]] - depth[V]});
        P[arr[i]] = climb(arr[i], depth[arr[i]] - depth[V] - 1), chk[P[arr[i]]] = true;
    }

    for (int i = 1; i <= N; i++) {
        for (int j : adj[i]) {
            if (j == parent[i][0] || chk[j])
                continue;
            F[i] += sz[j];
        }
    }

    for (int i = 0; i < (1 << K); i++) {
        for (int j : arr)
            S[j] = 0;
        V = K;
        for (int j = 0; j < K; j++) {
            if (i & (1 << j)) {
                S[A[j]]++, S[B[j]]--;
                V += ((sz[A[j]] - 1) << 1), V -= ((sz[B[j]] - 1) << 1);
            } else
                S[A[j]]--, S[B[j]]++;
        }
        V += dfs2(1), ans = min(ans, V);
    }

    cout << ans << '\n';

    return 0;
}