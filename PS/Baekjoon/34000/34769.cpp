#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 200001;

vector<int> adj[MAX];
int D[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, U, V, ans;

    cin >> N, ans = (N - 1) << 1;
    for (int i = 1; i < N; i++) {
        cin >> U >> V;
        adj[U].push_back(V), adj[V].push_back(U);
    }

    for (int i = 1; i <= N; i++)
        for (int j : adj[i])
            D[i] += (int)adj[j].size() - 1;

    for (int i = 1; i <= N; i++) {
        U = V = 0;
        for (int j : adj[i])
            if (adj[j].size() > 1)
                U++, V = j;

        if (U == 1)
            ans += (int)adj[V].size() - 1;
        if (D[i] == 1) {
            for (int j : adj[i])
                if (adj[j].size() == 2) {
                    for (int k : adj[j])
                        if (k != i)
                            V = k;
                }
            ans += D[V] - 1;
        }
    }

    cout << ans << '\n';

    return 0;
}