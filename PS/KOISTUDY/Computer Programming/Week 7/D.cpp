#include <bits/stdc++.h>
using namespace std;

const int MAX = 2001;

vector<int> adj[MAX];
bool vst[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X, Y;
    queue<int> q;

    cin >> N >> M;
    while (M--) {
        cin >> X >> Y;
        adj[X].push_back(Y), adj[Y].push_back(X);
    }

    vst[1] = true, q.push(1);
    while (!q.empty()) {
        X = q.front(), q.pop();
        cout << X << ' ';

        for (int i : adj[X])
            if (!vst[i])
                vst[i] = true, q.push(i);
    }
    cout << '\n';

    return 0;
}