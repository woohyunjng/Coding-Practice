#include <bits/stdc++.h>

using namespace std;
typedef array<int, 3> tp;

const int MAX = 400000;

vector<int> adj[2][MAX];
int parent[MAX], sz[MAX], val[2][MAX], cnt[2][MAX];

int find(int X) { return X == parent[X] ? X : parent[X] = find(parent[X]); }
void uni(int X, int Y) {
    X = find(X), Y = find(Y);
    if (X == Y)
        return;
    if (X > Y)
        swap(X, Y);
    sz[X] += sz[Y], parent[Y] = X;
}

void dfs(int x, int node) {
    if (adj[x][node].empty())
        val[x][node] = node, cnt[x][node] = 1;
    else
        for (int i : adj[x][node]) {
            dfs(x, i);
            val[x][node] = min(val[x][i], val[x][node] == 0 ? MAX : val[x][node]);
            cnt[x][node] += cnt[x][i];
        }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N[2], K, X, Y;
    vector<tp> arr;
    bool ans = true;

    cin >> N[0] >> N[1] >> K;
    for (int i = 0; i < 2; i++)
        for (int j = 1; j <= N[i]; j++)
            cin >> X, adj[i][X].push_back(j);
    dfs(0, 0), dfs(1, 0);

    for (int i = 1; i <= K; i++)
        parent[i] = i, sz[i] = 1;

    for (int i = 0; i < 2; i++)
        for (int j = K + 1; j <= N[i]; j++)
            arr.push_back({cnt[i][j], i, j});
    sort(arr.begin(), arr.end());

    for (tp i : arr) {
        X = i[1], Y = i[2];
        for (int j : adj[X][Y])
            uni(val[X][j], val[X][Y]);
        ans &= sz[find(val[X][Y])] <= i[0];
    }

    cout << (ans ? "YES" : "NO") << '\n';

    return 0;
}