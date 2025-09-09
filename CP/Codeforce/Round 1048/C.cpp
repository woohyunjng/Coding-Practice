#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;

const int MAX = 200001;

vector<int> adj[MAX];
int N, K, depth[MAX], cnt[MAX];

void dfs(int node) {
    cnt[depth[node]]++;
    for (int i : adj[node])
        depth[i] = depth[node] + 1, dfs(i);
}

void solve() {
    int P, ans = 1, S = 0, V, X;
    bool flag;
    vector<int> arr;

    cin >> N >> K;
    for (int i = 2; i <= N; i++)
        cin >> P, adj[P].push_back(i);

    depth[1] = 1, dfs(1);

    V = N;
    for (int i = 1; i <= N; i++)
        if (adj[i].empty())
            V = min(V, depth[i]);

    bitset<MAX> dp, base, clr;
    dp.reset(), base.reset(), clr.reset();

    dp[0] = true;
    for (int i = 0; i <= K; i++)
        base[i] = clr[i] = true;

    for (int i = 1; i <= V; i++) {
        dp |= (dp << cnt[i]), dp &= base;
        for (int j = max(0, S + K - N); j <= min(K, S + cnt[i] + K - N - 1); j++)
            clr[j] = false;
        S += cnt[i];

        if ((dp & clr).none())
            break;
        ans = i;
    }

    cout << ans << '\n';

    for (int i = 1; i <= N; i++)
        adj[i].clear(), cnt[i] = 0;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;

    while (T--)
        solve();

    return 0;
}