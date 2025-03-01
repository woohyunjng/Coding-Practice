#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 300000;

vector<int> adj[MAX];
int sz[MAX], in[MAX], out[MAX], cnt;

void dfs(int node, int par) {
    sz[node] = 1, in[node] = ++cnt;
    for (int i : adj[node]) {
        if (i == par)
            continue;
        dfs(i, node), sz[node] += sz[i];
    }
    out[node] = cnt;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, Y, A, B, R, ans = 1;

    cin >> N;
    for (int i = 1; i < N; i++) {
        cin >> X >> Y;
        adj[X].push_back(Y), adj[Y].push_back(X);
    }

    cin >> A >> B >> R;
    dfs(R, -1);

    for (int i : adj[R]) {
        if (in[i] <= in[A] && in[A] <= out[i])
            continue;
        if (in[i] <= in[B] && in[B] <= out[i])
            continue;
        ans += sz[i];
    }

    cout << ans << '\n';

    return 0;
}