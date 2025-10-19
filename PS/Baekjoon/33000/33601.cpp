#include <bits/stdc++.h>
using namespace std;

const int MAX = 200001;
const int MAX_LOG = 20;
const int INF = 1e9;

typedef array<int, 2> pr;

vector<int> adj[MAX], child[MAX];
multiset<int> val[MAX];
multiset<pr> V[MAX];

int N, D[MAX], A[MAX], S[MAX],
    parent[MAX][MAX_LOG], depth[MAX];
bool vst[MAX], ans_chk = true, chk[MAX];

int lca(int X, int Y) {
    if (depth[X] < depth[Y])
        swap(X, Y);
    int diff = depth[X] - depth[Y];
    for (int i = 0; i < MAX_LOG; i++)
        if ((diff >> i) & 1)
            X = parent[X][i];
    for (int i = MAX_LOG - 1; i >= 0; i--)
        if (parent[X][i] != parent[Y][i])
            X = parent[X][i], Y = parent[Y][i];
    if (X != Y)
        X = parent[X][0];
    return X;
}

void dfs1(int node, int par) {
    parent[node][0] = par;
    for (int i = 1; i < MAX_LOG; i++)
        parent[node][i] = parent[parent[node][i - 1]][i - 1];

    for (int i : child[node])
        depth[i] = depth[node] + 1, dfs1(i, node);
}

void dfs2(int node) {
    int X;
    pr K;

    chk[node] = node == 1;
    for (int i : child[node]) {
        dfs2(i), S[i]++, chk[node] |= chk[i];

        while (!V[i].empty() && (*V[i].rbegin())[0] == depth[node])
            X = (*V[i].rbegin())[1], V[i].erase(--V[i].end()), val[i].erase(val[i].find(X));
        if (V[node].size() < V[i].size())
            swap(V[node], V[i]), swap(val[node], val[i]), swap(S[node], S[i]);
        while (!V[i].empty()) {
            K = *V[i].begin(), V[i].erase(V[i].begin()), val[i].erase(val[i].find(K[1]));
            K[1] += S[i] - S[node], V[node].insert(K), val[node].insert(K[1]);
        }
    }

    for (int i : adj[node]) {
        if (parent[i][0] == node || parent[node][0] == i)
            continue;
        X = lca(node, i), V[node].insert({depth[X], depth[i] + 1 - S[node]}), val[node].insert(depth[i] + 1 - S[node]);
    }

    if (node == N)
        return;
    if (val[node].empty())
        ans_chk &= !chk[node];
    else
        D[node] = (*val[node].begin()) + S[node];
}

// D[i]: 내 go 간선 막았을때 최댓값

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int M, X, Y;
    queue<int> q;

    cin >> N >> M;
    while (M--) {
        cin >> X >> Y;
        adj[X].push_back(Y), adj[Y].push_back(X);
    }

    q.push(N), vst[N] = true;
    while (!q.empty()) {
        X = q.front(), q.pop();
        for (int i : adj[X]) {
            if (vst[i])
                continue;
            q.push(i), vst[i] = true, child[X].push_back(i);
        }
    }

    dfs1(N, 0), dfs2(N);

    priority_queue<pr, vector<pr>, greater<pr>> pq;
    pr P;

    fill(A + 1, A + N + 1, INF);
    pq.push({0, N}), A[N] = 0;

    while (!pq.empty()) {
        P = pq.top(), pq.pop();
        if (A[P[1]] < P[0])
            continue;

        for (int i : adj[P[1]]) {
            X = max(D[i], min(A[i], P[0] + 1));
            if (A[i] > X)
                A[i] = X, pq.push({X, i});
        }
    }

    cout << (ans_chk ? A[1] : -1) << '\n';

    return 0;
}