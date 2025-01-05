#include <bits/stdc++.h>
#define int long long

#define MAX 300100
using namespace std;

vector<int> adj[MAX];
int vst[MAX], num = 0, cut[MAX];

int dfs(int node, bool root) {
    int res = ++num, X = 0, Y;
    vst[node] = res;

    for (int i : adj[node]) {
        if (!vst[i]) {
            X++, Y = dfs(i, false);
            if (!root && Y >= vst[node])
                cut[node]++;
            res = min(res, Y);
        } else
            res = min(res, vst[i]);
    }

    if (root)
        cut[node] = X - 1;
    if (cut[node])
        cut[node]++;

    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, U, V, ans = 0;
    cin >> N >> M;

    for (int i = 1; i <= M; i++) {
        cin >> U >> V;
        adj[U].push_back(V), adj[V].push_back(U);
    }

    dfs(1, true);

    for (int i = 1; i <= N; i++) {
        if (cut[i] && (M - adj[i].size() == N - 1 - cut[i]))
            ans += i;
        if (!cut[i] && (M - adj[i].size() == N - 2))
            ans += i;
    }
    cout << ans << '\n';

    return 0;
}