#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

typedef array<int, 2> pr;

const int MAX = 500002;
const int MAX_LOG = 20;
const int INF = 1e9;

int U[MAX], V[MAX], L[MAX], R[MAX], ans[MAX], B[MAX],
    parent[MAX][MAX_LOG], sparse[MAX][MAX_LOG][2], depth[MAX];
vector<pr> adj[MAX];
vector<int> in[MAX];

void dfs(int node, int par) {
    parent[node][0] = par, depth[node] = depth[par] + 1;
    sparse[node][0][0] = INF, sparse[node][0][1] = L[B[node]];

    for (int i = 1; i < MAX_LOG; i++) {
        parent[node][i] = parent[parent[node][i - 1]][i - 1];
        sparse[node][i][0] = min(sparse[node][i - 1][0], sparse[parent[node][i - 1]][i - 1][0]);
        sparse[node][i][1] = max(sparse[node][i - 1][1], sparse[parent[node][i - 1]][i - 1][1]);
    }

    for (pr i : adj[node]) {
        if (i[0] == par)
            continue;
        B[i[0]] = i[1], dfs(i[0], node);
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

    int T, N, M, X, Y, Z;
    bool ans_chk;

    set<pr> st;
    pr K;

    cin >> T;
    while (T--) {
        for (int i = 0; i < MAX_LOG; i++)
            sparse[0][i][0] = INF, sparse[0][i][1] = 0;

        cin >> N >> M, ans_chk = true;
        for (int i = 1; i <= M; i++) {
            cin >> U[i] >> V[i] >> L[i] >> R[i];
            if (i < N)
                adj[U[i]].push_back({V[i], i}), adj[V[i]].push_back({U[i], i});
        }

        dfs(1, 0);

        for (int i = N; i <= M; i++) {
            X = lca(U[i], V[i]);
            Y = depth[U[i]] - depth[X], Z = U[i];
            for (int j = 0; j < MAX_LOG; j++)
                if (Y & (1 << j)) {
                    L[i] = max(L[i], sparse[Z][j][1] + 1);
                    sparse[Z][j][0] = min(sparse[Z][j][0], R[i] - 1);
                    Z = parent[Z][j];
                }
            Y = depth[V[i]] - depth[X], Z = V[i];
            for (int j = 0; j < MAX_LOG; j++)
                if (Y & (1 << j)) {
                    L[i] = max(L[i], sparse[Z][j][1] + 1);
                    sparse[Z][j][0] = min(sparse[Z][j][0], R[i] - 1);
                    Z = parent[Z][j];
                }
        }

        for (int i = MAX_LOG - 1; i > 0; i--)
            for (int j = 1; j <= N; j++) {
                sparse[j][i - 1][0] = min(sparse[j][i - 1][0], sparse[j][i][0]);
                sparse[parent[j][i - 1]][i - 1][0] = min(sparse[parent[j][i - 1]][i - 1][0], sparse[j][i][0]);
            }

        for (int i = 2; i <= N; i++)
            R[B[i]] = min(R[B[i]], sparse[i][0][0]);

        for (int i = 1; i <= M; i++) {
            ans_chk &= L[i] <= R[i];
            in[L[i]].push_back(i);
        }

        for (int i = 1; i <= M && ans_chk; i++) {
            for (int j : in[i])
                st.insert({R[j], j});
            while (!st.empty() && (*st.begin())[0] < i)
                st.erase(st.begin());
            ans_chk &= !st.empty();
            if (ans_chk)
                K = *st.begin(), st.erase(st.begin()), ans[K[1]] = i;
        }

        if (ans_chk) {
            cout << "YES" << '\n';
            for (int i = 1; i <= M; i++)
                cout << ans[i] << ' ';
            cout << '\n';
        } else
            cout << "NO" << '\n';

        for (int i = 1; i <= N; i++)
            adj[i].clear();
        for (int i = 0; i <= M + 1; i++)
            in[i].clear();
        st.clear();
    }

    return 0;
}