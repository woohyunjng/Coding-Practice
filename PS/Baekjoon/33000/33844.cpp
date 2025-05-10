#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 100001;
const int MAX_LOG = 20;
const int BUCKET = 1500;

int A[MAX], P[MAX], OR[MAX][2], V[MAX][3], L[MAX], R[MAX], TG[MAX], TL[MAX], COL[MAX], ans[MAX], parent[MAX][MAX_LOG], depth[MAX], in[MAX], out[MAX], cnt = 1, res;
vector<int> adj[MAX];
bool toggled[MAX];

void dfs(int node, int par) {
    in[node] = cnt++, parent[node][0] = par, depth[node] = depth[par] + 1;
    for (int i = 1; i < MAX_LOG; i++)
        parent[node][i] = parent[parent[node][i - 1]][i - 1];

    for (int i : adj[node]) {
        if (i == par)
            continue;
        dfs(i, node);
    }

    out[node] = cnt++;
}

int lca(int X, int Y) {
    if (depth[X] < depth[Y])
        swap(X, Y);

    int diff = depth[X] - depth[Y];
    for (int i = 0; i < MAX_LOG; i++) {
        if (diff & 1)
            X = parent[X][i];
        diff >>= 1;
    }

    for (int i = MAX_LOG - 1; i >= 0; i--)
        if (parent[X][i] != parent[Y][i])
            X = parent[X][i], Y = parent[Y][i];

    if (X != Y)
        X = parent[X][0];
    return X;
}

void toggle(int node) {
    if (node == 0)
        return;
    if (!toggled[node])
        res += A[node] * (P[COL[A[node]] + 1] - P[COL[A[node]]]), COL[A[node]]++;
    else
        res += A[node] * (P[COL[A[node]] - 1] - P[COL[A[node]]]), COL[A[node]]--;
    toggled[node] = !toggled[node];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M = 0, Q, T, X, Y, Z, CL, CR, CT, K = 0;
    vector<int> queries[2];

    cin >> N >> Q;

    for (int i = 1; i <= N; i++)
        cin >> A[i], M = max(M, A[i]);
    for (int i = 1; i <= N; i++)
        cin >> P[i];

    for (int i = 1; i < N; i++)
        cin >> X >> Y, adj[X].push_back(Y), adj[Y].push_back(X);
    dfs(1, 0);

    for (int i = 1; i <= N; i++)
        OR[in[i]][0] = OR[in[i]][1] = OR[out[i]][1] = i;

    for (int i = 1; i <= Q; i++) {
        cin >> T;
        if (T == 1) {
            cin >> X, L[i] = in[X], R[i] = out[X], TL[i] = K;
            queries[0].push_back(i);
        } else if (T == 2) {
            cin >> X >> Y, Z = lca(X, Y);
            L[i] = in[X], R[i] = in[Y], TL[i] = K;
            if (L > R)
                swap(L[i], R[i]);
            if (Z != X && Z != Y)
                TG[i] = Z;
            queries[1].push_back(i);
        } else {
            cin >> V[++K][0] >> V[K][1], ans[i] = -1;
            V[K][2] = A[V[K][0]], A[V[K][0]] = V[K][1], M = max(M, V[K][1]);
        }
    }

    for (int t = 0; t < 2; t++) {
        sort(queries[t].begin(), queries[t].end(), [&](int a, int b) {
            if (L[a] / BUCKET != L[b] / BUCKET)
                return L[a] < L[b];
            else if (R[a] / BUCKET != R[b] / BUCKET)
                return R[a] < R[b];
            else
                return TL[a] < TL[b];
        });

        CL = 1, CR = 0, CT = K, res = 0;
        for (int i = 1; i <= K; i++)
            A[V[i][0]] = V[i][1];
        for (int i = 1; i <= N; i++)
            toggled[i] = false;
        for (int i = 1; i <= M; i++)
            COL[i] = 0;

        for (int i : queries[t]) {
            while (CL > L[i])
                toggle(OR[--CL][t]);
            while (CR < R[i])
                toggle(OR[++CR][t]);
            while (CL < L[i])
                toggle(OR[CL++][t]);
            while (CR > R[i])
                toggle(OR[CR--][t]);

            while (CT < TL[i]) {
                CT++;
                if (toggled[V[CT][0]]) {
                    res += A[V[CT][0]] * (P[COL[A[V[CT][0]]] - 1] - P[COL[A[V[CT][0]]]]), COL[A[V[CT][0]]]--;
                    res += V[CT][1] * (P[COL[V[CT][1]] + 1] - P[COL[V[CT][1]]]), COL[V[CT][1]]++;
                }
                A[V[CT][0]] = V[CT][1];
            }
            while (CT > TL[i]) {
                if (toggled[V[CT][0]]) {
                    res += A[V[CT][0]] * (P[COL[A[V[CT][0]]] - 1] - P[COL[A[V[CT][0]]]]), COL[A[V[CT][0]]]--;
                    res += V[CT][2] * (P[COL[V[CT][2]] + 1] - P[COL[V[CT][2]]]), COL[V[CT][2]]++;
                }
                A[V[CT][0]] = V[CT][2], CT--;
            }

            if (TG[i])
                toggle(TG[i]);
            ans[i] = res;
            if (TG[i])
                toggle(TG[i]);
        }
    }

    for (int i = 1; i <= Q; i++)
        if (ans[i] != -1)
            cout << ans[i] << '\n';

    return 0;
}