#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

const int MAX = 500001;

int V[MAX];
vector<pr> adj[MAX];
map<int, int> cnt;

void dfs(int node, int par) {
    for (pr i : adj[node]) {
        if (i[0] == par)
            continue;
        V[i[0]] = V[node] ^ i[1], dfs(i[0], node);
    }
    cnt[V[node]]++;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, Y, W, ans = 0;

    cin >> N;
    for (int i = 1; i < N; i++) {
        cin >> X >> Y >> W;
        adj[X].push_back({Y, W}), adj[Y].push_back({X, W});
    }

    dfs(1, 0);

    for (int i = 1; i <= N; i++) {
        if (cnt[V[i]] == 0)
            continue;
        ans += cnt[V[i]] * (cnt[V[i]] - 1) / 2, cnt[V[i]] = 0;
    }

    cout << ans << '\n';

    return 0;
}