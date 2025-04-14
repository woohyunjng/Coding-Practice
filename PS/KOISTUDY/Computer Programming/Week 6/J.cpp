#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 5001;

vector<int> adj[MAX];
int parent[MAX];
bool vst[MAX];

void dfs(int node) {
    for (int i : adj[node]) {
        if (vst[i])
            continue;
        vst[i] = true, parent[i] = node, dfs(i);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int P, NS, T, X, Y, Z;
    vector<int> ans;

    cin >> P >> NS >> T;

    while (NS--) {
        cin >> X >> Y >> Z;
        adj[X].push_back(Y), adj[Y].push_back(X);
        adj[X].push_back(Z), adj[Z].push_back(X);
        adj[Y].push_back(Z), adj[Z].push_back(Y);
    }

    vst[T] = true, dfs(T);

    T = 1;
    while (T != 0)
        ans.push_back(T), T = parent[T];

    cout << ans.size() << '\n';
    for (int i : ans)
        cout << i << '\n';

    return 0;
}