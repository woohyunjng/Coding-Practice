#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;

vector<int> adj[MAX];
int ans[MAX], K;
bool vst[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, R, U, V;
    queue<int> q;

    cin >> N >> M >> R;
    while (M--) {
        cin >> U >> V;
        adj[U].push_back(V), adj[V].push_back(U);
    }

    for (int i = 1; i <= N; i++)
        sort(adj[i].rbegin(), adj[i].rend());

    q.push(R), vst[R] = true;
    while (!q.empty()) {
        V = q.front(), q.pop(), ans[V] = ++K;
        for (int i : adj[V]) {
            if (!vst[i])
                q.push(i), vst[i] = true;
        }
    }

    for (int i = 1; i <= N; i++)
        cout << ans[i] << '\n';

    return 0;
}