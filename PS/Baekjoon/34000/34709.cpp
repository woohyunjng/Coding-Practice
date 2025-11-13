#include <bits/stdc++.h>
using namespace std;

const int MAX = 500001;

vector<int> adj[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, U, V, ans = 0;

    cin >> N;
    for (int i = 1; i < N; i++) {
        cin >> U >> V;
        adj[U].push_back(V), adj[V].push_back(U);
    }

    for (int i = 1; i <= N; i++)
        ans += max(0, (int)adj[i].size() - 2);

    cout << ans << '\n';

    return 0;
}