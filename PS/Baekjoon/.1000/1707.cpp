#include <bits/stdc++.h>
using namespace std;

const int MAX = 20001;

vector<int> adj[MAX];
int C[MAX];
bool vst[MAX], ans;

void dfs(int node) {
    vst[node] = true;
    for (int i : adj[node]) {
        if (vst[i])
            ans &= C[i] != C[node];
        else
            C[i] = C[node] ^ 1, dfs(i);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, M, U, V;

    cin >> T;
    while (T--) {
        cin >> N >> M, ans = true;
        while (M--) {
            cin >> U >> V;
            adj[U].push_back(V), adj[V].push_back(U);
        }

        for (int i = 1; i <= N; i++)
            if (!vst[i])
                dfs(i);

        cout << (ans ? "YES" : "NO") << '\n';

        for (int i = 1; i <= N; i++)
            adj[i].clear(), C[i] = 0, vst[i] = false;
    }

    return 0;
}