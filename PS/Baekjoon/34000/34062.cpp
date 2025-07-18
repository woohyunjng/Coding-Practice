#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 300001;

vector<int> adj[MAX], D[MAX];
int depth[MAX], parent[MAX], L[MAX], P[MAX];
bool vst[MAX];

void dfs1(int node, int par) {
    depth[node] = depth[par] + 1, parent[node] = par;
    for (int i : adj[node]) {
        if (i == par)
            continue;
        dfs1(i, node);
    }
}

void dfs2(int node, int par, int K) {
    vst[node] = true, P[node] = K;
    L[K] = max(L[K], depth[node]);

    for (int i : adj[node]) {
        if (i == par || vst[i])
            continue;
        dfs2(i, node, K);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, U, V, A, B, X, Y, Z, ans;
    vector<int> arr;

    cin >> N;
    for (int i = 1; i < N; i++) {
        cin >> U >> V;
        adj[U].push_back(V), adj[V].push_back(U);
    }

    dfs1(1, 0), A = max_element(depth + 1, depth + N + 1) - depth;
    dfs1(A, 0), B = max_element(depth + 1, depth + N + 1) - depth;

    U = B;
    while (U) {
        dfs2(U, parent[U], U), L[U] -= depth[U];
        arr.push_back(L[U]), D[L[U]].push_back(depth[U]);
        U = parent[U];
    }

    sort(arr.begin(), arr.end()), arr.erase(unique(arr.begin(), arr.end()), arr.end());
    for (int i : arr)
        sort(D[i].begin(), D[i].end());

    cin >> Q;
    while (Q--) {
        cin >> U >> V;
        X = P[U], Y = P[V];
        if (depth[X] > depth[Y])
            swap(X, Y), swap(U, V);

        ans = max(
            (depth[U] + depth[B] - depth[X] * 2) * (depth[V] + depth[B] - depth[Y] * 2),
            (depth[U] - depth[A]) * (depth[V] - depth[A]));

        for (int i : arr) {
            Z = lower_bound(D[i].begin(), D[i].end(), (depth[V] - depth[U] + depth[X] * 2 + 1) / 2) - D[i].begin();
            if (Z < D[i].size() && D[i][Z] <= depth[Y])
                ans = max(ans, (depth[U] + D[i][Z] - depth[X] * 2 + i) * (depth[V] - D[i][Z] + i));
            if (Z > 0 && D[i][Z - 1] >= depth[X])
                ans = max(ans, (depth[U] + D[i][Z - 1] - depth[X] * 2 + i) * (depth[V] - D[i][Z - 1] + i));
        }

        cout << ans << '\n';
    }

    return 0;
}