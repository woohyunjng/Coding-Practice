#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;

const int MAX = 300000;
const int MOD = 1000000007;

vector<int> tree_adj[MAX], adj[MAX];
int ans = 0, cnt = 0;

int dfs(int node, int par) {
    int res = 1;
    for (int i : tree_adj[node]) {
        if (i == par)
            continue;
        res = res * (dfs(i, node) + 1) % MOD;
    }
    ans = (ans + res) % MOD;
    return res;
}

int dnc(int s, int e) {
    if (s + 1 == e)
        return -1;
    int X = *prev(lower_bound(adj[s].begin(), adj[s].end(), e)), K = cnt++, A, B;
    A = dnc(s, X), B = dnc(X, e);
    if (A != -1)
        tree_adj[A].push_back(K), tree_adj[K].push_back(A);
    if (B != -1)
        tree_adj[B].push_back(K), tree_adj[K].push_back(B);
    return K;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, Y, K = 0;

    cin >> N;
    for (int i = 0; i < N; i++) {
        adj[i].push_back((i + 1) % N);
        adj[(i + 1) % N].push_back(i);
    }

    for (int i = 0; i < N - 3; i++) {
        cin >> X >> Y, X--, Y--;
        adj[X].push_back(Y), adj[Y].push_back(X);
    }

    for (int i = 0; i < N; i++)
        sort(adj[i].begin(), adj[i].end());

    dnc(0, N - 1), dfs(0, -1);
    cout << ans << '\n';

    return 0;
}