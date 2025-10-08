#include <bits/stdc++.h>
using namespace std;

const int MAX = 300001;

int U[MAX], V[MAX];
vector<int> adj[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, ans = 0;

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> U[i] >> V[i], U[i]--, V[i]--;
        adj[U[i]].push_back(V[i]), adj[V[i]].push_back(U[i]);
    }

    for (int i = 0; i < N; i++)
        sort(adj[i].begin(), adj[i].end());

    for (int i = 0; i < M; i++) {
        if (adj[U[i]].size() > adj[V[i]].size())
            swap(U[i], V[i]);
        for (int j : adj[U[i]])
            if (binary_search(adj[V[i]].begin(), adj[V[i]].end(), j))
                ans++;
    }

    cout << ans / 3 << '\n';

    return 0;
}