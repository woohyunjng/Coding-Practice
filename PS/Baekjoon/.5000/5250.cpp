#include <bits/stdc++.h>
#define int long long

#define MAX 3000
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;
typedef array<int, 2> pr;
typedef array<int, 3> tp;

vector<pr> adj[MAX];
int dis[2][MAX], P[2][MAX], tree[MAX * 4], lazy[MAX * 4], V[MAX], C[MAX];

void lazy_propagate(int n, int s, int e) {
    if (lazy[n] == INF)
        return;
    tree[n] = min(tree[n], lazy[n]);
    if (s != e) {
        lazy[n << 1] = min(lazy[n << 1], lazy[n]);
        lazy[n << 1 | 1] = min(lazy[n << 1 | 1], lazy[n]);
    }
    lazy[n] = INF;
}

int query(int n, int s, int e, int l, int r) {
    lazy_propagate(n, s, e);
    if (r < s || e < l)
        return INF;
    else if (l <= s && e <= r)
        return tree[n];
    else {
        int m = s + e >> 1;
        return min(
            query(n << 1, s, m, l, r),
            query(n << 1 | 1, m + 1, e, l, r));
    }
}

void update(int n, int s, int e, int l, int r, int v) {
    lazy_propagate(n, s, e);
    if (r < s || e < l)
        return;
    else if (l <= s && e <= r) {
        lazy[n] = min(lazy[n], v);
        lazy_propagate(n, s, e);
        return;
    } else {
        int m = s + e >> 1;
        update(n << 1, s, m, l, r, v), update(n << 1 | 1, m + 1, e, l, r, v);
        tree[n] = min(tree[n << 1], tree[n << 1 | 1]);
    }
}

void dfs(int node, int type, int luck) {
    if (C[node])
        luck = node;
    P[type][node] = luck;
    for (pr i : adj[node]) {
        if (P[type][i[1]] || dis[type][i[1]] != dis[type][node] + i[0])
            continue;
        if (C[node] == 0 && C[i[1]])
            continue;
        dfs(i[1], type, luck);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X, Y, Z, A[2], K;
    vector<tp> edge;

    priority_queue<pr, vector<pr>, greater<pr>> pq;
    pr S;

    cin >> N >> M >> A[0] >> A[1];

    while (M--) {
        cin >> X >> Y >> Z;
        adj[X].push_back({Z, Y}), adj[Y].push_back({Z, X});
    }

    cin >> K;
    for (int i = 1; i <= K; i++)
        cin >> X, C[X] = i;
    K--;

    fill(tree, tree + (N + 1) * 4, INF);
    fill(lazy, lazy + (N + 1) * 4, INF);
    fill(&dis[0][0], &dis[1][N + 1], INF);

    for (int i = 0; i < 2; i++) {
        pq.push({0, A[i]}), dis[i][A[i]] = 0;

        while (!pq.empty()) {
            S = pq.top(), pq.pop();
            if (dis[i][S[1]] < S[0])
                continue;

            for (pr j : adj[S[1]]) {
                if (S[0] + j[0] < dis[i][j[1]]) {
                    dis[i][j[1]] = S[0] + j[0];
                    pq.push({dis[i][j[1]], j[1]});
                }
            }
        }

        dfs(A[i], i, 0);
    }

    for (int i = 1; i <= N; i++) {
        for (pr j : adj[i]) {
            if (C[i] > 0 && C[j[1]] > 0 && C[j[1]] - C[i] == 1)
                continue;
            update(1, 1, K, C[P[0][i]], C[P[1][j[1]]] - 1, dis[0][i] + dis[1][j[1]] + j[0]);
        }
    }

    for (int i = 1; i <= K; i++) {
        X = query(1, 1, K, i, i);
        cout << (X == INF ? -1 : X) << '\n';
    }

    return 0;
}