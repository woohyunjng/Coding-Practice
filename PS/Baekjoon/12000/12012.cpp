#include <bits/stdc++.h>
using namespace std;

const int MAX = 200001;

vector<int> adj[MAX];

int V[MAX], parent[MAX];
bool ans[MAX], chk[MAX];

int find(int X) { return X == parent[X] ? X : parent[X] = find(parent[X]); }
void uni(int X, int Y) {
    X = find(X), Y = find(Y);
    parent[max(X, Y)] = min(X, Y);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X, Y, C = 0;

    cin >> N >> M;
    while (M--) {
        cin >> X >> Y;
        adj[X].push_back(Y), adj[Y].push_back(X);
    }

    for (int i = 1; i <= N; i++)
        cin >> V[i], chk[i] = false, parent[i] = i;

    for (int i = N; i >= 1; i--) {
        chk[V[i]] = true, C++;
        for (int j : adj[V[i]]) {
            if (!chk[j] || find(j) == find(V[i]))
                continue;
            uni(V[i], j), C--;
        }
        ans[i] = C == 1;
    }

    for (int i = 1; i <= N; i++)
        cout << (ans[i] ? "YES" : "NO") << '\n';

    return 0;
}