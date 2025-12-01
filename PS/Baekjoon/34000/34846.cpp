#include <bits/stdc++.h>
using namespace std;

const int MAX = 200001;

int S[MAX], C[MAX];
vector<int> adj[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, Q, U, V;

    cin >> N >> M >> Q;
    while (M--) {
        cin >> U >> V;
        adj[U].push_back(V), adj[V].push_back(U);
    }

    while (Q--) {
        cin >> U >> V;
        if (U == 1) {
            if (++C[V] == 1)
                for (int i : adj[V])
                    S[i]++;
        } else
            cout << S[V] << '\n';
    }

    return 0;
}