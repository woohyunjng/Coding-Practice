#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 100001;

int A[MAX], B[MAX], C[MAX], D[MAX], W[MAX], depth[MAX], parent[MAX], dsu[MAX][2], val[MAX][2], sz[MAX][2];
vector<int> adj[MAX];

int find(int X, int T) { return dsu[X][T] == X ? X : dsu[X][T] = find(dsu[X][T], T); }
void uni(int X, int Y, int T, int D = 0) {
    X = find(X, T), Y = find(Y, T);
    if (X == Y)
        return;
    if (depth[X] > depth[Y])
        swap(X, Y);
    else if (depth[X] == depth[Y] && X > Y)
        swap(X, Y);
    dsu[Y][T] = X, sz[X][T] += sz[Y][T], val[X][T] += val[Y][T];
    val[X][T] += D;
}

void dfs(int node, int par) {
    parent[node] = par, depth[node] = depth[par] + 1;
    for (int i : adj[node]) {
        if (i == par)
            continue;
        dfs(i, node);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X, Y;
    vector<int> arr;

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        dsu[i][0] = dsu[i][1] = i, sz[i][0] = sz[i][1] = 1, val[i][0] = val[i][1] = 0;

    for (int i = 1; i < N; i++) {
        cin >> X >> Y;
        adj[X].push_back(Y), adj[Y].push_back(X);
    }
    dfs(1, 0);

    for (int i = 1; i <= M; i++) {
        cin >> A[i] >> B[i] >> C[i] >> D[i] >> W[i];
        arr.push_back(i);
    }

    sort(arr.begin(), arr.end(), [&](int x, int y) { return W[x] < W[y]; });

    for (int i : arr) {
        X = find(A[i], 1), Y = find(B[i], 1);
        while (X ^ Y) {
            if (depth[X] > depth[Y])
                swap(X, Y);
            uni(X, Y, 1), uni(X, Y, 0, W[i]);
            Y = find(parent[Y], 1);
        }

        X = find(C[i], 1), Y = find(D[i], 1);
        while (X ^ Y) {
            if (depth[X] > depth[Y])
                swap(X, Y);
            uni(X, Y, 1), uni(X, Y, 0, W[i]);
            Y = find(parent[Y], 1);
        }

        uni(find(A[i], 0), find(C[i], 0), 0, W[i]);
    }

    X = find(1, 0);
    cout << sz[X][0] << ' ' << val[X][0] << '\n';

    return 0;
}