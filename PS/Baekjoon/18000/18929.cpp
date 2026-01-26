#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000001;

int C[MAX];
vector<int> adj[MAX];
bool vst[MAX];

void dfs(int node) {
    vst[node] = true;
    for (int i : adj[node]) {
        if (vst[i])
            continue;
        C[i] = C[node] ^ 1, dfs(i);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, U, V;

    cin >> N;
    for (int i = 1; i <= (N << 1); i += 2)
        adj[i].push_back(i + 1), adj[i + 1].push_back(i);
    for (int i = 1; i <= N; i++) {
        cin >> U >> V;
        adj[U].push_back(V), adj[V].push_back(U);
    }

    for (int i = 1; i <= (N << 1); i++)
        if (!vst[i])
            dfs(i);

    for (int i = 1; i <= (N << 1); i++)
        cout << (C[i] ? 'X' : 'Y');
    cout << '\n';

    return 0;
}