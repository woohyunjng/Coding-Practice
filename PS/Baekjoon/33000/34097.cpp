#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 100001;
const int INF = 1'000'000'000'000'000'000;

vector<int> adj[MAX];
int uf[MAX], D[MAX], pr[MAX];

int find(int X) {
    if (uf[X] == X)
        return X;
    if (uf[uf[X]] != uf[X])
        find(uf[X]), D[X] = min(INF, D[X] + D[uf[X]]);
    return uf[X] = find(uf[X]);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, S, E, U, V, K, ans = 0;
    bool flag = true;

    cin >> N >> M >> S >> E;
    for (int i = 1; i <= N; i++)
        uf[i] = i;

    while (M--) {
        cin >> U >> V;
        adj[U].push_back(V), adj[V].push_back(U);
    }

    cin >> K, U = -1;
    while (K--)
        cin >> V, pr[V] = U, U = V;

    for (int i = 1; i <= N; i++) {
        for (int j : adj[i]) {
            if (j > i)
                continue;
            V = find(j), D[V] = min(INF, max(D[V], (j == V ? 0 : D[j]) + 1));
        }

        for (int j : adj[i]) {
            if (j > i || find(j) == i)
                continue;
            uf[find(j)] = i;
        }

        if (pr[i] == 0)
            continue;
        else if (pr[i] == -1)
            flag &= find(S) == i, ans = min(INF, ans + D[S]);
        else {
            V = 0;
            for (int j : adj[pr[i]]) {
                if (find(j) != i)
                    continue;
                V = max(V, D[j] + 1);
            }
            flag &= V > 0, ans = min(INF, ans + V);
        }
    }

    if (!flag)
        cout << "impossible" << '\n';
    else if (ans == INF)
        cout << "eternity" << '\n';
    else
        cout << ans << '\n';

    return 0;
}