#include <bits/stdc++.h>
using namespace std;

typedef array<int, 2> pr;

const int MAX = 1000001;

int uf[4][MAX], sz[MAX], deg[MAX], B[4], D[4][MAX], MD[4], R[MAX], adj[MAX][4];
bool is_cycle[4];

int find(int T, int X) { return X == uf[T][X] ? X : uf[T][X] = find(T, uf[T][X]); }
void uni(int T, int X, int Y) {
    X = find(T, X), Y = find(T, Y);
    uf[T][Y] = X;
    if (T == 0)
        sz[X] += sz[Y];
}

void add_edge(int T, int X, int Y) {
    if (R[X] == T || R[Y] == T)
        return;
    D[T][X]++, D[T][Y]++, MD[T] = max({MD[T], D[T][X], D[T][Y]});
    X = find(T, X), Y = find(T, Y), is_cycle[T] |= X == Y;
    if (X ^ Y)
        uni(T, X, Y);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, U, V, ans,
        cycle_count = 0, cycle_sum = 0;
    bool chk = false;
    vector<pr> edges;

    cin >> N >> Q;
    for (int i = 1; i <= N; i++)
        uf[0][i] = i, sz[i] = 1, R[i] = -1;

    while (Q--) {
        cin >> U;
        if (U == -1) {
            if (!chk)
                ans = cycle_count == 0 ? N : (cycle_count == 1 ? cycle_sum : 0);
            else {
                ans = 0;
                for (int i = 0; i < 4; i++)
                    if (!is_cycle[i] && MD[i] <= 2)
                        ans++;
            }
            cout << ans << '\n';
        } else {
            cin >> V, U++, V++, deg[U]++, deg[V]++;
            if (!chk) {
                MD[0] = max({MD[0], deg[U], deg[V]}), edges.push_back({U, V});
                adj[U][deg[U] - 1] = V, adj[V][deg[V] - 1] = U;

                if (MD[0] <= 2) {
                    if (find(0, U) == find(0, V))
                        cycle_count++, cycle_sum += sz[find(0, U)];
                    else
                        uni(0, U, V);
                } else {
                    chk = true;
                    for (int i = 0; i < 4; i++) {
                        MD[i] = 0;
                        for (int j = 1; j <= N; j++)
                            uf[i][j] = j, D[i][j] = 0;
                    }

                    if (deg[V] == 3)
                        swap(U, V);
                    B[0] = U, R[U] = 0;
                    for (int i = 0; i < deg[U]; i++)
                        B[1 + i] = adj[U][i], R[adj[U][i]] = 1 + i;
                    for (int i = 0; i < 4; i++)
                        for (pr j : edges)
                            add_edge(i, j[0], j[1]);
                    edges.clear();
                }
            } else
                for (int i = 0; i < 4; i++)
                    add_edge(i, U, V);
        }
    }

    return 0;
}