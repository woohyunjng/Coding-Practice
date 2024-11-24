#include <bits/stdc++.h>
#define int long long

#define MAX 100100
#define MAX_LOG 20
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int T[MAX], depth[MAX], order[MAX][2], cnt = 0, res[MAX], C[MAX], parent[MAX][MAX_LOG];
vector<int> adj[MAX], arr[MAX];
vector<pr> do_adj[MAX];

void dfs_init(int K, int P) {
    order[K][0] = ++cnt;

    parent[K][0] = P;
    for (int i = 1; i < MAX_LOG; i++)
        parent[K][i] = parent[parent[K][i - 1]][i - 1];

    for (int i : adj[K]) {
        if (i == P)
            continue;
        depth[i] = depth[K] + 1;
        dfs_init(i, K);
    }
    order[K][1] = cnt;
}

int LCA(int X, int Y) {
    if (depth[X] < depth[Y])
        swap(X, Y);

    int diff = depth[X] - depth[Y];
    for (int i = 0; diff; i++) {
        if (diff & 1)
            X = parent[X][i];
        diff >>= 1;
    }

    for (int i = MAX_LOG - 1; i >= 0; i--) {
        if (parent[X][i] != parent[Y][i])
            X = parent[X][i], Y = parent[Y][i];
    }

    if (X != Y)
        X = parent[X][0];
    return X;
}

void dfs(int K, int P) {
    int X;
    arr[T[K]].push_back(K);

    for (pr i : do_adj[K]) {
        if (arr[C[i.second]].empty())
            continue;
        X = arr[C[i.second]].back();

        if (LCA(K, i.first) == X)
            res[i.second] = 1;
        else if (!(order[X][0] <= order[i.first][0] && order[i.first][1] <= order[X][1]))
            res[i.second] = 1;
    }

    for (int i : adj[K]) {
        if (i == P)
            continue;
        dfs(i, K);
    }
    arr[T[K]].pop_back();
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X, Y;
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        cin >> T[i];

    for (int i = 1; i < N; i++) {
        cin >> X >> Y;
        adj[X].push_back(Y), adj[Y].push_back(X);
    }

    dfs_init(1, 0);

    for (int i = 1; i <= M; i++) {
        cin >> X >> Y >> C[i];
        do_adj[X].push_back({Y, i}), do_adj[Y].push_back({X, i});
    }

    dfs(1, 0);

    for (int i = 1; i <= M; i++)
        cout << res[i];
    cout << '\n';

    return 0;
}