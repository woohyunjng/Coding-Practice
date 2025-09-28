#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

const int MAX = 5001;

vector<pr> adj[MAX];
vector<int> comp, ans;

int depth[MAX], cnt[MAX];
bool dp[MAX][MAX], chk[MAX];

void dfs(int node, int par) {
    comp.push_back(depth[node]);
    for (pr i : adj[node]) {
        if (i[0] == par)
            continue;
        depth[i[0]] = depth[node] + i[1], dfs(i[0], node);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, K = 0, U, V, C;

    cin >> N >> M;
    for (int i = 1; i < N; i++) {
        cin >> U >> V >> C;
        adj[U].push_back({V, C}), adj[V].push_back({U, C});
    }

    dfs(1, 0);

    sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end());

    for (int i = 1; i <= N; i++) {
        if (depth[i] > 1'000'000'000)
            continue;
        depth[i] = lower_bound(comp.begin(), comp.end(), depth[i]) - comp.begin() + 1;
        cnt[depth[i]]++, K = max(K, depth[i]);
    }

    dp[0][0] = true;
    for (int i = 1; i <= K; i++) {
        for (int j = 0; j + cnt[i] <= N; j++)
            dp[i][j + cnt[i]] |= dp[i - 1][j];
        for (int j = 0; j <= N; j++)
            dp[i][j] |= dp[i - 1][j];
    }

    if (!dp[K][M]) {
        cout << -1 << '\n';
        return 0;
    }

    for (int i = K; i >= 1; i--) {
        if (dp[i - 1][M])
            continue;
        M -= cnt[i], chk[i] ^= 1, chk[i - 1] ^= 1;
    }

    for (int i = 0; i < K; i++)
        if (chk[i + 1])
            ans.push_back(comp[i]);

    cout << ans.size() << '\n';
    for (int i : ans)
        cout << i << ' ';
    cout << '\n';

    return 0;
}