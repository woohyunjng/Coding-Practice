#include <bits/stdc++.h>
using namespace std;

const int MAX = 101;

vector<int> adj[MAX];
int assign[MAX];
bool vst[MAX];

bool dfs(int node) {
    for (int i : adj[node]) {
        if (vst[i])
            continue;
        vst[i] = true;
        if (assign[i] == 0 || dfs(assign[i])) {
            assign[i] = node;
            return true;
        }
    }
    return false;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, U, V, ans = 0;

    cin >> N >> M;
    while (M--) {
        cin >> U >> V;
        adj[U].push_back(V);
    }

    for (int i = 1; i <= N; i++) {
        fill(vst + 1, vst + N + 1, false);
        if (dfs(i))
            ans++;
    }

    cout << ans << '\n';

    return 0;
}